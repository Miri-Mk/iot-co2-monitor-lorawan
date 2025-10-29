# IoT CO₂ Monitor

Ein IoT-basiertes CO₂-Überwachungssystem auf Basis des **Heltec WiFi LoRa 32 V2** (ESP32) und **LoRaWAN**.  
Das Projekt misst CO₂-Werte (und ggf. Temperatur- und Feuchtigkeitswerte) und sendet sie über _The Things Stack_ an _Datacake_ zur Visualisierung.

## Funktionen

- Messung von CO₂, ggf. Temperatur und Luftfeuchtigkeit
- LoRaWAN-Kommunikation über The Things Stack (TTN-Backend) mittels OTAA (Over-The-Air Activation)
- Anzeige der Messwerte auf OLED-Display
- Speicherung und Visualisierung in Datacake

## Aufbau

iot-co2-monitor-lorawan/
├── src/ # Hauptprogramm (main.ino)
├── include/ # Header-Dateien (config.h, secrets_template.h)
└── README.md # Projektübersicht und git-Workflow

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
git clone <repository-url>
```

2. **In Projektverzeichnis wechseln**

```bash
cd iot-co2-monitor-lorawan
```

3. **Auf den Entwicklungszweig wechseln**

```bash
git checkout dev
git pull origin dev
```

4. **Feature-Branch vorbereiten**
   Entweder neuen Branch anlegen (wenn man neues Thema beginnt):

```bash
git checkout -b feature/<beschreibung>
git push -u origin feature/<beschreibung>
```

Oder bestehenden Branch zum ersten Mal auschecken:

```bash
git fetch origin
git checkout feature/<beschreibung>
git pull
```

**Jedesmal:**

1. **In git-Ordner wechseln**

```bash
cd "C:\Users\...\...\iot-co2-monitor-lorawan"
```

2. **In den jeweiligen Feature-Branch wechseln**

```bash
git checkout feature/<beschreibung>
```

3. **Feature-Branch mit aktuellem dev-Branch abgleichen**

- Aktuellen Stand des eigenen Feature-Branches holen

```bash
git pull origin feature/<beschreibung>
```

- Aktuelle Änderungen aus dem dev-Branch vom Remote holen

```bash
git fetch origin dev
```

- dev-Branch in den eigenen Feature-Branch mergen

```bash
git merge origin/dev
```

- Falls Konflikte entstehen: Datei in IDE öffnen, Konflikte manuell lösen, dann

```bash
git add .
git commit -m "fix: Konflikte gelöst"
```

5. **Entwickeln → committen → pushen**

- Entwickeln
- ÄNDERUNGEN IN ARDUINO IDE SPEICHERN!!!
- Commit und Push:

```bash
git add .
git commit -m "feat: Beschreibung der Änderung"
git push
```

6. **Fertig entwickeltes Feature in dev mergen (lokal) und pushen**

```bash
git checkout dev
git pull origin dev
git merge feature/<beschreibung>
git push origin dev
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

2. Datei include/secrets_template.h kopieren und als include/secrets.h speichern! (secrets.h nicht versioniert, weil in .gitignore ausgeschlossen)
   → LoRaWAN-Zugangsdaten (AppEUI, DevEUI, AppKey) eintragen

3. Board „Heltec WiFi LoRa 32 (V2)” in der Arduino IDE auswählen
   (Tools → Board → Heltec WiFi LoRa 32 V2)

4. Port auswählen: Tools → Port → COMx (richtiges Gerät auswählen)

5. Gerät per USB verbinden

6. Sketch (main.ino) kompilieren und hochladen

7. Im Serial Monitor prüfen, ob die OTAA-Join-Request erfolgreich war und Daten an The Things Stack gesendet werden
   Typische erfolgreiche Ausgabe:
   Joined successfully via OTAA!
   Falls Fehler auftreten, z. B. Join failed oder No valid keys, Zugangsdaten in secrets.h prüfen und Board ggf. neu starten.
