from sys import argv
script, first = argv
import serial
#import serial.tools.list_ports


#ports = list(serial.tools.list_ports.comports())
#for p in ports:
#	print(p)
	
	
if first != "get":
	data1 = "attn:" + first
else:
	data1 = first
ser = serial.Serial('/dev/ttyUSB0', 115200)
ser.write(data1.encode())
response = ser.readline()
decoded_response = response.decode('utf-8')
ser.close()
print(decoded_response)