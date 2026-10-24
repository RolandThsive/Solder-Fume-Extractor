#include <Arduino.h>

// ===== Pins =====
const int PWM_PIN = 7;   // PWM output to fan
const int POT_PIN = 2;   // Potentiometer input (ADC-capable pin on ESP32-C3)

// ===== PWM settings =====
const uint32_t PWM_FREQ = 25000;  // 25 kHz
const uint8_t  PWM_RES  = 8;      // 8-bit resolution (0..255)

const uint8_t MIN_DUTY_PERCENT = 5; // Minimum fan duty = 5%

void setup() {
  //Serial.begin(9600);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
  delay(500);
  // ADC configuration
  analogReadResolution(12);       // 0..4095
  analogSetAttenuation(ADC_11db); // ~0–3.6V

  // Use new LEDC API for Arduino-ESP32 3.x
  // ledcAttach(pin, freq, resolution)
  if (!ledcAttach(PWM_PIN, PWM_FREQ, PWM_RES)) {
    // Attach failed — hang (or handle error)
    while (true) {
      delay(1000);
    }
  }

  // Start with fan off
  ledcWrite(PWM_PIN, 0);
}

void loop() {
  int potValue = analogRead(POT_PIN);  // 0..4095
  int dutyMax  = (1 << PWM_RES) - 1;   // e.g. 255 for 8-bit
  int minDuty  = dutyMax * MIN_DUTY_PERCENT / 100;
  int duty     = map(potValue, 0, 4095, minDuty, dutyMax);
  //Serial.printf("Pot: %d, Duty: %d (%d%%)\n", potValue, duty, duty);
  ledcWrite(PWM_PIN, duty);

  delay(100);
}
