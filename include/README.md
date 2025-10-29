# include-Ordner

Dieser Ordner enthält Header-Dateien (\*.h) für Konfiguration und Zugangsdaten.

## Dateien

**config.h**  
In diese Datei werden allgemeine Projekteinstellungen wie Pinbelegung, Sensor-Typen und Schwellenwerte eingetragen. Sie wird in die main eingebunden.

Beispiel:

```cpp
#define DHTPIN 13
#define DHTTYPE DHT22
#define TX_INTERVAL 60  // Sendeintervall in Sekunden
```

**secrets_template.h**  
Vorlage mit Platzhaltern für LoRaWAN-Schlüssel (`AppEUI`, `DevEUI`, `AppKey`).  
Wird im Repository geteilt.

**secrets.h**  
Lokale Datei mit echten Schlüsseln, die jeder Entwickler lokal selbst anlegt.  
Teil von `.gitignore` -> wird nicht commited
Echte Keys sind in der Nextcloud dokumentiert
