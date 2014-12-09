import serial
import time

ser = serial.Serial("COM10", 9600, timeout=.25)

time.sleep(1)

print ser.name

while(1):
  word = raw_input('> ')

  if(word == "end"):
    break;

  #Sends the text one character at a time
  for x in range(0, len(word)):
    ser.write(word[x])
    time.sleep(.01)
    ret=ser.read()
    print ret

#Closes the connection
ser.close()