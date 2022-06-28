/*
  Average NTC Thermistor

  Reads a temperature from the NTC thermistor
  and displays it in the default Serial.

  https://github.com/hamedsargoli/NTC

  Created by Hamed Sargoli, 2022/06/28.
  Released into the public domain.
*/
#include <NTC.h>


#define SENSOR_PIN            A1               //Sensor ADC PIN
#define B_VALUE               3977             // 3000~5000
#define NOMINAL_TEMPERATURE   25               //Nominal Temp
#define R_Series              10000            //Ω  Series Resistance
#define NTC_R                 10000            //Ω  Sensor Resistance
#define REF_Volt              5                //Voltage Reference 
#define VCC_series_resistor   5                //Vcc for connect to series Resistor
#define Number_Read           100              //Number for Average filter
#define Resolution            1024.00          //Resolution 10bit



float Temp=0;

NTC NTC_Sensor(SENSOR_PIN , B_VALUE , NOMINAL_TEMPERATURE , R_Series , NTC_R , REF_Volt , VCC_series_resistor , Number_Read , Resolution);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  Temp = NTC_Sensor.Temperature_C();

  const double celsius = NTC_Sensor.Temperature_C();
  const double kelvin = NTC_Sensor.Temperature_K();

  // Output of information
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(kelvin);
  Serial.print(" K, ");
  
  delay(1000); // optionally, only to delay the output of information in the example.
}
