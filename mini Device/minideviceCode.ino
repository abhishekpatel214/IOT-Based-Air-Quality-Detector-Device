#include <LiquidCrystal.h>   // Header file for LCD

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // Pins of LCD connected to Arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // LCD function from LiquidCrystal
int buz = 8;  // Buzzer connected to pin 8
const int aqsensor = A0;  // Output of MQ135 connected to A0 pin of Arduino
int threshold = 250;  // Threshold level for Air Quality

void setup() {
  pinMode(buz, OUTPUT);  // Buzzer is connected as output
  pinMode(aqsensor, INPUT);  // MQ135 is connected as input to Arduino
  Serial.begin(9600);  // Begin serial communication with baud rate of 9600
  lcd.clear();  // Clear LCD
  lcd.begin(16, 2);  // Initialize LCD with 16 columns and 2 rows
}

void loop() {
  int ppm = analogRead(aqsensor);  // Read MQ135 analog output at A0 and store it in ppm
  Serial.print("Air Quality: ");  // Print message in serial monitor
  Serial.println(ppm);  // Print value of ppm in serial monitor
  lcd.setCursor(0, 0);  // Set cursor of LCD to 1st row and 1st column
  lcd.print("Air Quality:");  // Print message on LCD
  lcd.setCursor(0, 1);  // Set cursor of LCD to 2nd row and 1st column
  lcd.print(ppm);  // Print value of MQ135

  if (ppm > threshold) {  // Check if ppm is greater than threshold or not
    lcd.setCursor(0, 2);  // Set cursor of LCD to 3rd row and 1st column
    lcd.print("AQ Level HIGH");
    Serial.println("AQ Level HIGH");
    digitalWrite(buz, HIGH);  // Turn ON Buzzer
  } else {
    digitalWrite(buz, LOW);  // Turn off Buzzer
    lcd.setCursor(0, 2);  // Set cursor of LCD to 3rd row and 1st column
    lcd.print("AQ Level Good");
    Serial.println("AQ Level Good");
  }

  delay(500);
}
