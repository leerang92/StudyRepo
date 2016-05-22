using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace UDP_Client
{
    class UdpEchoClient
    {
        static void Main(string[] args)
        {
            if ((args.Length < 2) || (args.Length > 3))
            {
                throw new System.ArgumentException("Parameters: <Server> <Word> [<Port>]");
            }

            String server = args[0];

            int servPort = (args.Length == 3) ? Int32.Parse(args[2]) : 7;

            byte[] sendPacket = Encoding.ASCII.GetBytes(args[1]);

            UdpClient client = new UdpClient();

            try
            {
                client.Send(sendPacket, sendPacket.Length, server, servPort);

                Console.WriteLine("Sent {0} bytes to the server...", sendPacket.Length);

                IPEndPoint remoteIPEndPoint = new IPEndPoint(IPAddress.Any, 0);

                byte[] rcvPacket = client.Receive(ref remoteIPEndPoint);

                Console.WriteLine("Received {0} bytes from {1}: {2}",
                    rcvPacket.Length, remoteIPEndPoint, Encoding.ASCII.GetString(rcvPacket, 0, rcvPacket.Length));
            }
            catch (SocketException se)
            {
                Console.WriteLine(se.ErrorCode + ": " + se.Message);
            }
            client.Close();

        }
    }
}
