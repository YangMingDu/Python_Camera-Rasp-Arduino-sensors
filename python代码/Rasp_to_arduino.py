import serial    #import serial module
ser = serial.Serial('/dev/ttyUSB0', 9600,timeout=1);   #open named port at 9600,1s timeot

#try and exceptstructure are exception handler
try:
  while 1:
    ser.write('s');#writ a string to port
    response = ser.readline();#read a string from port
    print(str(response));
except:
  ser.close();