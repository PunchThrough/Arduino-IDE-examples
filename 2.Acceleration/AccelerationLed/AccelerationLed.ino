/* 
  This sketch reads the acceleration from the Bean's on-board 
  accelerometer and displays it on the Bean's LED.
    
  This example code is in the public domain.
*/

void setup() {
  // Optional: Use Bean.setAccelerationRange() to set the sensitivity 
  // to something other than the default of ±2g.
}

// the loop routine runs over and over again forever:
void loop() {
   // Get the current acceleration with range of ±2g, 
   // and a conversion of 3.91×10-3 g/unit or 0.03834(m/s^2)/units. 
   AccelerationReading accel = Bean.getAcceleration();

   // Update LED color
   uint16_t r = (abs(accel.xAxis)) / 4;
   uint16_t g = (abs(accel.yAxis)) / 4;
   uint16_t b = (abs(accel.zAxis)) / 4;
   Bean.setLed((uint8_t)r,(uint8_t)g,(uint8_t)b);

   Bean.sleep(50);
}
