# Smart Medicine Reminder Box

A smart IoT-enabled medicine reminder system that helps users stay on top of their medication schedule using an ESP32 microcontroller, Blynk app integration, and visual/audio alerts.

## Features

✅ **Automated Medicine Reminders** - Set and receive reminders for medication schedules
✅ **LCD Display** - 16x2 I2C LCD display showing medicine names and status
✅ **Audio-Visual Alerts** - LED indicator and buzzer alarm when it's time to take medicine
✅ **Remote Control** - Control through Blynk mobile app from anywhere
✅ **User Confirmation** - Button to confirm when medicine is taken
✅ **WiFi Connectivity** - ESP32 WiFi integration with Blynk cloud

## Hardware Requirements

- **ESP32** microcontroller
- **16x2 LCD Display** (I2C compatible, address 0x27)
- **LED** (GPIO 18)
- **Buzzer** (GPIO 19)
- **Push Button** (GPIO 23)
- **WiFi Network** for Blynk connectivity

## Dependencies & Libraries

The project uses the following Arduino libraries:

- **Blynk** - IoT platform for remote application control
- **LiquidCrystal I2C** - LCD display control via I2C
- **WiFi** - ESP32 WiFi connectivity (built-in)
- **Wire** - I2C communication protocol (built-in)

## Setup Instructions

### 1. Hardware Connection

```
ESP32 Pin Layout:
- GPIO 18 → LED (via resistor)
- GPIO 19 → Buzzer
- GPIO 23 → Push Button
- SDA (GPIO 21) → LCD I2C SDA
- SCL (GPIO 22) → LCD I2C SCL
- GND → GND
- 5V → LCD VCC, LED+, Buzzer+
```

### 2. Software Setup

1. Install Arduino IDE
2. Add ESP32 board support:
   - File → Preferences → Additional Boards Manager URLs
   - Add: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Tools → Board Manager → Search "esp32" → Install

3. Install required libraries:
   - Sketch → Include Library → Manage Libraries
   - Search and install: "Blynk", "LiquidCrystal I2C"

### 3. Blynk Configuration

1. Download Blynk app (iOS/Android)
2. Create a new project in Blynk
3. Select ESP32 as device
4. Copy the authentication token
5. Update these values in the code:
   ```cpp
   #define BLYNK_TEMPLATE_ID "TMPL3ZmegDrr7"
   #define BLYNK_TEMPLATE_NAME "Medicine Reminder"
   #define BLYNK_AUTH_TOKEN "vrs5xDX-YuNOKDh7et4ef57cJ9mt5wto"
   ```

### 4. WiFi Configuration

Update WiFi credentials in the sketch:
```cpp
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";
```

### 5. Upload Sketch

1. Connect ESP32 via USB
2. Select Tools → Port → COM (your device)
3. Tools → Board → ESP32
4. Upload the sketch (Sketch → Upload or Ctrl+U)

## How to Use

1. **Power On** - Connect ESP32 to power
2. **Wait for Connection** - Device connects to WiFi and Blynk cloud
3. **Set Reminders** - Use Blynk app to schedule medicine reminders
4. **Receive Alerts** - LCD displays medicine name when reminder triggers
5. **Alarm Sounds** - LED flashes and buzzer sounds as notification
6. **Confirm** - Press button or tap Blynk to confirm medicine taken
7. **Status Display** - LCD shows "Medicine Taken" confirmation

## Pin Configuration

| Component | GPIO Pin | Function |
|-----------|----------|----------|
| LED | 18 | Visual indicator |
| Buzzer | 19 | Audio alert |
| Button | 23 | User confirmation |
| LCD SDA | 21 | I2C Data (built-in) |
| LCD SCL | 22 | I2C Clock (built-in) |

## Wokwi Simulation

This project can be simulated on [Wokwi](https://wokwi.com/):
- Download from: https://wokwi.com/projects/460445008875769857
- Test the circuit and code without physical hardware
- Perfect for learning and prototyping

## Project Structure

```
Smart Medicine Reminder Box/
├── sketch.ino           # Main Arduino sketch
├── diagram.json         # Circuit diagram (Wokwi format)
├── libraries.txt        # Required libraries list
├── wokwi-project.txt    # Wokwi project reference
└── README.md           # This file
```

## Code Highlights

### Main Functions

- **triggerAlarm()** - Activates LED, buzzer, and LCD display
- **stopAlarm()** - Stops alarm and shows confirmation message
- **setup()** - Initializes hardware and Blynk connection
- **loop()** - Main program loop with Blynk timer

### Customization

You can modify:
- Medicine names and schedules
- Alert duration and frequency
- Display messages
- GPIO pins for different devices
- Buzzer frequency

## Troubleshooting

**LCD not displaying:**
- Check I2C address (typically 0x27 or 0x3F)
- Verify SDA/SCL connections
- Use I2C scanner to confirm address

**Blynk not connecting:**
- Verify WiFi credentials
- Check authentication token
- Ensure ESP32 has internet access
- Monitor Serial output for errors

**Alarm not triggering:**
- Verify GPIO pins match your circuit
- Check buzzer polarity
- Test with Serial.println() for debugging

## Security Note

⚠️ **Important:** The authentication token and WiFi credentials in this sketch are examples. 
- Never commit real credentials to public repositories
- Use environment variables or secure configuration files
- Regenerate tokens if repository is public

## License

This project is open source and available for educational and personal use.

## Contributing

Feel free to fork, modify, and improve this project!

---

**Author:** Aarthi  
**Last Updated:** April 2026  
**Repository:** https://github.com/Aarthi198/Smart-medicine-remainder-box
