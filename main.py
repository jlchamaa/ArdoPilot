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
    #Check for new mesasages
    new_messages =sio.readline()

    if not new_messages:
        #No new messages...
        continue
    else:

        for message in new_messages:
            # we got a message. Let's extract some details from it
            msg = message
 
            #This is where you change the keys that shall be pressed and listened to.
            #The code below will simulate the key q if "q" is typed into twitch by someone
            #.. the same thing with "w"
            #Change this to make Twitch fit to your game!
            for letter in msg:
                k.key_press(letter)
    