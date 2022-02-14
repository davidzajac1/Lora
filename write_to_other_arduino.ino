// #include <Wire.h>

// void setup() {
//   Wire.begin(8);                // join i2c bus with address #8
//   Wire.onRequest(requestEvent); // register event
// }

// void loop() {
//   delay(100);
// }

// // function that executes whenever data is requested by master
// // this function is registered as an event, see setup()
// void requestEvent() {
//   Wire.write("hello "); // respond with message of 6 bytes
//   // as expected by master
// }







// void setup(){
//  Serial.begin(9600);
//  delay(2000);
// }

// void loop() {
//  ////read sensor data to a variable 
//  Serial.println(sensorDataVariable);
//  delay(2000); //Not to flood serial port
// }




char mystr[5] = "Hello"; //String data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.write(mystr,5); //Write the serial data
  delay(1000);
}