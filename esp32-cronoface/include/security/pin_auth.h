#pragma once
#include <Arduino.h>

// PIN simple de 4 dígitos para abrir la cerradura.
static const char AUTH_PIN[] = "1234";

inline bool check_pin(const String& candidate) {
    return candidate == AUTH_PIN;
}
