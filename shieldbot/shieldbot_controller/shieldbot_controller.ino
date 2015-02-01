//Make sure the dip switches are turned ON, and none of your shields are using pins A0,A1,A2,A3 or D4

#include <Shieldbot.h>	//includes the Shieldbot Library

#define up_button   8
#define down_button A1
#define left_button 9
#define right_button    12
 
#define stick_button    A0
#define level_stick A3
#define vertical_stick  A2


Shieldbot shieldbot = Shieldbot();	//decares a Shieldbot object

int left_state;
int right_state;
int up_state;
int down_state;
int stick_state;
int level_value;
int vertical_value;

int comtemp;
int oldComtemp;


void setup(){
    pinMode (left_button, INPUT);
    pinMode (right_button, INPUT);
    pinMode (up_button, INPUT);
    pinMode (down_button, INPUT);
 
    pinMode (stick_button  , INPUT);
    pinMode (level_stick   , INPUT);
    pinMode (vertical_stick, INPUT);
    
    Serial.begin(9600);//Begin serial comm for debugging
    shieldbot.setMaxSpeed(50,50);//255 is max, if one motor is faster than another, adjust values 
}

void loop(){
   int left_state = digitalRead (left_button);
    int right_state = digitalRead (right_button);
    int up_state = digitalRead (up_button);
    int down_state = digitalRead (down_button);
 
    int stick_state = digitalRead (stick_button);
 
    int level_value = analogRead (level_stick);
    int vertical_value = analogRead (vertical_stick);
 if (vertical_value < 230){ //stick upwards
     if (level_value < 230) { //stick towards right
       comtemp = 'e'; //turn right
     }
     else if (level_value > 800) { //stick towards left
       comtemp = 'q';  //turn left
     }
     else 
     {
       comtemp = 'w';  //go forward
     }
 }
 else if (vertical_value > 800){ //stick downwards
   comtemp = 's'; //go backward
 }
 else { // stick in the middle
   if (level_value < 230) { //stick towards right
     comtemp = 'd'; //turn right at the spot
   }
   else if (level_value > 800){ //stick towards left
     comtemp = 'a'; //turn left at the spot
   }
   else 
   {
     comtemp = 't'; //stop 
   }   
   
   if(comtemp != oldComtemp){
     Serial.print(comtemp);
     oldComtemp = comtemp;
   }
 }
  
}

