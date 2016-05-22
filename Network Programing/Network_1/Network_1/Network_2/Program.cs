using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net.Sockets;

namespace Network_2
{
    class TcpEchoClient
    {
        static void Main(string[] args)
        {
            if ((args.Length < 2) || (args.Length > 3))
            {
                throw new ArgumentException("Parmeters: <Sever> <Word> [<Port>]");
            }

            String server = args[0];

            byte[] bytebuffer = Encoding.ASCII.GetBytes(args[1]);

            int servPort = (args.Length == 3) ? Int32.Parse(args[2]) : 7;

            TcpClient client = null;
            NetworkStream netStream = null;

            try
            {
                client = new TcpClient(server, servPort);

                Console.WriteLine("Connected to sever...", bytebuffer.Length);

                int totalBytesRcvd = 0;
                int bytesRecvd = 0;

                while (totalBytesRcvd < bytebuffer.Length)
                {
                    if ((bytesRecvd = netStream.Read(bytebuffer, totalBytesRcvd,
                        bytebuffer.Length - totalBytesRcvd)) == 0)
                    {
                        Console.WriteLine("Connection closed prematurely.");
                        break;
                    }
                    totalBytesRcvd += bytesRecvd;
                }

                Console.WriteLine("Received{0} bytes from sever: {1}", totalBytesRcvd,
                    Encoding.ASCII.GetString(bytebuffer, 0, totalBytesRcvd));

            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                netStream.Close();
                client.Close();
            }
        }
    }
}
