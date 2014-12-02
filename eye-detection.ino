

void setup()
{
  Serial.begin(9600);
}

int wakeArray[20], count = 0, count2 = 0;
void loop()
{
  if(Serial.available()){
    Serial.print(count+1);// this line for testing: showing how numbers input
    Serial.print("number input:"); //testing
    
    wakeArray[count] = Serial.read();
    Serial.println(wakeArray[count]-'0'); // testing showing the value input
    if(wakeArray[count] ==1)
    {
      count2 ++;
    }
    
    if(count ==19) // when the array is full, we need to make a judgement
    {
      if(count2 >=17) Serial.println("you are awake");  //the levels of sleepiness
      else if(count2 >=13) Serial.println("you are half asleep");
      else Serial.println("you are asleep");
      
      count2 = 0; //reset the two counters
      count = 0;
    }
    count++;
    
  }
 
    
  }

