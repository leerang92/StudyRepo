using UnityEngine;

public class GameGUI : MonoBehaviour
{
    public GameObject clientPlayer;
    public GameObject serverPlayer;

    public static GameGUI instance;

    void Awake()
    {
        instance = this;
    }

    private void OnGUI()
    {
        if (Network.peerType == NetworkPeerType.Disconnected)
        {
            var Address = "127.0.0.1";
            var Port = 9000;

            Address = GUI.TextArea(new Rect(Screen.width / 2 - 105, Screen.height / 2 - 50, 100, 20), Address);
            Port = int.Parse(GUI.TextArea(new Rect(Screen.width / 2 - 105, Screen.height / 2 - 20, 100, 20), Port.ToString()));

            if (GUI.Button(new Rect(Screen.width / 2 + 5, Screen.height / 2 - 50, 100, 50), "Join"))
                Network.Connect(Address, Port);
            else if (GUI.Button(new Rect(Screen.width / 2 - 105, Screen.height / 2 + 5, 210, 50), "Create"))
                Network.InitializeServer(2, 9000, false);
        }

    }

    void OnServerInitialized()
    {
        Network.Instantiate(serverPlayer, Vector3.up * 3.5f, Quaternion.identity, 0);
    }

    private void OnConnectedToServer()
    {
        Network.Instantiate(clientPlayer, Vector3.down * 3.5f, Quaternion.identity, 0);
    }
}