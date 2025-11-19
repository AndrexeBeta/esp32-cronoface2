#include "mqtt_client.h"

static PubSubClient* clientPtr = nullptr;

// Configuración de ejemplo, se puede cambiar en el código fuente.
static const char* MQTT_BROKER = "test.mosquitto.org";
static const uint16_t MQTT_PORT = 1883;
static const char* MQTT_TOPIC  = "cronoface/events";

void mqtt_setup(WiFiClient& wifiClient) {
    static PubSubClient client(wifiClient);
    clientPtr = &client;
    client.setServer(MQTT_BROKER, MQTT_PORT);
}

void mqtt_loop() {
    if (!clientPtr) return;
    auto& client = *clientPtr;
    if (!client.connected()) {
        client.connect("cronoface-device");
    }
    client.loop();
}
