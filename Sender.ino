#include <SPI.h>
#include <LoRa.h>

#define LORA_SCK  18
#define LORA_MISO 19
#define LORA_MOSI 23
#define LORA_CS   5
#define LORA_RST  14
#define LORA_IRQ  2

SPIClass spiLoRa(VSPI);

void setup() {
  Serial.begin(115200);
  delay(100);

  spiLoRa.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_CS);
  LoRa.setSPI(spiLoRa);
  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check wiring.");
    while (true);
  }

  Serial.println("Sending: HI");

  LoRa.beginPacket();
  LoRa.print("Hi");
  LoRa.endPacket();

  LoRa.sleep();

  esp_sleep_enable_timer_wakeup(30000000); // 30 seconds
  Serial.println("LoRa and ESP32 going to deep sleep for 30s...");
  delay(50);

  esp_deep_sleep_start();
}

void loop() {
  // Not used
}