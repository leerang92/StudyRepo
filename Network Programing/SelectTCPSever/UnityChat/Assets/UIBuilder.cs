using UnityEngine;

using System;
using System.Collections;
using System.IO;
using System.Net;
using System.Net.Sockets;

[Serializable]
public class UserInfo
{
    public string NickName = "Guest";
    public string Message = string.Empty;
}

public class UIBuilder : MonoBehaviour
{
    public string Address = "127.0.0.1";
    public int Port = 9000;

    ArrayList ChatLog = new ArrayList();
    TcpClient Client = new TcpClient();
    NetworkStream Reader = null;
    StreamWriter Writer = null;
    UserInfo Info = new UserInfo();
    Vector2 Scroll = Vector2.zero;

    void Start()
    {
        StartCoroutine("Receive");
    }

    void OnGUI()
    {
        if (Client.Connected == false)
        {
            GUILayout.Window(0, new Rect(Screen.width / 2 - 200, Screen.height / 2 - 200, 400, 400), Login, "Login");
        }
        else
        {
            GUILayout.Window(0, new Rect(Screen.width / 2 - 200, Screen.height / 2 - 200, 400, 400), ChattingRoom, "Chatting Room");
        }
    }

    void Login(int Arg)
    {
        // IP Address Start
        GUILayout.Label("IP Address");
        Address = GUILayout.TextField(Address);

        // Port Start
        GUILayout.Label("Port");
        Port = int.Parse(GUILayout.TextField(Port.ToString()));

        // Nick Name Start
        GUILayout.Label("Nick Name");
        Info.NickName = GUILayout.TextField(Info.NickName);

        // Connect Button Start
        GUILayout.BeginArea(new Rect(5, 375, 390, 20));
        if (GUILayout.Button("Connect"))
        {
            try
            {
                Client.Connect(IPAddress.Parse(Address), Port);

                if (Client.Connected)
                {
                    ChatLog.Add("*** Welcome ***");

                    Reader = Client.GetStream();
                    Writer = new StreamWriter(Client.GetStream());

                    Writer.AutoFlush = true;
                }
            }
            catch
            {
                Debug.Log("Connection Error");
            }
        }
        GUILayout.EndArea();
    }

    void ChattingRoom(int Arg)
    {
        #region
        // Window 사이즈 줄어듦 방지용
        GUILayout.Label("");
        #endregion

        // Chat Log Start
        GUILayout.BeginArea(new Rect(5, 25, 390, 300));
        Scroll = GUILayout.BeginScrollView((Scroll += Vector2.up));
        foreach (string Log in ChatLog)
        {
            GUILayout.Label(Log);
        }
        GUILayout.EndScrollView();
        GUILayout.EndArea();

        // Message Text Area Start
        GUILayout.BeginArea(new Rect(5, 350, 390, 20));
        Info.Message = GUILayout.TextArea(Info.Message, 255);
        GUILayout.EndArea();

        // Send Button Start
        GUILayout.BeginArea(new Rect(5, 375, 190, 20));
        if (GUILayout.Button("Send") && Info.Message != string.Empty)
        {
            try
            {
                Writer.WriteLine(Info.NickName + " : " + Info.Message);

                Info.Message = string.Empty;
            }
            catch
            {
                Debug.Log("Send Error");
            }
        }
        GUILayout.EndArea();

        // Disconnect Button Start
        GUILayout.BeginArea(new Rect(205, 375, 190, 20));
        if (GUILayout.Button("Disconnect"))
        {
            Client.Client.Shutdown(SocketShutdown.Both);
            Client.Client.Close();
            Client.Close();

            Client = new TcpClient();
        }
        GUILayout.EndArea();
    }

    IEnumerator Receive()
    {
        while (!Client.Connected || !Reader.CanRead)
            yield return null;

        var Data = new byte[64];

        while (true)
        {
            if (Reader.DataAvailable)
            {
                Reader.Read(Data, 0, 64);

                //var message = System.Text.Encoding.ASCII.GetString(Data, 0, 64) + "\0";
                var message = string.Empty;

                for (int i = 0; i < Data.Length && Data[i] >= 32 && Data[i] <= 126; i++)
                {
                    message += (char)Data[i];
                    Debug.Log(Data[i]);
                }

                message = message.Trim();

                if (message != string.Empty && message != null)
                {
                    Debug.Log("<" + message + ">");
                    ChatLog.Add(message);
                }
            }

            yield return null;
        }
    }
}