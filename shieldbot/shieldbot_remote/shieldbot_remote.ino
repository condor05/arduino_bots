//Make sure the dip switches are turned ON, and none of your shields are using pins A0,A1,A2,A3 or D4

#include <Shieldbot.h>	//includes the Shieldbot Library
#include <SoftwareSerial.h>
#include "Syn6288.h"
Syn6288 syn;
//uint8_t text1[]={0xB3,0xC9,0xB6,0xBC,0xBC,0xAB,0xC8,0xA4,0xBF,0xC6,0xBC,0xBC,0xD3,0xD0,0xCF,0xDE,0xB9,0xAB,0xCB,0xBE};   //成都极趣科技有限公司
//uint8_t text2[]={0x77,0x77,0x77,0x2E,0x64,0x66,0x72,0x6F,0x62,0x6F,0x74,0x2E,0x63,0x6F,0x6D,0x2E,0x63,0x6E};   //www.dfrobot.com.cn
uint8_t text3[]={0xCE,0xD2,0xCA,0xC7,0xD0,0xA1,0xB0,0xB2};   //0,1,2,3,4,5,6,7,8,9
//uint8_t text3[]={0xCE, 0xD2, 0xCA, 0xC7. 0xD0, 0xA1, 0xB0, 0xB2};

Shieldbot shieldbot = Shieldbot();	//decares a Shieldbot object
int S1,S2,S3,S4,S5;	//values to store state of sensors
int comtemp;
SoftwareSerial softSerial(2, 3);

void setup(){
  Serial.begin(9600);
  softSerial.begin(9600);//Begin serial comm for debugging
  shieldbot.setMaxSpeed(200,200);//255 is max, if one motor is faster than another, adjust values 

   syn.play(text3,sizeof(text3),3);//合成text3，背景音乐3
}

void loop(){
  //Read all the sensors 
  S1 = shieldbot.readS1();
  S2 = shieldbot.readS2();
  S3 = shieldbot.readS3();
  S4 = shieldbot.readS4();
  S5 = shieldbot.readS5();
  
  if (softSerial.available()){
    comtemp = softSerial.read();
    switch(comtemp){
     case 'e':
        shieldbot.drive(127,0);
        break;
      case 'q':
        shieldbot.drive(0,127);
        break;
      case 'w':
        //syn.play(text3,sizeof(text3),3);//合成text3，背景音乐3
        shieldbot.forward();
        break;
      case 's':
       // syn.play(text3,sizeof(text3),3);//合成text3，背景音乐3
        shieldbot.backward();
        break;
      case 'd':
        shieldbot.drive(127, -128);
        break;
       case 'a':
        shieldbot.drive(-128, 127);
        break;
       case 't':
        shieldbot.stop();
        break;
  
    }
  }
}
