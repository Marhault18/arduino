#include <IRremote.h>
 
int RECV_PIN = 3; // the pin where you connect the output pin of TSOP4838
int led1 = 2;
int led2 = 4;
int led3 = 7;
int led4 = 8;
int led5 = 2;
int led6 = 4;
int led7 = 7;
int led8 = 8;
int led9 = 4;
int itsONled[] = {0,0,0,0,0,0,0,0,0};
/* the initial state of LEDs is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
led to light when the board is powered */
#define code1  26775 // code received from button 1
#define code2  39015 // code received from button 2
#define code3  45135 // code received from button 3
#define code4  12495 // code received from button 4
#define code5  6375  // code received from button 5
#define code6  31365 // code received from button 6
#define code7  4335  // code received from button 7

IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
}
 
void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1:
         if(itsONled[1] == 1) {        // if first led is on then
            digitalWrite(led1, LOW);   // turn it off when button is pressed
            itsONled[1] = 0;           // and set its state as off
         } else {                      // else if first led is off
             digitalWrite(led1, HIGH); // turn it on when the button is pressed
             itsONled[1] = 1;          // and set its state as on
         }
          break; 
       case code2:
         if(itsONled[2] == 1) {
            digitalWrite(led2, LOW);
            itsONled[2] = 0;
         } else {
             digitalWrite(led2, HIGH);
             itsONled[2] = 1;
         }
          break;
       case code3:
         if(itsONled[3] == 1) {
            digitalWrite(led3, LOW);
            itsONled[3] = 0;
         } else {
             digitalWrite(led3, HIGH);
             itsONled[3] = 1;
         }

          break;
       case code4:
         if(itsONled[4] == 1) {
            digitalWrite(led4, LOW);
            itsONled[4] = 0;
         } else {
             digitalWrite(led4, HIGH);
             itsONled[4] = 1;
         }
         
          break;
       case code5:
         if(itsONled[5] == 1) {
            digitalWrite(led5, LOW);
            itsONled[5] = 0;
         } else {
             digitalWrite(led5, HIGH);
             itsONled[5] = 1;
         }
         if(itsONled[5] == 1) {        // if first led is on then
            digitalWrite(led6, LOW);   // turn it off when button is pressed
            itsONled[5] = 0;           // and set its state as off
         } else {                      // else if first led is off
             digitalWrite(led6, HIGH); // turn it on when the button is pressed
             itsONled[5] = 1;          // and set its state as on
         }
         if(itsONled[5] == 1) {
            digitalWrite(led7, LOW);
            itsONled[5] = 0;
         } else {
             digitalWrite(led7, HIGH);
             itsONled[5] = 1;
         }
         
          break;
       case code6:
         if(itsONled[6] == 1) {
            digitalWrite(led1, LOW);
            itsONled[6] = 0;
         } else {
             digitalWrite(led1, HIGH);
             itsONled[6] = 1;
         }
         if(itsONled[6] == 1) {  
          delay(500);
            digitalWrite(led2, LOW);   
            itsONled[6] = 0;           // and set its state as off
         } else {    
          delay(500);                  
             digitalWrite(led2, HIGH); // turn it on when the button is pressed
             itsONled[6] = 1;          // and set its state as on
         }
         if(itsONled[6] == 1) {
          delay(1000);
            digitalWrite(led3, LOW);
            itsONled[6] = 0;
         } else {
          delay(1000);
             digitalWrite(led3, HIGH);
             itsONled[6] = 1;
         }
         
          break;
       case code7:
         if(itsONled[7] == 1) {
            digitalWrite(led3, LOW);
            itsONled[7] = 0;
         } else {
             digitalWrite(led3, HIGH);
             itsONled[7] = 1;
         }
         if(itsONled[7] == 1) {  
          delay(500);
            digitalWrite(led9, LOW);   
            itsONled[7] = 0;           // and set its state as off
         } else {    
          delay(500);                  
             digitalWrite(led9, HIGH); // turn it on when the button is pressed
             itsONled[7] = 1;          // and set its state as on
         }
         if(itsONled[6] == 1) {
          delay(1000);
            digitalWrite(led1, LOW);
            itsONled[7] = 0;
         } else {
          delay(1000);
             digitalWrite(led1, HIGH);
             itsONled[7] = 1;
         }
         

          break;          
    }
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
}
