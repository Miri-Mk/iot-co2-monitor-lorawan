#include <HardwareSerial.h>

HardwareSerial sensor(2); // UART2

const int OUTPUT_PIN = 13; // Pin für Signal (kannst du ändern)
int timeCounter = 0;

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println("MH-Z19C UART-Test (Heltec WiFi LoRa V2)");
  
  // Output Pin konfigurieren
  pinMode(OUTPUT_PIN, OUTPUT);
  digitalWrite(OUTPUT_PIN, LOW); // Startet ausgeschaltet
  
  sensor.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
  delay(1000); // Sensor Bootzeit
}

void loop() {
  // Messbefehl senden
  const uint8_t cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
  
  // Buffer leeren
  while(sensor.available()) sensor.read();
  
  sensor.write(cmd, 9);
  sensor.flush();
  
  delay(100); // Etwas mehr Zeit für Antwort
  
  // Prüfen ob Daten verfügbar
  if(sensor.available() >= 9) {
    uint8_t resp[9];
    sensor.readBytes(resp, 9);
    
    // Checksumme prüfen
    uint8_t checksum = 0;
    for(int i = 1; i < 8; i++) {
      checksum += resp[i];
    }
    checksum = 0xFF - checksum + 1;
    
    // Ausgabe
    Serial.print("Antwort: ");
    for(int i = 0; i < 9; i++) {
      if(resp[i] < 0x10) Serial.print("0");
      Serial.print(resp[i], HEX);
      Serial.print(' ');
    }
    
    if(checksum == resp[8] && resp[0] == 0xFF && resp[1] == 0x86) {
      int ppm = (resp[2] << 8) | resp[3];
      Serial.print(" -> CO2: ");
      Serial.print(ppm);
      Serial.println(" ppm [OK]");
      
      // Pin setzen basierend auf ppm-Wert
      if(ppm >= 1000 && ppm <= 5000) {
        if(timeCounter > 60 ){
          digitalWrite(OUTPUT_PIN, HIGH); delay(500);
          digitalWrite(OUTPUT_PIN, LOW); delay(500);
          digitalWrite(OUTPUT_PIN, HIGH); delay(500);
          digitalWrite(OUTPUT_PIN, LOW); delay(500);
          digitalWrite(OUTPUT_PIN, HIGH); delay(500);
          digitalWrite(OUTPUT_PIN, LOW); delay(500);
          timeCounter = 0;
        }else{
          timeCounter++;
        }
      } else {
        digitalWrite(OUTPUT_PIN, LOW);
        timeCounter = 0;
      }
      
    } else {
      Serial.println(" [CHECKSUM ERROR]");
      digitalWrite(OUTPUT_PIN, LOW); // Bei Fehler ausschalten
    }
  } else {
    Serial.println("Keine Antwort vom Sensor!");
    digitalWrite(OUTPUT_PIN, LOW); // Bei Fehler ausschalten
  }
  
  
  delay(1000);
}
