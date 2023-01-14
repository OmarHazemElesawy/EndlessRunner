using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class obstacleManager : MonoBehaviour
{
    public GameObject oneLane;
    public GameObject twoLane;
    public GameObject threeLane;
    public GameObject healthOrb;
    public GameObject abilityOrb;
    public Transform player;

    private float obstacleTimer = 0f;
    private float obstacleSpawnTime = 2f;

    private float[,] obstaclePositions = new float[,] { { -2.6f, 0, 2.6f }, { 0, -2.5f, 0 }, { -0.25f, 0.67f, 0 } };
    private float[] collectiblePositions = new float[] {-2.55f, 0, 2.55f};
    public List<GameObject> createdObstacles = new List<GameObject>();
    private List<List<GameObject>> createdCollectibles = new List<List<GameObject>>();

    private float zposition = 10;
    private float zposition_collectible = 15;


    void Update()
    {
        obstacleTimer += Time.deltaTime;
        if (obstacleTimer > obstacleSpawnTime)
        {
            SpawnObstacle();
            obstacleTimer -= obstacleSpawnTime;
        }
    }

    void SpawnObstacle()
    {
        int randomObstacle = Random.Range(1, 4);
        float xposition;
        float yposition;
        if (randomObstacle == 1)
        {
            xposition = obstaclePositions[0, Random.Range(0, 3)];
            yposition = 2;
            GameObject obstacle = Instantiate(oneLane, new Vector3(xposition, yposition, zposition), transform.rotation);
            createdObstacles.Add(obstacle);
        }
        if (randomObstacle == 2)
        {
            xposition = obstaclePositions[1, Random.Range(0, 2)];
            yposition = 2;
            GameObject obstacle = Instantiate(twoLane, new Vector3(xposition, yposition, zposition), transform.rotation);
            createdObstacles.Add(obstacle);

        }
        if (randomObstacle == 3)
        {
            xposition = obstaclePositions[2, 0];
            yposition = obstaclePositions[2, 1];
            GameObject obstacle = Instantiate(threeLane, new Vector3(xposition, yposition, zposition), transform.rotation);
            createdObstacles.Add(obstacle);

        }
        SpawnCollectible(zposition);
        zposition = player.position.z + 30;
        DeleteObstacle();
    }

    void DeleteObstacle()
    {
        if (createdObstacles.Count > 5)
        {
            Destroy(createdObstacles[0]);
            createdObstacles.RemoveAt(0);
        }
    }


    void SpawnCollectible(float position)
    {
        int chance = Random.Range(1, 4);
        if (chance == 1 ||chance == 2) {
            int randomCount = Random.Range(1, 4);
            int healthCount = Random.Range(1, randomCount + 1);
            int abilityCount = randomCount - healthCount;
            List<int> taken = new List<int>();
            List<GameObject> collectibles = new List<GameObject>();
            for (int i = 0; i < healthCount; i++)
            {
                int randomX = Random.Range(0, 3);
                while (taken.Contains(randomX))
                {
                    randomX = Random.Range(0, 3);
                }
                float xposition = collectiblePositions[randomX];
                taken.Add(randomX);
                GameObject healthCollectible = Instantiate(healthOrb, new Vector3(xposition, 0.8f, position + 3.5f), transform.rotation);
                collectibles.Add(healthCollectible);
            }

            for (int i = 0; i < abilityCount; i++)
            {
                int randomX = Random.Range(0, 3);
                while (taken.Contains(randomX))
                {
                    randomX = Random.Range(0, 3);
                }
                float xposition = collectiblePositions[randomX];
                taken.Add(randomX);
                GameObject abilityCollectible = Instantiate(abilityOrb, new Vector3(xposition, 0.8f, position + 3.5f), transform.rotation);
                collectibles.Add(abilityCollectible);
            }
            createdCollectibles.Add(collectibles);
            zposition_collectible = player.position.z + 35;
            DeleteCollectible();
    
        }
    }

    void DeleteCollectible()
    {
        if (createdCollectibles.Count > 3)
        {
            for(int i = 0; i < createdCollectibles[0].Count; i++)
                Destroy(createdCollectibles[0][i]);
            createdCollectibles.RemoveAt(0);
        }
    }
}