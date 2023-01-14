using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraFollow : MonoBehaviour
{
    public Transform player;
    private Vector3 offset;
    void Start()
    {
        offset = transform.position - player.position;
    }
    void Update()
    {
        transform.position = new Vector3(transform.position.x, transform.position.y, offset.z + player.position.z);
    }
}
