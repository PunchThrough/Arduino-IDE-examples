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
  // Make LED red
  Bean.setLed(255, 0, 0);
  Bean.sleep(1000);      
  // Make LED green  
  Bean.setLed(0, 255, 0);
  Bean.sleep(1000);
  // Make LED blue
  Bean.setLed(0, 0, 255);
  Bean.sleep(1000);
  // Turn off LED
  Bean.setLed(0, 0, 0);
  Bean.sleep(1000);
}
