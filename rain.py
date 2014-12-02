#Define the imports
from time import sleep
import serial
import io
from keypresser import Keypresser
k = Keypresser()
 
#Initialize the Serial
ser=serial.Serial(8,9600,timeout=1)
sio = io.TextIOWrapper(io.BufferedRWPair(ser,ser))

#The main loop
while True:
    sleep(5)
    ser.write('b')
    