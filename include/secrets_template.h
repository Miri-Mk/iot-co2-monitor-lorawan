// Vorlage für LoRaWAN-Zugangsdaten (dient als Muster)
// Jeder Entwickler lokal eigene Datei "secrets.h" erstellen
// und dort die echten Werte aus The Things Stack (TTS) eintragen
// 1. Vorlage kopieren: bash: cp include/secrets_template.h include/secrets.h
// 2. Keys eintragen
// 3. In main.ino ist Datei mit #include "secrets.h" eingebunden
// Wegen .gitignore wird secrets.h-Datei nicht gepusht


#ifndef SECRETS_TEMPLATE_H
#define SECRETS_TEMPLATE_H

// ---------------------------
// LoRaWAN-Zugangsdaten (OTAA)
// ---------------------------

// Application EUI (8 Bytes, Little Endian Format)
// Beispiel: 70B3D57ED0XXXXXX
#define APP_EUI "0000000000000000"

// Device EUI (8 Bytes, Little Endian Format)
// Beispiel: A84041F17BXXXXXX
#define DEV_EUI "0000000000000000"

// Application Key (16 Bytes, Big Endian Format)
// Beispiel: C4E7A8FA1XXXXXXX
#define APP_KEY "00000000000000000000000000000000"

#endif
