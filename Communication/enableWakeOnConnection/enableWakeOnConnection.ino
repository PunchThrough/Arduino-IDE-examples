/* 
  This sketch shows how to use the enableWakeOnConnect() function. 

  In this example the LED is turned on when the Bean is awake. 
  To save power the Bean will be put to sleep when it's not connected to another device,
  and woken up when it's connected to by using enableWakeOnConnect().
  
  This example code is in the public domain.
*/

bool connected = false;

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
   // Turn the LED green
   Bean.setLed(0, 255, 0);
   Bean.sleep(1000);
 }else{
   // Turn off the LED
   Bean.setLed(0, 0, 0);
   // Sleep forever or until the Bean wakes up by being connected to
   Bean.sleep(0xFFFFFFFF);
 }
}
