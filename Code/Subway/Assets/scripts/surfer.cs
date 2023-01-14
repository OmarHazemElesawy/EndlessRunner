using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class surfer : MonoBehaviour
{
    public obstacleManager obstacleManager;
    Rigidbody rb;
    private float speed = 0.09f;
    private int currentLane = 1;
    public TMP_Text health;
    public TMP_Text ability;
    public TMP_Text score;
    public TMP_Text finalScore;
    public int playerHealth = 5;
    public int playerAbility = 10;
    public int playerScore = 0;
    private bool paused = false;
    public GameObject PauseMenu;
    public GameObject GameOverMenu;
    public AudioSource BackgroundMusic;
    public AudioSource WaitingMusic;
    public AudioSource HitSound;
    public AudioSource CollectSound;
    private bool end = false;


    void Start()
    {
        Application.targetFrameRate = 60;
        WaitingMusic.Pause();
        BackgroundMusic.Play();
        rb = GetComponent<Rigidbody>();
        health.text = "Health: " + playerHealth;
        ability.text = "Ability: " + playerAbility;
        score.text = "Score: " + playerScore;
    }

    void Update()
    {

        if (!paused)
        {
            transform.Translate(new Vector3(0, 0, speed));
            if (Input.GetKeyDown("q"))
            {
                if (playerAbility >= 5)
                {
                    playerAbility -= 5;
                    ability.text = "Ability: " + playerAbility;
                    for (int i = 0; i < obstacleManager.createdObstacles.Count; i++)
                        Destroy(obstacleManager.createdObstacles[i]);
                }
            }
            if (Input.GetKeyDown("space"))
            {
                if (transform.position.y < 1 && playerAbility > 0)
                {
                    rb.AddForce(new Vector3(0, 300, 0));
                    playerAbility--;
                    ability.text = "Ability: " + playerAbility;
                }
            }

            if (Input.GetKeyDown("right") || Input.GetKeyDown("d"))
                if ((currentLane == 0 || currentLane == 1) && transform.position.y < 1)
                {
                    currentLane++;
                    this.transform.Translate(new Vector3(2.7f, 0, 0));
                }
            if (Input.GetKeyDown("left") || Input.GetKeyDown("a"))
                if ((currentLane == 1 || currentLane == 2) && transform.position.y < 1)
                {
                    currentLane--;
                    this.transform.Translate(new Vector3(-2.7f, 0, 0));
                }
        }
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if (paused && !end)
            {
                BackgroundMusic.Play();
                WaitingMusic.Pause();
                ResumeGame();
            }
            else if (!paused && !end)
            {
                BackgroundMusic.Pause();
                WaitingMusic.Play();
                PauseGame();
            }
        }

    }
    private void OnTriggerEnter(Collider other)
    {
        int addedHealth = 0;
        int addedScore = 0;
        if (other.gameObject.CompareTag("Ability"))
        {
            if (playerAbility < 10) 
                playerAbility++;
            CollectSound.Play();
            ability.text = "Ability: " + playerAbility;
            Destroy(other.gameObject);
        }

        if (other.gameObject.CompareTag("Health"))
        {
            if (playerHealth < 5)
                playerHealth++;
            CollectSound.Play();
            Destroy(other.gameObject);
        }

        if (other.gameObject.CompareTag("Obstacle1"))
        {
            addedHealth -= 3;
            addedScore -= 3;
            HitSound.Play();
            Destroy(other.gameObject);
        }

        if (other.gameObject.CompareTag("Obstacle2"))
        {
            addedHealth -= 2;
            addedScore -= 2;
            HitSound.Play();
            Destroy(other.gameObject);
        }

        if (other.gameObject.CompareTag("Obstacle3"))
        {
            addedHealth -= 1;
            addedScore -= 1;
            HitSound.Play();
            Destroy(other.gameObject);
        }

        if (other.gameObject.CompareTag("Border1"))
        {
            addedScore += 3;
        }

        if (other.gameObject.CompareTag("Border2"))
        {
            addedScore += 2;
        }

        if (other.gameObject.CompareTag("Border3"))
        {
            addedScore += 1;
        }

        playerScore += addedScore;
        score.text = "Score: " + playerScore;

        playerHealth += addedHealth;
        if(playerHealth <= 0)
        {
            playerHealth = 0;
            health.text = "Health: " + playerHealth;
            playerScore -= addedScore;
            score.text = "Score: " + playerScore;
            EndGame();
        }
        else
        {
            health.text = "Health: " + playerHealth;
        }

    }
    public void PauseGame()
    {

        PauseMenu.SetActive(true);
        Time.timeScale = 0;
        paused = true;
    }

   public void ResumeGame()
    {
        PauseMenu.SetActive(false);
        Time.timeScale = 1;
        paused = false;
    }

    void EndGame()
    {
        end = true;
        BackgroundMusic.Pause();
        WaitingMusic.Play();
        Time.timeScale = 0;
        paused = true;
        finalScore.text = "Final Score: " + playerScore;
        GameOverMenu.SetActive(true);

    }

}