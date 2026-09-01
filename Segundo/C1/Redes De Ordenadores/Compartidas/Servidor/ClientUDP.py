import socket
import os
# Welcome
os.system("clear")
print ('***************')
print ('* Cliente UDP *')
print ('***************')

# user input
host=input('Enter Server IP: ')
port=int(input('Enter Server UDP Port: '))
name = input('enter your username : ')
bytesToSend1 = str.encode(name)
password = input('enter your password : ')
bytesToSend2 = str.encode(password)

serverAddrPort = (host, port)
bufferSize = 1024

# connecting to hosts
UDPClientSocket = socket.socket(family = socket.AF_INET, type = socket.SOCK_DGRAM) 

# sending username by encoding it
UDPClientSocket.sendto(bytesToSend1, serverAddrPort) 
# sending password by encoding it
UDPClientSocket.sendto(bytesToSend2, serverAddrPort) 

# receiving status from server 
msgFromServer = UDPClientSocket.recvfrom(bufferSize) 
msg = "Message from Server {}".format(msgFromServer[0].decode()) 
print(msg)
