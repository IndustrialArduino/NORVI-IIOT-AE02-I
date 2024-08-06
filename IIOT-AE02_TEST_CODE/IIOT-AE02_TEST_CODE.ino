#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1X15.h>
#include <SoftwareSerial.h>
#include <SPI.h>

// Define the screen dimensions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // I2C address for the OLED display

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_ADS1115 ads1;
Adafruit_ADS1115 ads2;

// RS485 communication pins
#define RS485_RXD 3
#define RS485_TXD 2
#define RS485_FC 4

SoftwareSerial rs485Serial(RS485_RXD, RS485_TXD);

#define ANALOG_PIN_0 32

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

int analog_value = 0;

int readSwitch() {
  analog_value = analogRead(ANALOG_PIN_0);
  return analog_value;
}

void setup() {
  Serial.begin(115200);
  pinMode(RS485_FC, OUTPUT);
  digitalWrite(RS485_FC, LOW);

  // Initialize RS485 serial communication
  rs485Serial.begin(9600);
  Serial2.begin(115200, SERIAL_8N1, RS485_RXD, RS485_TXD);

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

  Wire.begin(16, 17);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.display();

  if (!ads1.begin(0x48)) {
    Serial.println("Failed to initialize ADS 1.");
    while (1);
  }

  if (!ads2.begin(0x49)) {
    Serial.println("Failed to initialize ADS 2.");
    while (1);
  }
  TEST_SPECIFICATION();
  delay(500);
  digitalWrite(RS485_FC, HIGH);   // RS-485 
}

void loop() {
  int16_t adc0, adc1, adc2, adc3;

  Serial.println(""); 
  Serial.print(digitalRead(INPUT1)); 
  Serial.print(digitalRead(INPUT2)); 
  Serial.print(digitalRead(INPUT3)); 
  Serial.print(digitalRead(INPUT4)); 
  Serial.print(digitalRead(INPUT5)); 
  Serial.print(digitalRead(INPUT6)); 
  Serial.print(digitalRead(INPUT7)); 
  Serial.print(digitalRead(INPUT8));
  Serial.println(""); 

  Serial.print("Push button  "); 
  Serial.println(readSwitch());
  Serial.println(""); 

  adc0 = ads1.readADC_SingleEnded(0);
  adc1 = ads1.readADC_SingleEnded(1);
  adc2 = ads1.readADC_SingleEnded(2);
  adc3 = ads1.readADC_SingleEnded(3);

  Serial.println("-----------------------------------------------------------");
  Serial.print("AIN1: "); Serial.print(adc0); Serial.println("  ");
  Serial.print("AIN2: "); Serial.print(adc1); Serial.println("  ");
  Serial.print("AIN3: "); Serial.print(adc2); Serial.println("  ");
  Serial.print("AIN4: "); Serial.print(adc3); Serial.println("  ");

  adc0 = ads2.readADC_SingleEnded(0);
  adc1 = ads2.readADC_SingleEnded(1);

  Serial.print("AIN4: "); Serial.print(adc0); Serial.println("  ");
  Serial.print("AIN5: "); Serial.print(adc1); Serial.println("  ");
  Serial.println("-----------------------------------------------------------");

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

  digitalWrite(RS485_FC, HIGH); // Make FLOW CONTROL pin HIGH
  delay(500);
  Serial2.println(F("RS485 01 SUCCESS")); // Send RS485 SUCCESS serially
  delay(500); // Wait for transmission of data
  digitalWrite(RS485_FC, LOW); // Receiving mode ON

  delay(1000);

  while (Serial2.available()) { // Check if data is available
    char c = Serial2.read(); // Read data from RS485
    Serial.write(c); // Print data on serial monitor
  }

  // Handle RS485 communication with OLED display
  if (rs485Serial.available()) {
    String rs485Data = rs485Serial.readString();
    Serial.println(rs485Data);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("RS485 Data:");
    display.setCursor(0, 10);
    display.print(rs485Data);
    display.display();
  }

  if (Serial.available()) {
    String userInput = Serial.readString();
    digitalWrite(RS485_FC, HIGH);
    rs485Serial.print(userInput);
    digitalWrite(RS485_FC, LOW);
    delay(100);
  }

  delay(100);
}
void TEST_SPECIFICATION(){
   Serial.println("DIGITAL INPUTS '8'");
   Serial.println("TRANSISTER OUTPUT '2'");
   Serial.println("ANALOG INPUT CURRENT IN 4-20MHP /VOLTAGE 0-10");
   Serial.println("RS485 RECEVER 'TEST RESET BUTTON SERIAL2 BOUTRATE IS 9600'   ");
   Serial.println();
   Serial.println("RS485 TRANSMIT 'TEST RESET BUTTON SERIAL2 BOUTRATE IS 115200'   ");
   Serial.println();
   delay(1000);       
}
