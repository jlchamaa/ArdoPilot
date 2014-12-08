// Serial read(1)=49
// serial read(0)=48

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);
void apply(int r, int g, int b){
	analogWrite(10,r); 
	analogWrite(11,g);
	analogWrite(9,b);
}
void screenApply(int r, int g, int b){
	analogWrite(3, 255-g);
	analogWrite(5, 255-b);
	analogWrite(6, 255-r);

}

void setup(){
	pinMode(13, OUTPUT);
	Serial.begin(9600);
	apply(0,100,50);
	digitalWrite(13,LOW);
	screenApply(65,200,120);
	lcd.setCursor(0,0);
	lcd.print("THALES ARDUINO");
}



int wakeArray[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

void loop()
{
	if(Serial.available() > 0 )
	{
		int newin=Serial.read() -'0'; // 
		digitalWrite(13,HIGH);

		for(int k=0;k<19;k++){ // The for loop index shift
			wakeArray[k]=wakeArray[k+1];
		}	
		wakeArray[19] = newin; // add new reading to the array

		
		
		int count=0;
		for(int k=0;k<20;k++){ // The for loop index shift
			if(wakeArray[k]==1){
				count++;
			}
		}
	 
			if(count>=17) {
				
				apply(255,255,255);
			}
			else if(count>=10) {
				
					int intermediate=255*((count-10)*(count-10))/49;
					apply(intermediate,intermediate,intermediate);
					Serial.print("-");

			}
			else if(count>=5){

			Serial.print(" ");
			apply(0,0,0);
			}
			else{
				
				apply(0,0,10);
			}
			
		
	}
		
}

