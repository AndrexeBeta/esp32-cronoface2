#include "door_control.h"

// Usamos el pin del flash integrado como "rele" simbólico.
static const int RELAY_PIN = 4; // LED flash ESP32‑CAM

void door_control_setup() {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
}

void door_open() {
    digitalWrite(RELAY_PIN, HIGH);
}

void door_close() {
    digitalWrite(RELAY_PIN, LOW);
}
