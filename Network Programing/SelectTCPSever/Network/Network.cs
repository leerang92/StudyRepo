using UnityEngine;

using System;
using System.Collections;
using System.ComponentModel;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;

[Serializable]
public class UserInfo
{
    public string NickName;
    public string Message;
}

public class Network : MonoBehaviour
{
    EndPoint ServerAddress = null;
    Socket ServerSocket = null;
    bool Success = true;

    BinaryFormatter Formatter = new BinaryFormatter();
    MemoryStream Stream = new MemoryStream();
    UserInfo Info = new UserInfo();
    byte[] Buffer = new byte[256];

    void Start()
    {
        try
        {
            ServerAddress = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 9000);
            ServerSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            ServerSocket.Connect(ServerAddress);
        }
        catch (SocketException Exception)
        {
            Debug.Log(Exception.Message);

            Success = false;
        }

        StartCoroutine("Client");
        StartCoroutine("Recv");
    }

    IEnumerator Client()
    {
        Info.NickName = "Master";
        Info.Message = "1234567890";
        Formatter.Serialize(Stream, Info);

        while (Success)
        {
            ServerSocket.Send(Stream.ToArray());
            Stream.Flush();
            yield return null;
        }

        Stream.Close();
        ServerSocket.Close();
    }

    IEnumerator Recv()
    {
        while (Success)
        {
            ServerSocket.Receive(Buffer);
            Debug.Log(Buffer.ToString());
            yield return null;
        }
    }
}
