using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Loader : MonoBehaviour
{
    public string LevelName;

    public void Load()
    {
        SceneManager.LoadScene(LevelName);
        Time.timeScale = 1;
    }
    public void Quit()
    {
        Application.Quit();
    }
}
