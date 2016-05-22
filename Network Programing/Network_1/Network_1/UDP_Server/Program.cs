using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets

namespace UDP_Server
{
    class UdpEchoServer{
        static void Main(string[] args){
            if(args.Length > 1){
                throw new ArgumentException("Parameters: <Port>");
            }
            int servPort = (args.Length == 1) ? Int32.Parse(args[0]):7;

            UdpClient client = null;

            try{
                client = new UdpClient(servPort);
            }catch(SocketException se){
                Console.WriteLine(se.ErrorCode + ": " + se.Message);
                Environment.Exit(se.ErrorCode);
            }

            IPEndPoint remoteIPEndPoint = new IPEndPoint(IPAddress.Any, 0);
            for(;;){
                try{
                    byte[] byteBuffer = client.Receive(ref remoteIPEndPoint);
                    Console.Write("Handling client at " + remoteIPEndPoint + "-");

                    client.Send(byteBuffer, byteBuffer.Length, remoteIPEndPoint);
                    Console.WriteLine("echoed {0} bytes.", byteBuffer.Length);
                }catch(SocketException se){
                    Console.WriteLine(se.ErrorCode + ": " + se.Message);
                }
            }
        }
    }

}
