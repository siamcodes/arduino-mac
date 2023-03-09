# updclient.py

import socket

msgFromClient = "Hello, UDP Server"

bytesToSend = str.encode(msgFromClient)
serverAddressPort = ("192.168.43.16", 20002)
bufferSize = 1024


UDPClientSock = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)


UDPClientSock.sendto(bytesToSend, serverAddressPort)
 
msgFromServer = UDPClientSock.recvfrom(bufferSize)

msg = "Message from Server {}".format(msgFromServer[0])
print(msg)
