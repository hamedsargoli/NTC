/**
 * @file       NTC.cpp
 * @author     Hamed Sargoli
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2022 Hamed Sargoli
 * @date       2022/06/27
 * @brief      Read Temperature from NTC Sensor and compatable change reference voltage ADC and VCC Series Resistor ...
 * 
 * parameter Programable
 * @param _SENSOR_PIN sensor connect adc pin
 * @param _B_VALUE coefficient for read NTC (3000~5000)
 * @param _NOMINAL_TEMPERATURE Temperature Room (25+273.15) in kelvin
 * @param _R_Series Ω Series Resistance
 * @param _NTC_R Ω Sensor Resistance
 * @param _REF_Volt Voltage Reference micro controller (5V or 2.5V or ...) 
 * @param _VCC_series_resistor  Vcc connect to series Resistor (VCC|-----/\/\/\-----NTC----|||)
 * @param _Number_Read  Number for mid filter
 * @param _Resolution Resolution micro controller
 */
 

#ifndef NTC_h
#define NTC_h

#include <ARDUINO.h>

class NTC
{
  private:
    float Voltage_on_series_resistor=0;                           //Voltage on Series Resistor

  public:
    //default Value
    char SENSOR_PIN=0;                                            //Sensor ADC PIN
    float B_VALUE = 3977;                                         // 3000~5000
    float NOMINAL_TEMPERATURE=25+273.15;                          //Nominal Temp
    float R_Series = 10000;                                       //Ω  Series Resistance
    float NTC_R = 10000;                                          //Ω  Sensor Resistance
    float REF_Volt = 5;                                           //Voltage Reference 
    float VCC_series_resistor=5;                                  //Vcc for connect to series Resistor
    int Number_Read=1;                                            //Number for mid filter
    float Resolution = 1024.00;                                   //Resolution 10bit
    
    
    /**
    * initialize Class
    * 
    * @param _SENSOR_PIN sensor connect adc pin
    * @param _B_VALUE coefficient for read NTC (3000~5000)
    * @param _NOMINAL_TEMPERATURE Temperature Room (25+273.15) in kelvin
    * @param _R_Series Ω Series Resistance
    * @param _NTC_R Ω Sensor Resistance
    * @param _REF_Volt Voltage Reference micro controller (5V or 2.5V or ...) 
    * @param _VCC_series_resistor  Vcc connect to series Resistor (VCC|-----/\/\/\-----NTC----|||)
    * @param _Number_Read  Number for mid filter
    * @param _Resolution Resolution micro controller
    */
    NTC(char _SENSOR_PIN , float _B_VALUE , float _NOMINAL_TEMPERATURE ,float _R_Series ,float _NTC_R , 
        float _REF_Volt , float _VCC_series_resistor , int _Number_Read , float _Resolution){}
    
    /**
    * initialize Class
    * 
    * @param _SENSOR_PIN sensor connect adc pin
    * @param _B_VALUE coefficient for read NTC (3000~5000)
    * @param _NOMINAL_TEMPERATURE Temperature Room (25+273.15) in kelvin
    * @param _R_Series Ω Series Resistance
    * @param _NTC_R Ω Sensor Resistance
    * @param _REF_Volt Voltage Reference micro controller (5V or 2.5V or ...) 
    * @param _VCC_series_resistor  Vcc connect to series Resistor (VCC|-----/\/\/\-----NTC----|||)
    * @param _Number_Read = 1 default  
    * @param _Resolution = 1024.00 default
    */
    NTC(char _SENSOR_PIN , float _B_VALUE , float _NOMINAL_TEMPERATURE ,float _R_Series ,float _NTC_R ,
        float _REF_Volt , float _VCC_series_resistor){}
    
    /**
    * initialize Class
    * 
    * @param _SENSOR_PIN sensor connect adc pin
    * @param _B_VALUE coefficient for read NTC (3000~5000)
    * @param _NOMINAL_TEMPERATURE Temperature Room (25+273.15) in kelvin
    * @param _R_Series Ω Series Resistance
    * @param _NTC_R Ω Sensor Resistance
    * @param _REF_Volt = 5
    * @param _VCC_series_resistor = 5
    * @param _Number_Read = 1 default  
    * @param _Resolution = 1024.00 default
    */
    NTC(char _SENSOR_PIN , float _B_VALUE , float _NOMINAL_TEMPERATURE ,float _R_Series ,float _NTC_R){}
    //-----------------------------------------------------------------------------------------------------------------------


    /**
    * read adc
    * 
    * @param _SENSOR_PIN sensor connect adc pin
    * @param _Number_Read  Number for mid filter
    * 
    * @return This function read adc pin and filter median output
    */
    float read_value_adc(char _SENSOR_PIN , int _Number_Read){}

    /**
    * read adc
    * 
    * @param _SENSOR_PIN = 0
    * @param _Number_Read = 1
    * 
    * @return This function read adc pin
    */
    float read_value_adc(){}
    //-----------------------------------------------------------------------------------------------------------------------


    /**
    * This function calculate voltage on sensor
    * 
    * @param _SENSOR_PIN sensor connect adc pin
    * @param _REF_Volt Voltage Reference micro controller (5V or 2.5V or ...) 
    * @param _Number_Read  Number for mid filter
    * @param _Resolution Resolution micro controller
    * 
    * @return This function calculate voltage on sensor
    */
    float read_voltage_NTC_Sensor(float _Resolution , float _REF_Volt , char _SENSOR_PIN , int _Number_Read){}
    
    /**
    * This function calculate voltage on sensor
    * 
    * @param _SENSOR_PIN = 0
    * @param _REF_Volt = 5
    * @param _Number_Read = 1 
    * @param _Resolution = 1024.00
    * 
    * @return This function calculate voltage on sensor
    */
    float read_voltage_NTC_Sensor(){}
    //-----------------------------------------------------------------------------------------------------------------------
    
    
    /**
    * This function Calculate resistor sensor
    * 
    * @return resistor NTC
    */
    float NTC_resistor(){}
    //-----------------------------------------------------------------------------------------------------------------------
    

   /**
    * This function Calculate Temperature in Kelvin
    * 
    * @return Temperature
    */
    float Temperature_K(){}
    //-----------------------------------------------------------------------------------------------------------------------
    
    
    /**
    * This function Calculate Temperature in Celsius
    * 
    * @return Temperature_K() - 273.15 (float)
    */
    float Temperature_C(){}

};//end class

#endif