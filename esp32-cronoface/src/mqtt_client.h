#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

void mqtt_setup(WiFiClient& wifiClient);
void mqtt_loop();
