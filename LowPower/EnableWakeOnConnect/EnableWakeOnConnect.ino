/* 
  This sketch shows how to use enableWakeOnConnect(). 
  It wakes the Bean up when it establishes a BLE connection.
  
  If the Bean is connected to another device, the built-in LED will blink red.  
  If the device disconnects the Bean will sleep and the LED stops blinking.

  This example code is in the public domain.
*/

bool connected;

void setup() 
{
  // Turn off the LED
  Bean.setLed(0, 0, 0);
  Bean.enableWakeOnConnect(true); 
}

void loop() 
{ 
 connected = Bean.getConnectionState();
 if(connected)
 {
    //Blink the LED red
    Bean.setLed(255, 0, 0);
    Bean.sleep(100);
    Bean.setLed(0, 0, 0);
    Bean.sleep(100);
 }else{
   // Turn off the LED
   Bean.setLed(0, 0, 0);
   // Sleep forever or until the Bean wakes up by being connected to
   Bean.sleep(0xFFFFFFFF);
 }
}
