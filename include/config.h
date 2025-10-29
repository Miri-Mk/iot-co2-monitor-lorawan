// Projektkonfiguration

#ifndef CONFIG_H
#define CONFIG_H

// ---------------------------
// LoRaWAN-Konfiguration
// ---------------------------

// Intervall, in dem Sensordaten gesendet werden (in Sekunden)
#define TX_INTERVAL <Sendeintervall_in_Sekunden>

// Frequenzband des LoRa-Netzes (z. B. 868E6 für Europa)
#define LORA_FREQUENCY <Frequenz_in_Hz>

// Pinbelegung des Heltec-Boards für LoRa-Kommunikation
#define LORA_DIO0_PIN   <Pin_DIO0>
#define LORA_DIO1_PIN   <Pin_DIO1>
#define LORA_DIO2_PIN   <Pin_DIO2>
#define LORA_RST_PIN    <Pin_Reset>
#define LORA_NSS_PIN    <Pin_ChipSelect>

// ---------------------------
// Sensor-Konfiguration
// ---------------------------

// CO₂-Sensor
#define CO2_RX_PIN  <RX_Pin_CO2_Sensor>
#define CO2_TX_PIN  <TX_Pin_CO2_Sensor>

// ggf. DHT-Sensor (Temperatur & Luftfeuchtigkeit)
#define DHTPIN   <Pin_DHT>
#define DHTTYPE  <Sensortyp>

// ---------------------------
// Display
// ---------------------------

// OLED-Display aktivieren oder deaktivieren (true = aktiv, false = deaktiviert)
#define DISPLAY_ENABLED <true_or_false>

// ---------------------------
// Weitere Einstellungen
// ---------------------------

// Serielle Schnittstelle (Baudrate für Debug-Ausgabe)
#define SERIAL_BAUD <Baudrate>

#endif
