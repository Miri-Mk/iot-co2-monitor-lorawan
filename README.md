# IoT CO₂ Monitor

Ein IoT-basiertes CO₂-Überwachungssystem auf Basis des **Heltec WiFi LoRa 32 V2** (ESP32) und **LoRaWAN**.  
Das Projekt misst CO₂-Werte (und ggf. Temperatur- und Feuchtigkeitswerte) und sendet sie über _The Things Stack_ an _Datacake_ zur Visualisierung.

## Funktionen

- Messung von CO₂, ggf. Temperatur und Luftfeuchtigkeit
- LoRaWAN-Kommunikation mit The Things Stack (OTAA)
- Anzeige der Messwerte auf OLED-Display
- Speicherung und Visualisierung in Datacake

## Aufbau

iot-co2-monitor-lorawan/
├── src/ → Hauptprogramm (main.ino)
├── include/ → Header-Dateien (config.h, secrets_template.h)
└── README.md → Projektübersicht und git-Workflow

---

## Entwicklung

### Branch-Struktur

- **main** – stabile, getestete Versionen
- **dev** – gemeinsamer Entwicklungszweig
- **feature/** – Branches für einzelne Themen:
  - `feature/lora-connection` → LoRaWAN-Integration
  - `feature/sensor` → CO₂- und Umgebungssensoren
  - `feature/display` → OLED-Ausgabe
  - `feature/dashboard` → Datacake-Anbindung

### Arbeitsablauf

**Einmalig:**

1. **Repository klonen**

```bash
git clone <repository-url>`
```

2. **In Projektverzeichnis wechseln**

```bash
cd iot-co2-monitor-lorawan
```

3. **Feature-Branch vorbereiten**
   Entweder neuen Branch anlegen (wenn man neues Thema beginnt):

```bash
git checkout -b feature/<beschreibung>
```

Oder bestehenden Branch auschecken (wenn man an vorhandenem Feature-Branch weiterarbeitet):

```bash
git checkout feature/<beschreibung>
git pull
```

**Jedesmal:**

1. **In den jeweiligen Feature-Branch wechseln**

```bash
git checkout feature/<beschreibung>
```

2. **Neuesten Stand vom Remote-Repo holen**

```bash
git pull origin dev
```

3. **Entwickeln → committen → pushen**

```bash
git add .
git commit -m "feat: Beschreibung der Änderung"
git push
```

4. **Fertig entwickeltes Feature in dev mergen (lokal) und pushen**

```bash
git checkout dev
git pull
git merge feature/<beschreibung>
git push
```

**Regeln**

- Keine direkten Commits auf main
- Jeder entwickelt auf einem eigenen Feature-Branch
- Vor jedem Push immer git pull, um Konflikte zu vermeiden
- Kleine, thematisch saubere Commits mit klaren Messages
- Organisatorisches in README oder Nextcloud dokumentieren

## Ausführen (Run)

1. Neuesten Stand laden

```bash
git pull
```

2. Datei include/secrets_template.h kopieren und als include/secrets.h speichern
   → LoRaWAN-Zugangsdaten (AppEUI, DevEUI, AppKey) eintragen

3. Board „Heltec WiFi LoRa 32 (V2)” in der Arduino IDE auswählen
   (Tools → Board → Heltec WiFi LoRa 32 V2)

4. Gerät per USB verbinden

5. Sketch (main.ino) kompilieren und hochladen

6. Im Serial Monitor prüfen, ob die Verbindung zu The Things Stack erfolgreich hergestellt wurde
