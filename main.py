#Define the imports
from time import sleep
from keypresser import Keypresser
k = Keypresser()
 

#The main loop
while True:
    #Check for new mesasages
    new_messages ='p' 

    if not new_messages:
        #No new messages...
        continue
    else:

        for message in new_messages:
            # we got a message. Let's extract some details from it
            msg = message['message']
            username = message['username'].lower()
            print(username + ": " + msg);
 
            #This is where you change the keys that shall be pressed and listened to.
            #The code below will simulate the key q if "q" is typed into twitch by someone
            #.. the same thing with "w"
            #Change this to make Twitch fit to your game!
            for letter in msg:
                k.key_press(letter)
                sleep(.01)
    
            
            