//Libraries
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
Adafruit_BMP280 bmp; // I2C
int rainSense = 0; // analog sensor input pin 0


//Variables
float hum;  //Stores humidity value
float temp1; //Stores temperature value
float temp2; //Stores temperature value
float pressure; //Stores pressure value
float altitude; //Stores altitude value
float rainSenseReading; //Stores rain value

void setup()
{
  Serial.begin(9600);
  pinMode(rainSense, INPUT);
  dht.begin();
  if (!bmp.begin())
  {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}

void loop()
{
    delay(10000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp1 = dht.readTemperature();
    temp2 = bmp.readTemperature();
    pressure = (bmp.readPressure() / 100); // 100 Pa = 1 millibar
    altitude = bmp.readAltitude(1013.25);
    rainSenseReading = analogRead(rainSense);

    Serial.print("Humidity: ");
    Serial.println(+hum);
    Serial.print("Temperature1: ");
    Serial.println(temp1);
    Serial.print("Temperature2: ");
    Serial.println(temp2);
    Serial.print("Pressure: ");
    Serial.println(pressure);
    Serial.print("Altitude: ");
    Serial.println(altitude);
    Serial.print("RainSense: ");
    Serial.println(rainSenseReading);
    Serial.println("----------------------");

}
