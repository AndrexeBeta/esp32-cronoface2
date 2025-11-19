#include "state_machine.h"
#include "door_control.h"
#include "oled_display.h"
#include "../include/security/pin_auth.h"

static DoorState current = DoorState::LOCKED;

void state_machine_setup() {
    current = DoorState::LOCKED;
    display_message(F("Cerradura bloqueada"));
}

DoorState get_door_state() {
    return current;
}

void state_machine_loop() {
    // La lógica real escucharía eventos; aquí sólo revisamos el Serial para detectar "PIN_OK".
    if (Serial.available()) {
        String line = Serial.readStringUntil('\n');
        line.trim();
        if (line == F("PIN_OK")) {
            if (current == DoorState::LOCKED) {
                current = DoorState::OPEN;
                door_open();
                display_message(F("Puerta abierta (PIN correcto)"));
            } else {
                current = DoorState::LOCKED;
                door_close();
                display_message(F("Puerta cerrada"));
            }
        }
    }
}
