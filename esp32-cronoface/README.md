# Cronoface_Cerradura

Proyecto de ejemplo para compilar en Jenkins con PlatformIO y ESP32‑CAM.

- Board: `esp32cam` (AI Thinker ESP32‑CAM)
- Framework: Arduino
- Toolchain: PlatformIO
- Pipeline: Jenkins declarative pipeline (Jenkinsfile)

El código está simplificado para pruebas de integración continua: enciende el LED flash,
se conecta a WiFi (si se configura) y publica un mensaje MQTT opcional.
