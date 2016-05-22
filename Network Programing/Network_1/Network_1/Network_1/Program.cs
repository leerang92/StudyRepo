using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace Network_1
{
    class IPAddressExample
    {
        static void PrintHostInfo(String host)
        {
            try
            {
                IPHostEntry hostInfo;
                hostInfo = Dns.GetHostEntry(host);
                Console.WriteLine("\t Canonical Name: " + hostInfo.HostName);

                Console.Write("\t IP Addresses:  ");
                foreach (IPAddress ipaddr in hostInfo.AddressList)
                {
                    Console.Write(ipaddr.ToString() + " ");
                }
                Console.WriteLine();
                Console.Write("\tAliases:    ");
                foreach (String alias in hostInfo.Aliases)
                {
                    Console.Write(alias + " ");
                }
                Console.WriteLine("\n");
            }
            catch (Exception)
            {
                Console.WriteLine("\tUnable to resolve host: " + host + "\n");
            }
        }
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Local Host:");
                String localHostName = Dns.GetHostName();
                Console.WriteLine("\tHost Name:    " + localHostName);
                PrintHostInfo(localHostName);
            }
            catch (Exception)
            {
                Console.WriteLine("Unable to resolve local host\n");
            }
            foreach (String arg in args)
            {
                Console.WriteLine(arg + ":");
                PrintHostInfo(arg);
            }
        }
    }
}
