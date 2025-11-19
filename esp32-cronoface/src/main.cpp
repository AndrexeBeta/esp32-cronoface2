#include <Arduino.h>
#include <WiFi.h>

#include "door_control.h"
#include "keypad_input.h"
#include "mqtt_client.h"
#include "oled_display.h"
#include "state_machine.h"
#include "face_logic.h"

// Ajusta estas credenciales si quieres probar conexión WiFi real.
const char* WIFI_SSID = "";
const char* WIFI_PASS = "";

WiFiClient wifiClient;

void connectWifi() {
    if (strlen(WIFI_SSID) == 0) {
        Serial.println(F("WiFi desactivado (SSID vacío)."));
        return;
    }
    Serial.printf("Conectando a %s...", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    uint8_t retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < 20) {
        delay(500);
        Serial.print('.');
        retries++;
    }
    Serial.println();
    if (WiFi.status() == WL_CONNECTED) {
        Serial.print(F("WiFi conectado, IP: "));
        Serial.println(WiFi.localIP());
    } else {
        Serial.println(F("No se pudo conectar a WiFi."));
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println(F("Cronoface_Cerradura - build de Jenkins"));

    door_control_setup();
    init_keypad();
    display_setup();
    face_logic_setup();
    state_machine_setup();

    connectWifi();
    mqtt_setup(wifiClient);
}

void loop() {
    read_keypad_input();
    face_logic_loop();
    state_machine_loop();
    mqtt_loop();
    delay(10);
}
