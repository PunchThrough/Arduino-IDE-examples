/* 
  This sketch uses the Bean library to blink the on-board RGB LED. 
  
  Notes:
    - This is not a low-power sketch 
    - A Bean with a low battery might show a faint blue and green LED color
  
  This example code is in the public domain.
*/

void setup() {
}

void loop() {
  Bean.setLed(255, 0, 0);   // LED is red
  Bean.sleep(1000);        
  Bean.setLed(0, 255, 0);   // LED is green
  Bean.sleep(1000);
  Bean.setLed(0, 0, 255);   // LED is blue
  Bean.sleep(1000);
  Bean.setLed(0, 0, 0);     // LED is turned off
  Bean.sleep(1000);
}
