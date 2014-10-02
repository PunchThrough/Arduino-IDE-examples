/* 
  This sketch shows you how to monitor if your Bean is in free fall. 
  
  The Bean will track how many times it's been dropped.
  
  To use the Serial Monitor, set Arduino's serial port to "/tmp/tty.LightBlue-Bean"
  and the Bean as "Virtual Serial" in the OS X Bean Loader.
      
  This example code is in the public domain.
*/

// When acceleration is below this threshold, we consider it free fall.
#define THRESHOLD 65    

int fallDuration = 0;
int fallCount = 0;

void setup() {
  // Bean Serial is at a fixed baud rate. Changing the value in Serial.begin() has no effect.
  Serial.begin(); 
}

void loop() {
  // Take 60 readings in three seconds and check for free fall
  for(int i = 0; i < 60; i++){
    // Get the current acceleration with a conversion of 3.91×10-3 g/unit.
    AccelerationReading currentAccel = Bean.getAcceleration();   
    uint32_t magnitude = abs(currentAccel.xAxis) + abs(currentAccel.yAxis) + abs(currentAccel.zAxis);
    
    // Is the Bean in free fall?                                            
    if(magnitude < THRESHOLD){
      fallDuration++; 
      // Check if the Bean has been in free fall for at least 150ms.
      if(fallDuration == 3){
        fallCount++;
      } 
    }else{
      fallDuration = 0;
    }
    // Check for free fall 20 times a second
    Bean.sleep(50);
  }
  
  // Print the drop count
  Serial.print("I've been dropped ");
  Serial.print(fallCount);
  Serial.println(" time(s)!");
}


