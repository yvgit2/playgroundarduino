/*
 
www.DFRobot.com
 
Author: Lauren
Version:0.1
 
*/
 
////////////////Arduino例子程序///////////////////////////////////////
#define  ClockPin  6  // clock in
#define  DataPin   7  //data in  
#define  TestPin   8 //driver pin  set pin low to start deliver data
 
void setup() {
  Serial.begin(9600);   
  pinMode(DataPin,INPUT);
  pinMode(ClockPin,INPUT);
  pinMode(TestPin,OUTPUT);
  digitalWrite(TestPin, HIGH);
  delay(100);
}
 
void data_read(int *p)
{
  int i,j,PinState,tempData;
   
  digitalWrite(TestPin, LOW);
  for(i=0;i<5;i++)
  {
	for(j=0;j<8;j++)
	{
  	do{
    	PinState = digitalRead(ClockPin);
  	}while(PinState);
  	delayMicroseconds(100);
  	PinState = digitalRead(DataPin);
  	if(1 == PinState)
     	tempData = (tempData<<1 & 0xfe)+1;
  	else
     	tempData = (tempData<<1 & 0xfe);
   	do{
    	PinState = digitalRead(ClockPin);
  	}while(PinState != 1);
	}
	*p++ = tempData;
  }
  digitalWrite(TestPin, HIGH);
}
 
void loop()
{
  int data_buf[5] = {0};
  int tempData = 0;
  unsigned long previousMillis;
  unsigned long elapsedMillis;
  while(1)
  {
  previousMillis = millis();
  data_read(data_buf);
  elapsedMillis = millis() - previousMillis;
  tempData = data_buf[1]*256 + data_buf[2];
  float realTemp = (float)tempData/16-273.15;
  Serial.print("Temp[C]=");
  Serial.println(realTemp);
  Serial.println(elapsedMillis);
  Serial.print(" ms \n");  
  delay(500);  
  }
}	


