int buz = 8;  //buzzer connected to pin 8
int green = 7;  //led connected to pin 9
int yello = 6;  //led connected to pin 9
int red = 5;  //led connected to pin 9
const int aqsensor = A0;  //output of mq135 connected to A0 pin of Arduino
int threshold = 230;//Threshold level for Air Quality
int threshold1 = 200; 
void setup() {
  pinMode (buz,OUTPUT);     // buzzer is connected as Output from Arduino
  pinMode (green,OUTPUT);     // led is connected as output from Arduino
  pinMode (yello,OUTPUT);     // led is connected as output from Arduino
  pinMode (red,OUTPUT);     // led is connected as output from Arduino
  pinMode (aqsensor,INPUT); // MQ135 is connected as INPUT to arduino
Serial.begin (9600);      //begin serial communication with baud rate of 9600
}
void loop() {
  int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A0 and store it in ppm
 Serial.print("Air Quality: ");  //print message in serail monitor
  Serial.println(ppm);            //print value of ppm in serial monitor
 if (ppm > threshold)            // check is ppm is greater than threshold or not
    {
      Serial.println("AQ Level HIGH"); 
      tone(red,1000,200);         //blink led with turn on time 1000mS, turn off time 200mS
       digitalWrite(green,LOW);   
       digitalWrite(yello,LOW); 
      digitalWrite(buz,HIGH);     //Turn ON Buzzer
}
else if (ppm < threshold)            // check is ppm is greater than threshold or not
    {
 if (ppm <= threshold1)            // check is ppm lower than or = threshold1
    {
Serial.println("AQ Level good"); 

 
tone(green,1000,200);         //blink led with turn on time 1000mS, turn off time 200mS
       digitalWrite(yello,LOW);   
       digitalWrite(red,LOW);
       digitalWrite(buz,LOW); 
    }
     Serial.println("AQ Level medium"); 
    tone(yello,1000,200);         //blink led with turn on time 1000mS, turn off time 200mS
       digitalWrite(green,LOW);   
       digitalWrite(red,LOW);
       digitalWrite(buz,LOW); 
    }
else
    {
 Serial.println("AQ Level Good");
     digitalWrite(green,HIGH); 
       digitalWrite(yello,LOW);
      digitalWrite(red,LOW);   
      digitalWrite(buz,LOW);  
    }  
  delay (500);
}
