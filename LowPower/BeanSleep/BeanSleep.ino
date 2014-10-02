/* 
  This sketch shows you how to use the Bean.sleep() function. 
  Bean.sleep() should be used in place of Arduino's generic sleep() function. 
  
  Bean.sleep() provides a time delay and is used to save power. 
  It's important to note that the Bean's sleep is interrupted by incoming serial data. 
  For example, Bean.sleep(10000) will only sleep for 10 seconds if no serial data is received during this time. 
  If serial data is received, the sleep will immediately end.
  
  In comparsion, the delay() function doesn't save power but provides a fixed delay.  
  
  To experience the difference between Bean.sleep() and delay(), 
  constantly send data to the Bean by entering characters in the Serial Monitor. 
  Notice the LED's off-time decreasing as the Bean.sleep() is interrupted.
  
  To use the Serial Monitor, set Arduino's serial port to "/tmp/tty.LightBlue-Bean" 
  and the Bean as "Virtual Serial" in the OS X Bean Loader.
  
  This example code is in the public domain.
*/

void setup() {
  // Bean Serial is at a fixed baud rate. Changing the value in Serial.begin() has no effect.
  Serial.begin();    
  // Turn off the Bean's LED    
  Bean.setLed(0,0,0);   
}

void loop() {
  // Turn the Bean's LED red 
  Bean.setLed(255,0,0); 
  // Delay for two seconds   
  delay(2000);
  // Turn off the Bean's LED 
  Bean.setLed(0,0,0);
  // Sleep for two seconds (unless serial data is received)
  Bean.sleep(2000);
}
