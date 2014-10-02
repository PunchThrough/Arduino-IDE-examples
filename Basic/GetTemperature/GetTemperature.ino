/* 
  This sketch reads the ambient temperature from the Bean's on-board temperature sensor. 
  
  The temperature readings are sent over serial and can be accessed in Arduino's Serial Monitor.
  
  To use the Serial Monitor, set Arduino's serial port to "/tmp/tty.LightBlue-Bean" 
  and the Bean as "Virtual Serial" in the OS X Bean Loader.
    
  This example code is in the public domain.
*/

void setup() {
  // Bean Serial is at a fixed baud rate. Changing the value in Serial.begin() has no effect.
  Serial.begin();
}

void loop() {
  // Get the current ambient temperature in degrees Celsius with a range of -40 C to 87 C.
  int temperature = Bean.getTemperature();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  Bean.sleep(3000);
}
