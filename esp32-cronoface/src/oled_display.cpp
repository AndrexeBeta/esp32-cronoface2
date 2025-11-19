#include "oled_display.h"

void display_setup() {
    // Para simplificar, solo inicializamos Serial para mostrar mensajes.
    // En un proyecto real se usaría un driver I2C para la pantalla.
}

void display_message(const String& msg) {
    Serial.print(F("[DISPLAY] "));
    Serial.println(msg);
}
