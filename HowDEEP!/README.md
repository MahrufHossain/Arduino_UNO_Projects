# Water Level Monitoring System 🚰

This Arduino project monitors the water level using a water sensor and displays the current water level (High, Medium, or Low) on an LCD screen. It also uses LEDs to indicate the water level visually. This system can be used in water tanks, reservoirs, or any application where monitoring the water level is important.

## Features 🌟
- **Water Sensor**: Reads the water level and maps it to a percentage value.
- **LED Indicators**: 
  - **Red LED**: Indicates **High** water level (≥ 85%).
  - **Blue LED**: Indicates **Medium** water level (60% - 84%).
  - **Green LED**: Indicates **Low** water level (< 60%).
- **LCD Display**: Shows the current water level as "HIGH," "MEDIUM," or "LOW."
- **Serial Monitor**: Prints the water level status for debugging purposes.

## Components Required 🛠️
- Arduino Uno
- Water Sensor (Analog output)
- 3 LEDs (Red, Blue, Green)
- Resistors for LEDs (220Ω)
- 16x2 LCD Display
- Jumper Wires
- Breadboard

## Circuit Diagram 🔌
Include the circuit diagram here (e.g., with Fritzing or a hand-drawn schematic).
 - Not yet included

## Code Explanation 💻

### Key Functions:
- `lcd_printing()`: Clears and sets up the LCD to print the current water level.
- **Water Level Detection**: The system reads the analog value from the water sensor (on `A0`), maps it to a percentage (0 - 100%), and updates both the LCD and the LED indicators based on the water level.

### LED Control Logic:
- **Water level ≥ 85%**: Red LED lights up, LCD displays "LVL: HIGH."
- **60% ≤ Water level < 85%**: Blue LED lights up, LCD displays "LVL: MEDIUM."
- **Water level < 60%**: Green LED lights up, LCD displays "LVL: LOW."

### Code Snippet:
```cpp
float water_lvl = analogRead(water_sensor_pin);
float water_lvl_mapped = map(water_lvl, 0, 435, 0, 100);
```

#### Note: The water sensor's maximum value is mapped to 435, based on sensor calibration.


## Installation and Usage 📖
 - Clone or download the repository.
 - Upload the provided code to your Arduino board using the Arduino IDE.
 - Connect the components as per the circuit diagram.
 - Open the Serial Monitor to view real-time water level status.

## Future Improvements 🚀
 - Add a buzzer to alert when water levels are too high or low.
 - Implement data logging to track water levels over time.
 - Optimize the pin usage by using an I2C interface for the LCD display.


## License 📄
This project is licensed under the GNU License. Feel free to use, modify, and share!

## Contact 📧
 - GitHub: [MahrufHossain](https://github.com/MahrufHossain)
 - Email:  mahrufhossain97@gmail.com