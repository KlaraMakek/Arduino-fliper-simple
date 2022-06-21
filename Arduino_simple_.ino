// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit Graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Reset pin not used but needed for library
#define OLED_RESET 4
 
// Create an object for each OLED display
Adafruit_SSD1306 display1(OLED_RESET);
Adafruit_SSD1306 display2(OLED_RESET);

int Sensor1 = 5; // set the value for Sensor1
int Sensor2 = 3; // set the value for Sensor2
int Sensor3 = 2; // set the value for Sensor3
int Sensor4 = 1; // set the value for Sensor4

int ResetButton = 6;  // set the value for ResetButton

int StateSensor1;
int StateSensor2;
int StateSensor3;
int StateSensor4;

int score = 0;

void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void setup() {
  pinMode(Sensor1, INPUT_PULLUP); //set the Sensor1(10) output as input, pull-up
  pinMode(Sensor2, INPUT_PULLUP); //set the Sensor2 (9) output as input, pull-up
  pinMode(Sensor3, INPUT_PULLUP); //set the Sensor3 (8) output as input, pull-up
  pinMode(Sensor4, INPUT_PULLUP); //set the Sensor4 (7) output as input, pull-up
 
  // Start Wire library for I2C
  Wire.begin();
 
  // Set multiplexer to channel 1 and initialize OLED-0 with I2C addr 0x3C

     // Set multiplexer to channel 1 and initialize OLED-0 with I2C addr 0x3C
  TCA9548A(1);
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display1.clearDisplay();
  display1.setTextSize(4);
  display1.setTextColor(WHITE);
  display1.setCursor(18, 0);
  // Display static text
  display1.println("GAME");
  display1.display();
  // initialize OLED-1 with I2C addr 0x60
  TCA9548A(2);
  display2.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display2.clearDisplay();
  display2.setTextSize(4);
  display2.setTextColor(WHITE);
  display2.setCursor(18    , 0);
  // Display static text
  display2.println("START");
  display2.display();

 
 
}

void loop() {
  StateSensor1 = digitalRead(Sensor1); //read the statement status and store it in StateSensor
  if (StateSensor1 == LOW) { //if the sensor is activated
   
     // display 1
  TCA9548A(1);
      score = score + 10; //add 10 points
  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 0);
  // Display static text
  display1.println("SCORE:");
   display1.print(score);
  display1.display();
    delay(300);

  // display 2
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 0);
  // Display static text
  display2.println("Existence Is Pain");
  display2.display();

}else{}
  StateSensor2 = digitalRead(Sensor2); //read the statement status and store it in StateSensor
  if (StateSensor2 == LOW) { //if the sensor is activated
   
     // display 1
  TCA9548A(1);
      score = score + 10; //add 10 points
  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 0);
  // Display static text
  display1.println("SCORE:");
   display1.print(score);
  display1.display();
    delay(300);

  // display 2
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 0);
  // Display static text
  display2.println("Pickle    Rick");
  display2.display();
}else {}
  StateSensor3 = digitalRead(Sensor3); //read the statement status and store it in StateSensor
  if (StateSensor3 == LOW) { //if the sensor is activated
   
     // display 1
  TCA9548A(1);
      score = score + 10; //add 10 points
  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 0);
  // Display static text
  display1.println("SCORE:");
     display1.print(score);
  display1.display();
    delay(300);

  // display 2
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 0);
  // Display static text
  display2.println("PeaceAmong Worlds");
  display2.display();
}else {}
  StateSensor4 = digitalRead(Sensor4); //read the statement status and store it in StateSensor
  if (StateSensor4 == LOW) { //if the sensor is activated
   
     // display 1
  TCA9548A(1);
      score = score + 10; //add 10 points
  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 0);
  // Display static text
  display1.println("SCORE:");
     display1.print(score);
  display1.display();
    delay(300);

  // display 2
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 0);
  // Display static text
  display2.println("WubbaLubba Dub Dub");
  display2.display();

}else{}


if(digitalRead(6) == HIGH)
 {  
     // display 1
  TCA9548A(1);
  display1.clearDisplay();
  display1.setTextSize(4);
  display1.setTextColor(WHITE);
  display1.setCursor(18, 0);
  // Display static text
  display1.println("GAME");
  display1.display();
  score = 0;

  // display 2
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextSize(4);
  display2.setTextColor(WHITE);
  display2.setCursor(7, 0);
  // Display static text
  display2.println("START");
  display2.display();

  }
}
