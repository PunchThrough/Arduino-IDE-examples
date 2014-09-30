/* 
  This sketch shows you how to monitor if your Bean moves by sampling the acceleration at 5Hz and measuring change. 
  
  The LED will blink red when it's being moved.
  
  Please note that if motion detection is triggered often, the LED use will drain the battery quickly.
    
  This example code is in the public domain.
*/

#define THRESHOLD 100    // When acceleration change goes beyond this threshold, the LED will blink.

AccelerationReading previousAccel;

void setup() {
  Bean.setLed(0, 0, 0);                   // Turn off the Bean's LED  
  previousAccel = Bean.getAcceleration(); // Initial reading
}

void loop() {
  AccelerationReading currentAccel = Bean.getAcceleration();   // Get the current acceleration with a conversion of 3.91×10-3 g/unit.
  
  int accelDifference = getAccelDifference(previousAccel, currentAccel);   // Find the difference between the current acceleration and that of 200ms ago.
  previousAccel = currentAccel;                                            // Update previousAccel for the next loop. 
   
  if(accelDifference > THRESHOLD){   // Check if the Bean has been moved beyond our threshold.
    // Blink the LED
    Bean.setLed(255, 0, 0);
    Bean.sleep(100);
    Bean.setLed(0, 0, 0); 
    Bean.sleep(100);
  }else{
    Bean.sleep(200);
  }
}

// This function calculates the difference between two acceleration readings
int getAccelDifference(AccelerationReading readingOne, AccelerationReading readingTwo){
  int deltaX = abs(readingTwo.xAxis - readingOne.xAxis);
  int deltaY = abs(readingTwo.yAxis - readingOne.yAxis);
  int deltaZ = abs(readingTwo.zAxis - readingOne.zAxis);
  return deltaX + deltaY + deltaZ;   // Return the magnitude
}
