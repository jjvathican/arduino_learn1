/*
### Get GPS data
1. This example is used to test SIM808 GPS/GPRS/GSM Shield's reading GPS data.
2. Open the SIM808_GetGPS example or copy these code to your project
3. Download and dial the function switch to Arduino
4. open serial helper
4. Place it outside, waiting for a few minutes and then it will send GPS data to serial

create on 2016/09/23, version: 1.0
by jason

*/
#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>
char receivedChar;
boolean newData = false;

//#define PIN_TX    10
//#define PIN_RX    11
//SoftwareSerial mySerial(PIN_TX,PIN_RX);
//DFRobot_SIM808 sim808(&mySerial);//Connect RX,TX,PWR,

DFRobot_SIM808 sim808(&Serial);

void setup() {
 // mySerial.begin(9600);
  Serial.begin(9600);

  //******** Initialize sim808 module *************
  while(!sim808.init()) { 
      delay(1000);
      Serial.print("Sim808 init error\r\n");
  }

  //************* Turn on the GPS power************
  if( sim808.attachGPS())
      Serial.println("Open the GPS power success");
  else 
      Serial.println("Open the GPS power failure");
  
}

void loop() {
   //************** Get GPS data *******************
   recvOneChar();
   showNewData();
   //delay(200);

}



void recvOneChar() {
 if (Serial.available() > 0) {
 receivedChar = Serial.read();
 newData = true;
 }
}

void showNewData() {
 if (newData == true) { 
 Serial.print(receivedChar);
 newData = false;
 }
}




