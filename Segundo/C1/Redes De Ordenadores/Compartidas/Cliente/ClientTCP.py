import socket
import os

os.system("clear")
print ('***************')
print ('* Cliente TCP *')
print ('***************')

s = socket.socket()
host = input('Enter Server IP: ')
port = int(input('Enter Server TCP Port: '))

# connect to host
s.connect((host, port))

# recv message and decode here 1024 is buffer size.
print (s.recv(1024).decode())
s.close()
