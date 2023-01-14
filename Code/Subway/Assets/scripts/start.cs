using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class start : MonoBehaviour
{
    public AudioSource WaitingMusic;
    private bool muted = false;

    void Start()
    {
        WaitingMusic.Play();

    }
    public void MuteUnmute()
    {
        if (muted)
        {
            AudioListener.volume = 1;
            muted = false;
        }
        else
        {
            AudioListener.volume = 0;
            muted = true;
        }
    }
}