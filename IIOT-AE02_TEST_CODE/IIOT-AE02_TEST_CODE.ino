
/*
 * RS485
 * All Output Turn ON Series
 * All input status serial print
 
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1X15.h>
#include "FS.h"

#define ANALOG_PIN_0 32
#define I2C1_SDA 16
#define I2C1_SCL 17

#define INPUT1 18
#define INPUT2 39
#define INPUT3 34
#define INPUT4 35
#define INPUT5 19
#define INPUT6 21
#define INPUT7 22
#define INPUT8 23

#define OUTPUT1 26
#define OUTPUT2 27
#define OUTPUT3 14
#define OUTPUT4 12
#define OUTPUT5 13
#define OUTPUT6 15
#define OUTPUT7 2
#define OUTPUT8 33

#define RS485_RXD 3
#define RS485_TXD 1
#define RS485_FC 4

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_ADS1115 ads1;
Adafruit_ADS1115 ads2;

int analog_value = 0;

int readSwitch(){
  analog_value = analogRead(ANALOG_PIN_0);

 
  return analog_value                                                                                                ; //Read analog
}

void setup() {
 
 Serial.begin(9600);
 
 pinMode(RS485_FC, OUTPUT); 
 digitalWrite(RS485_FC, HIGH);

 Serial2.begin(115200, SERIAL_8N1,RS485_RXD,RS485_TXD);

  
  pinMode(OUTPUT1, OUTPUT);
  pinMode(OUTPUT2, OUTPUT);
  pinMode(OUTPUT3, OUTPUT);
  pinMode(OUTPUT4, OUTPUT);
  pinMode(OUTPUT5, OUTPUT);
  pinMode(OUTPUT6, OUTPUT);
  pinMode(OUTPUT7, OUTPUT);
  pinMode(OUTPUT8, OUTPUT);

  pinMode(INPUT1, INPUT);
  pinMode(INPUT2, INPUT);
  pinMode(INPUT3, INPUT);
  pinMode(INPUT4, INPUT);
  pinMode(INPUT5, INPUT);
  pinMode(INPUT6, INPUT);
  pinMode(INPUT7, INPUT);
  pinMode(INPUT8, INPUT);

  
  Wire.begin(16,17);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  
 Wire.begin(I2C1_SDA,I2C1_SCL);
  delay(100);
  I2C_SCAN_1();
 Serial.println("\nI2C Scanner");
 
    
    
 if (!ads1.begin(0x48)) {
    Serial.println("Failed to initialize ADS 1 .");
   // while (1);
  }

  if (!ads2.begin(0x49)) {
    Serial.println("Failed to initialize ADS 1 .");
   // while (1);
  }

  adcAttachPin(32);
  digitalWrite(RS485_FC, HIGH);   // RS-485 

}


void loop() {

  int16_t adc0, adc1, adc2, adc3;
 
  Serial.println(""); 
  Serial2.print(digitalRead(INPUT1));
  Serial2.print(digitalRead(INPUT2));
  Serial2.print(digitalRead(INPUT3));
  Serial2.print(digitalRead(INPUT4));
  Serial2.print(digitalRead(INPUT5));
  Serial2.print(digitalRead(INPUT6));
  Serial2.print(digitalRead(INPUT7));
  Serial2.print(digitalRead(INPUT8));
  Serial2.println(""); 

  Serial2.print("Push button  ");Serial2.println(readSwitch());
  Serial2.println(""); 

  adc0 = ads1.readADC_SingleEnded(0);
  adc1 = ads1.readADC_SingleEnded(1);
  adc2 = ads1.readADC_SingleEnded(2);
  adc3 = ads1.readADC_SingleEnded(3);

  Serial2.println("-----------------------------------------------------------");
  Serial2.print("AIN1: "); Serial2.print(adc0); Serial2.println("  ");
  Serial2.print("AIN2: "); Serial2.print(adc1); Serial2.println("  ");
  Serial2.print("AIN3: "); Serial2.print(adc2); Serial2.println("  ");
  Serial2.print("AIN4: "); Serial2.print(adc3); Serial2.println("  ");

  adc0 = ads2.readADC_SingleEnded(0);
  adc1 = ads2.readADC_SingleEnded(1);
  adc2 = ads2.readADC_SingleEnded(2);
  adc3 = ads2.readADC_SingleEnded(3);

  Serial2.println("-----------------------------------------------------------");
  Serial2.print("AIN4: "); Serial2.print(adc0); Serial2.println("  ");
  Serial2.print("AIN5: "); Serial2.print(adc1); Serial2.println("  ");
  
  
  digitalWrite(OUTPUT1, HIGH);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, LOW);
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, HIGH);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, LOW);
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, HIGH);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, LOW);
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, HIGH);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, LOW);
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, HIGH);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, LOW);
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, HIGH);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, LOW);
 
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, HIGH);
  digitalWrite(OUTPUT8, LOW);
  
  delay(200);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  digitalWrite(OUTPUT5, LOW);
  digitalWrite(OUTPUT6, LOW);
  digitalWrite(OUTPUT7, LOW);
  digitalWrite(OUTPUT8, HIGH);
  
  delay(200);
  
  digitalWrite(RS485_FC, HIGH);                    // Make FLOW CONTROL pin HIGH
  delay(500);
  Serial2.println(F("RS485 01 SUCCESS"));    // Send RS485 SUCCESS serially
  delay(500);                                // Wait for transmission of data
  digitalWrite(RS485_FC, LOW) ;                    // Receiving mode ON

                                             // Serial1.flush() ;
  delay(1000);     
  
  while (Serial2.available()) {  // Check if data is available
    char c = Serial2.read();     // Read data from RS485
    Serial.write(c);             // Print data on serial monitor
  }
   delay(500);
}
 void I2C_SCAN_1(){
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");

      deviceCount++;
      delay(1);  // Wait for a moment to avoid overloading the I2C bus
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found in Wire 1\n");
  }
  else {
    Serial.println("Wire 1 Scanning complete\n");
  }

  delay(1000);  // Wait for 5 seconds before scanning again
}
