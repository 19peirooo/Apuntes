# importing required modules
import socket
import datetime
import os

# welcome
os.system ("clear")
print ('****************')
print ('* Servidor TCP *')
print ('****************')

# initializing socket
s = socket.socket()
host = input ('Enter Server IP: ') # "192.168.1.88"
port = int(input ('Enter Server TCP Port: ')) # 60000

# binding port and host
s.bind((host, port))

# waiting for a client to connect
s.listen(5)

while True:
	# accept connection
	c, addr = s.accept()
	print ('got connection from addr', addr)
	date = datetime.datetime.now()
	d = str(date)

	# sending data type should be string and encode before sending
	c.send(d.encode())
	c.close()
