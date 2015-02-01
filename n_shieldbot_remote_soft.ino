//Make sure the dip switches are turned ON, and none of your shields are using pins A0,A1,A2,A3 or D4

#include <Shieldbot.h>	//includes the Shieldbot Library

Shieldbot shieldbot = Shieldbot();	//decares a Shieldbot object
int S1,S2,S3,S4,S5;	//values to store state of sensors
int comtemp;

void setup(){
  Serial.begin(9600);//Begin serial comm for debugging
  shieldbot.setMaxSpeed(50,50);//255 is max, if one motor is faster than another, adjust values 
}

void loop(){
  //Read all the sensors 
  S1 = shieldbot.readS1();
  S2 = shieldbot.readS2();
  S3 = shieldbot.readS3();
  S4 = shieldbot.readS4();
  S5 = shieldbot.readS5();

  //Print the status of each sensor to the Serial console
  Serial.print("S5: ");
  Serial.print(S5);
  Serial.print(" S4: ");
  Serial.print(S4);
  Serial.print(" S3: ");
  Serial.print(S3);
  Serial.print(" S2: ");
  Serial.print(S2);
  Serial.print(" S1: ");
  Serial.print(S1);
  Serial.println();
 
  if (Serial.available()){
    comtemp = Serial.read();
    switch(comtemp){
     case 'e':
        shieldbot.drive(127,0);
        break;
      case 'q':
        shieldbot.drive(0,127);
        break;
      case 'w':
        shieldbot.forward();
        break;
      case 's':
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

