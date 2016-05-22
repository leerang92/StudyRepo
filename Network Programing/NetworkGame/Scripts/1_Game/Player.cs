using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using UnityEngine.Networking;

public class Player : MonoBehaviour
{
    private Vector3 MovePosition;
    private Animator PlayerAnimator;
    public GameObject Object;
    private Renderer Render;

    float hp = 50f;

    private void FixedUpdate()
    {
        transform.position += MovePosition * Time.fixedDeltaTime;
    }

    private void OnPlayerDisconnected(NetworkPlayer Player)
    {
        Network.DestroyPlayerObjects(Player);
    }

    private void OnSerializeNetworkView(BitStream Stream, NetworkMessageInfo Info)
    {
        if (Stream.isReading)
        {
            var Move = Vector3.zero;
            var Position = Vector3.zero;

            Stream.Serialize(ref Move);
            Stream.Serialize(ref Position);

            MovePosition = Move;
            transform.position = Position;
        }
        else
        {
            var Move = MovePosition;
            var Position = transform.position;

            Stream.Serialize(ref Move);
            Stream.Serialize(ref Position);
        }
    }

    private void Update()
    {
        if (!GetComponent<NetworkView>().isMine)
            return;

        if (Timer.instance.bOver)
            return;

        if (Input.GetKey(KeyCode.LeftArrow))
            MovePosition = Vector3.left;
        else if (Input.GetKey(KeyCode.RightArrow))
            MovePosition = Vector3.right;
        else
            MovePosition = Vector3.zero;
    }

    private void Start()
    {
        PlayerAnimator = GetComponent<Animator>();
        Render = GetComponentInChildren<Renderer>();
    }

    void OnTriggerEnter(Collider coll)
    {
        if(coll.gameObject.name == "METEO(Clone)")
        {
            Destroy(coll.gameObject);
            hp -= 10f;
            StartCoroutine("HItPlayer", 0.2f);

            if(hp <= 0)
            {
                Destroy(this.gameObject);
            }
        }
    }

    IEnumerator HItPlayer(float duration)
    {
        while (duration > 0f)
        {
            duration -= Time.deltaTime;
            Render.enabled = !Render.enabled;
            yield return new WaitForSeconds(0.2f);
        }
        Render.enabled = true;
    }
}
