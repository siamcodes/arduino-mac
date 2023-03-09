import socket

localIP     = "0.0.0.0" 

localPort   = 20002
bufferSize  = 1024


# Create a datagram socket
UDPServerSock = socket.socket(family=socket.AF_INET,
                              type=socket.SOCK_DGRAM)


UDPServerSock.bind((localIP, localPort))
print("UDP server is up and listening at", localPort)

# Listen for incoming datagrams
while(True):
    msg, addr = UDPServerSock.recvfrom(bufferSize)


    clientMsg = "Message from Client:{}".format(msg)
    clientIP  = "Client IP Address:{}".format(addr)
    
    print(clientMsg)
    print(clientIP)


    bytesToSend = str.encode(' you sent ')
    UDPServerSock.sendto(bytesToSend+msg, addr)
    
