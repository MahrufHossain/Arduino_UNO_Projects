#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <SPI.h>
#include <DHT.h>
#include <Adafruit_I2CDevice.h>



const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 =4, d7 = 5;


int led_blue = 10;
int led_green = 9;
int led_red = 8;
int water_sensor_pin = A0;



LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void lcd_printing() {
    lcd.clear();  // Clear the display to refresh the content
    lcd.setCursor(0, 0);
}

void setup(){
    pinMode(led_red, OUTPUT);
    pinMode(led_blue, OUTPUT);
    pinMode(led_green, OUTPUT);
    Serial.begin(9600);
    lcd.begin(16,2);
    pinMode(water_sensor_pin, OUTPUT);
}

void loop() {
    
    float water_lvl = analogRead(water_sensor_pin);
    float water_lvl_mapped = map(water_lvl, 0, 435, 0, 100);


    if (water_lvl_mapped >= 85.0){
        analogWrite(led_red, 255);
        analogWrite(led_blue, 0);
        analogWrite(led_green, 0);
        Serial.println("LVL: HIGH");
        lcd_printing();
        lcd.print("LVL: HIGH");
    }

    else if (water_lvl_mapped >= 60.0 && water_lvl_mapped < 85.0){
        analogWrite(led_red, 0);
        analogWrite(led_blue, 255);
        analogWrite(led_green, 0);
        Serial.println("LVL: MEDIUM");
        lcd_printing();
        lcd.print("LVL: MEDIUM");
    }
    else if (water_lvl_mapped < 60.0){
        analogWrite(led_red, 0);
        analogWrite(led_blue, 0);
        analogWrite(led_green, 255);
        Serial.println("LVL: LOW");
        lcd_printing();
        lcd.print("LVL: LOW");
    }

    delay(1000);
}


