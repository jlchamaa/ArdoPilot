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



int wakeArray[10]={1,1,1,1,1,1,1,1,1,1};
boolean paused=false;
int vol=9;

void loop()
{
	if(Serial.available() > 0 )
	{
		int newin=Serial.read() -'0'; // 
		digitalWrite(13,HIGH);

		for(int k=0;k<9;k++){ // The for loop index shift
			wakeArray[k]=wakeArray[k+1];
		}	
		wakeArray[9] = newin; // add new reading to the array

		
		
		int count=0;
		for(int k=0;k<10;k++){ // The for loop index shift
			if(wakeArray[k]==1){
				count++;
			}
		}
		
		int intermediate=255*((count-3)*(count-3))/36;
	 
		switch(count){

			case 0:
				apply(0,0,10);
				break;

			case 1:
				apply(0,0,10);
				if(paused==false){
					Serial.write(" ");
					paused=true;
				}
				break;
			case 2:
				apply(0,0,0);
				if(paused==true){
					Serial.write(" ");
					paused=false;
				}
				vol=2;
				break;
			case 3:
				apply(0,0,0);
				if(vol>3) {Serial.write("-");vol=3;}
				if(vol<3) {Serial.write("u");vol=3;}
				break;

			case 4:
				apply(intermediate,intermediate,intermediate);
				if(vol>4) {Serial.write("-");vol=4;}
				if(vol<4) {Serial.write("u");vol=4;}
				break;
			case 5:
				apply(intermediate,intermediate,intermediate);
				if(vol>5) {Serial.write("-");vol=5;}
				if(vol<5) {Serial.write("u");vol=5;}
				break;
			case 6:
				apply(intermediate,intermediate,intermediate);
				if(vol>6) {Serial.write("-");vol=6;}
				if(vol<6) {Serial.write("u");vol=6;}
				break;
			case 7:
				apply(intermediate,intermediate,intermediate);
				if(vol>7) {Serial.write("-");vol=7;}
				if(vol<7) {Serial.write("u");vol=7;}
				break;
			case 8:
				apply(intermediate,intermediate,intermediate);
				if(vol>8) {Serial.write("-");vol=8;}
				if(vol<8) {Serial.write("u");vol=8;}
				break;
			case 9:
				apply(intermediate,intermediate,intermediate);
				vol=9;
				break;
			case 10:
				apply(255,255,255);
				break;
		}


	}
		
}

