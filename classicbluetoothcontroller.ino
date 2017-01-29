#include <SoftwareSerial.h>// import the serial library

SoftwareSerial RemoteControl(2,3); // RX, TX
int ledpin=13; // led on D13 will show blink on / off - Or you could choose any possible Digital GPIO
int BluetoothData; // the data input

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RemoteControl.begin(38400);
  RemoteControl.println("Bluetooth On please press 1 blink LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
   if (RemoteControl.available()){
BluetoothData=RemoteControl.read();
Serial.println("REading remote input");
Serial.println(BluetoothData);
   digitalWrite(ledpin,1);


   if(BluetoothData=='1'){   // if number 1 pressed
Serial.println("Remote REading 1 input");

   digitalWrite(ledpin,1);
Serial.println("LED HIGH");
   RemoteControl.println("LED is ON ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed
  Serial.println("Remote Reading 0 input");
  digitalWrite(ledpin,0);
Serial.println("LED LOW");
     RemoteControl.println("LED  is Off ! ");
  }
}
delay(1000);
}
