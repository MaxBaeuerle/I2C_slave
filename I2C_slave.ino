#include <Wire.h>
//SDA
//SCL 

#define SLAVE_ADDRESS 0x01

void setup() {
  Serial.begin(115200);        
  while (!Serial);           

  Wire.begin(SLAVE_ADDRESS); // I2C als Slave starten
  Wire.onReceive(receiveEvent);

  Serial.println("I2C Slave bereit...");
}

void loop() {
  // Nichts nötig – Empfang läuft über Interrupt
}

// Wird aufgerufen, wenn Daten vom Master kommen
void receiveEvent(int byteCount) {
  Serial.print("Empfangen: ");
  Serial.print(byteCount);
  Serial.println(" Byte(s)");

  while (Wire.available()) {
    byte data = Wire.read();

    Serial.print("Byte: ");
    Serial.print(data);
    Serial.print(" | Hex: ");
    Serial.print(data, HEX);
    Serial.print(" | Binär: ");
    Serial.println(data, BIN);

  }

  Serial.println("----------------------------------");
}
