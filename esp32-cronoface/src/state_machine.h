#pragma once
#include <Arduino.h>

enum class DoorState {
    IDLE,
    OPEN,
    LOCKED
};

void state_machine_setup();
void state_machine_loop();
DoorState get_door_state();
