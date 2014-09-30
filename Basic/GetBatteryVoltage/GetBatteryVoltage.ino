/* 
  This sketch shows you how to read the battery or power supply voltage of the Bean.
  
  The voltage readings are sent over serial and can be accessed in Arduino's Serial Monitor.
  To use the Serial Monitor, set Arduino's serial port to "/tmp/tty.LightBlue-Bean" and the Bean as "Virtual Serial" in the OS X Bean Loader.

  This example code is in the public domain.
*/

void setup() {
  Serial.begin(); // Bean Serial is at a fixed baud rate. Changing the value in Serial.begin() has no effect.
}

void loop() {
 uint16_t batteryReading =  Bean.getBatteryVoltage(); // Returns the voltage with conversion of 0.01 V/unit
 
 // Format the output like "Battery voltage: 2.60 V"
 String stringToPrint = String();
 stringToPrint = stringToPrint + "Battery voltage: " + batteryReading/100 + "." + batteryReading%100 + " V";
 Serial.println(stringToPrint);
 
 Bean.sleep(1000);
}
