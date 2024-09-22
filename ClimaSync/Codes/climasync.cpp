#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <DHT.h>
#include <Adafruit_I2CDevice.h>

#define DHTTYPE DHT11
#define DHTPIN  6

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 =4, d7 = 5;

int button_pin = 7;

int led_blue = 10;
int led_green = 9;
int led_red = 8;


DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void printing(float humidity, float temperature){
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("\n");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("\n");

}

void lcd_printing(float humidity, float temperature) {
    lcd.clear();  // Clear the display to refresh the content
    lcd.setCursor(0, 0);  // Set the cursor to the first line, first position
    lcd.print("H: ");
    lcd.print(humidity);
    lcd.print("%   ");    // Ensures to overwrite old data

    lcd.setCursor(0, 1);  // Set the cursor to the second line, first position
    lcd.print("T: ");
    lcd.print(temperature);
    lcd.print("C   ");    // Add units and clear remaining space
}

void setup(){
    pinMode(led_red, OUTPUT);
    pinMode(led_blue, OUTPUT);
    pinMode(led_green, OUTPUT);
    Serial.begin(9600);
    dht.begin();
    lcd.begin(16,2);
    pinMode(button_pin, INPUT);
}

void loop() {
    int button_state = digitalRead(button_pin);

    if (button_state == 1){
    
        float humidity = dht.readHumidity();

        float temperature = dht.readTemperature(false);

        if (isnan(humidity) || isnan(temperature)){
            Serial.println("Failed to read data.");
            return;
        }

        if (humidity >= 70.0 || temperature >= 30.0){
            analogWrite(led_red, 255);
            analogWrite(led_blue, 0);
            analogWrite(led_green, 0);
            printing(humidity, temperature);
            lcd_printing(humidity, temperature);

        }

        else if (humidity >= 40.0 || temperature >= 25.0){
            analogWrite(led_red, 240);
            analogWrite(led_blue, 255);
            analogWrite(led_green, 103);
            printing(humidity, temperature);
            lcd_printing(humidity, temperature);
        }
        else if (humidity < 40.0 || temperature < 25.0){
            analogWrite(led_red, 0);
            analogWrite(led_blue, 0);
            analogWrite(led_green, 255);
            printing(humidity, temperature);
            lcd_printing(humidity, temperature);
    }



    }
    else{
        Serial.print("Please press the button to read data:");
        Serial.print(button_state);
        Serial.print("\n");
        lcd.clear();
        analogWrite(led_red, 0);
        analogWrite(led_blue, 0);
        analogWrite(led_green, 0);
    }   
    delay(2000);
}


