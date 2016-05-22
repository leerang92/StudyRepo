using UnityEngine;
using System.Collections;

public class serverPlayerCtrl : MonoBehaviour {

    public GameObject meteo;

    private Vector3 MovePosition;
    NetworkView _netWorkView;

    bool bFire = true;

    void Awake()
    {
        _netWorkView = GetComponent<NetworkView>();
    }

    private void Update()
    {

        if (_netWorkView.isMine)
        {
            if (Timer.instance.bOver)
                return;

            if (Input.GetKey(KeyCode.LeftArrow))
                MovePosition = Vector3.left;
            else if (Input.GetKey(KeyCode.RightArrow))
                MovePosition = Vector3.right;
            else
                MovePosition = Vector3.zero;

            transform.position += MovePosition * Time.deltaTime;

            if (Input.GetButtonDown("Jump") && bFire)
            {
                StartCoroutine("Fire");
                _netWorkView.RPC("Fire", RPCMode.Others);
            }
        }
    }

    void OnSerializeNetworkView(BitStream Stream, NetworkMessageInfo Info)
    {
        if (Stream.isReading)
        {
            Vector3 Move = Vector3.zero;
            Vector3 Position = Vector3.zero;

            Stream.Serialize(ref Move);
            Stream.Serialize(ref Position);

            MovePosition = Move;
            transform.position = Position;
        }
        else
        {
            Vector3 Move = MovePosition;
            Vector3 Position = transform.position;

            Stream.Serialize(ref Move);
            Stream.Serialize(ref Position);
        }
    }
    
    [RPC]
    IEnumerator Fire()
    {
        bFire = false;
        Instantiate(meteo, transform.position, Quaternion.identity);

        yield return new WaitForSeconds(2.0f);
        bFire = true;
    }
}