using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class roadManager : MonoBehaviour
{
    public GameObject MyRoad;
    private float zposition = 0;
    private int startingNumber = 4;
    private List<GameObject> createdRoad = new List<GameObject>();
    public Transform player;
    void Start()
    {
        for(int i = 0; i < startingNumber; i++)
        {
            SpawnRoadTile();
        }
    }

    void Update()
    {
        if(player.position.z - 40 > zposition - (startingNumber * 30))
        {
            SpawnRoadTile();
            DeleteTile();
        }
    }
    void SpawnRoadTile()
    {
        GameObject roadtile = Instantiate(MyRoad, new Vector3(0, 0, zposition), transform.rotation);
        createdRoad.Add(roadtile);
        zposition += 30;
    }
    void DeleteTile()
    {
        Destroy(createdRoad[0]);
        createdRoad.RemoveAt(0);
    }
}
