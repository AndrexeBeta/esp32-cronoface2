#include "keypad_input.h"
#include "state_machine.h"
#include "../include/security/pin_auth.h"

static String buffer;

void init_keypad() {
    buffer.reserve(8);
}

// Para pruebas: simulamos que siempre llega el PIN correcto cada cierto tiempo.
void read_keypad_input() {
    static unsigned long last = 0;
    if (millis() - last > 10000) { // cada 10 segundos
        last = millis();
        buffer = AUTH_PIN;
        if (check_pin(buffer)) {
            // Simplemente escribimos por serial; la FSM leerá este evento mediante Serial.
            Serial.println(F("PIN_OK"));
        }
        buffer = "";
    }
}
