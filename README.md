# 📡 LoRa ESP32 Point-to-Point Communication

This project demonstrates a simple **point-to-point LoRa network** using two ESP32 boards with SX1278 LoRa modules. One board acts as a **sender**, the other as a **receiver**. It uses the LoRa protocol on the **433 MHz band** for low-power wireless data transmission.

## 📦 Project Structure

lora-esp32-point-to-point/

├── sender/
│   └── sender.ino        # Sends “Hi” then sleeps

├── receiver/
│   └── receiver.ino      # Continuously listens for packets

└── README.md             # Project documentation
---

## 📡 Overview

- **Sender**: Transmits `"Hi"` over LoRa and enters **deep sleep** for 30 seconds to conserve power.
- **Receiver**: Continuously listens and prints incoming messages over Serial.

This setup is ideal for **low-power, long-range IoT communication** in non-LoRaWAN scenarios, such as simple environmental sensors, alarms, or remote control systems.

---

## 🛠 Hardware Used

- 2x ESP32 Development Boards
- 2x LoRa SX1278 Modules (433 MHz)
- Jumper wires / breadboard / power source

---

## 🔌 Wiring (ESP32 ↔ SX1278)

| Pin       | ESP32 Sender | ESP32 Receiver |
|-----------|--------------|----------------|
| NSS / SS  | GPIO 5       | GPIO 5         |
| RST       | GPIO 14      | GPIO 14        |
| DIO0 / IRQ| GPIO 2       | GPIO 2         |
| MOSI      | GPIO 23      | default        |
| MISO      | GPIO 19      | default        |
| SCK       | GPIO 18      | default        |

> Note: Sender uses `VSPI` with custom `SPIClass`, receiver uses default SPI.

---

## 🧪 Example Output

**Receiver Serial Monitor:**

Receiver ready.
Listening for packets...
Received: Hi

Sending: HI
LoRa and ESP32 going to deep sleep for 30s...

> Note: This allows the node to wake up periodically, send data, then go back to sleep — useful for battery-powered sensors.
