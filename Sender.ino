#include <Wire.h>

int s;
long x;
long y;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
}

void loop() {

  x = analogRead(A0);
  y = analogRead(A1);
  //int z = analogRead(A0);
 // Serial.println(x);
  if (x < 500) {
    s = 0;
  } else if (x > 600) {
    s = 1;
  } else if (y < 500) {
    s = 2;
  } else if (y > 600) {
    s = 3;
  } else{
    s = 4;
  }
  
  Serial.println(s);

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(s);              // sends s
  Wire.endTransmission();    // stop transmitting
  /*Wire.requestFrom(9, 6);    // request 6 bytes from slave device #8
    while (Wire.available()) { // slave may send less than requested
    char x = Wire.read(); // receive a byte as character
    Serial.print(x);  // print the character
  */
  delay(10);

}
