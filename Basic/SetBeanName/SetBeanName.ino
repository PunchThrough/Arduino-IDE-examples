/* 
  This sketch shows you how to change the name of your Bean depending on the ambient temperature.
  
  If the name doesn't change, try turning Bluetooth off and on on your device to clear the cache. 
  
  This example code is in the public domain.
*/

void setup() {
}

void loop()
{
 int temp = Bean.getTemperature(); 
 String beanName = "Temp is ";

 beanName += String(temp, DEC ); 
 beanName += " C";
 
 Bean.setBeanName(beanName);
 
 // Sleep for a minute 
 Bean.sleep(60000);
}
