/* 
  This sketch monitors if the Bean is connected to a device or not. 
  
  The on-board LED is green when the Bean is connected and red when it's not.
  
  Please note that the LED quickly will drain the battery.
  
  This example code is in the public domain.
*/

bool connected = false;

void setup() {
  //Turn of the LED
  Bean.setLed(0, 0, 0);
}

void loop() {
  connected = Bean.getConnectionState();
  if(connected){
    //Turn the LED green
    Bean.setLed(0, 255, 0);
  }
  else{
    //Turn the LED red
    Bean.setLed(255, 0, 0);
  }
  Bean.sleep(100);
}
