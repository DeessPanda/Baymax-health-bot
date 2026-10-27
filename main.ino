#include <Wire.h>
#include <BluetoothSerial.h>
#include "MAX30105.h"      
#include "heartRate.h"
#include <Adafruit_MLX90614.h> 
#include <SPIFFS.h> // For local data logging

BluetoothSerial SerialBT;
MAX30105 particleSensor;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// --- ARCHITECTURE PLACEHOLDERS (Phase 2 & 3) ---
// #include <TFT_eSPI.h> // For onboard screen
// #include "esp_camera.h" // For camera vision
// #include <WiFi.h> // For Cloud AI API / Local LLM

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Baymax_Health_Bot"); 
  
  Wire.begin(21, 22); // SDA, SCL

  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 Error"); while (1);
  }
  particleSensor.setup(); 
  particleSensor.setPulseAmplitudeRed(0x0A); 

  if (!mlx.begin()) {
    Serial.println("MLX90614 Error"); while (1);
  }

  // Initialize Local Storage for Patient Logs
  if(!SPIFFS.begin(true)){
    Serial.println("SPIFFS Mount Failed");
  }
}

void loop() {
  float tempC = mlx.readObjectTempC();
  long irValue = particleSensor.getIR();
  
  // Simulated SpO2 and HR for architecture demonstration
  int heartRate = map(irValue, 50000, 100000, 60, 120); 
  int spO2 = 98; 

  // 1. DATA LOGGING (Save to internal memory)
  File file = SPIFFS.open("/vitals_log.csv", FILE_APPEND);
  if (file) {
    file.printf("%lu,%.2f,%d,%d\n", millis(), tempC, heartRate, spO2);
    file.close();
  }

  // 2. FORMAT AS JSON (For Web App / Phone Dashboard)
  String jsonPayload = "{\"hr\":" + String(heartRate) + 
                       ",\"spo2\":" + String(spO2) + 
                       ",\"temp\":" + String(tempC) + "}";
  
  SerialBT.println(jsonPayload);

  // --- FUTURE LOGIC PLACEHOLDERS ---
  // updateScreen(heartRate, tempC);  // Update onboard LCD
  // checkMovementSensors();          // Autonomous navigation logic
  // processVoiceCommand();           // Listen for "Hello Baymax"

  delay(2000); 
}
