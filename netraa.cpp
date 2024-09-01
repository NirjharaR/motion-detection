#include <esp_camera.h>
#include <WiFi.h>
#include "config.h"

// PIR sensor settings
#define PIR_PIN 13
#define LED_PIN 4

bool motionDetected = false;

// Camera settings
void setupCamera() {
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = 5;
    config.pin_d1 = 18;
    config.pin_d2 = 19;
    config.pin_d3 = 21;
    config.pin_d4 = 36;
    config.pin_d5 = 39;
    config.pin_d6 = 34;
    config.pin_d7 = 35;
    config.pin_xclk = 0;
    config.pin_pclk = 22;
    config.pin_vsync = 25;
    config.pin_href = 23;
    config.pin_sscb_sda = 26;
    config.pin_sscb_scl = 27;
    config.pin_pwdn = 32;
    config.pin_reset = -1;
    config.pin_xclk = 0;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;

    if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
    } 
    else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
    }

    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    
    setupCamera();
    
  // Connect to Wi-Fi
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println("WiFi connected");
}

void loop() {
    motionDetected = digitalRead(PIR_PIN);
    
    if (motionDetected) {
        digitalWrite(LED_PIN, HIGH);
    
    // Capture Image
    camera_fb_t * fb = NULL;
    fb = esp_camera_fb_get();
    if (!fb) {
        Serial.println("Camera capture failed");
        return;
    }
    
    // Save the image or send to server
    // Implement image processing or transmission logic here
    
    esp_camera_fb_return(fb);
    digitalWrite(LED_PIN, LOW);
    
    delay(10000); // Delay to avoid multiple captures
    }
}
