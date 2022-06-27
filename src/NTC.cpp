#include "NTC.h"

 
  NTC :: NTC(char _SENSOR_PIN , float _B_VALUE , float _NOMINAL_TEMPERATURE ,float _R_Series ,float _NTC_R , 
            float _REF_Volt , float _VCC_series_resistor , int _Number_Read , float _Resolution)
  {
    SENSOR_PIN = _SENSOR_PIN;                                 //sensor connect to ADC pin
    B_VALUE = _B_VALUE;                                       //coefficient for read temp
    NOMINAL_TEMPERATURE = _NOMINAL_TEMPERATURE + 273.15;      //for change Temp to kelvin
    
    R_Series = _R_Series;                                     //value resistor series
    NTC_R = _NTC_R;                                           //value sensor resistor on 25 degree centigrade
    
    REF_Volt=_REF_Volt;                                       //for change reference voltage
    VCC_series_resistor = _VCC_series_resistor;               //change voltage VCC on series resistor
    
    if(_Number_Read<1)
      Number_Read = 1;                                        //number of read ADC pin for mid filter
    else
      Number_Read = _Number_Read;                             //number of read ADC pin for mid filter
    Resolution = _Resolution;                                 //resolution microcontroller  10bit - > 1024 and 12bit 4096
  }

  NTC :: NTC(char _SENSOR_PIN , float _B_VALUE , float _NOMINAL_TEMPERATURE ,float _R_Series ,float _NTC_R , 
            float _REF_Volt , float _VCC_series_resistor)
  {
    SENSOR_PIN = _SENSOR_PIN;                                 //sensor connect to ADC pin
    B_VALUE = _B_VALUE;                                       //coefficient for read temp
    NOMINAL_TEMPERATURE = _NOMINAL_TEMPERATURE + 273.15;      //for change Temp to kelvin
    
    R_Series = _R_Series;                                     //value resistor series
    NTC_R = _NTC_R;                                           //value sensor resistor on 25 degree centigrade
    
    REF_Volt=_REF_Volt;                                       //for change reference voltage
    VCC_series_resistor = _VCC_series_resistor;               //change voltage VCC on series resistor
  }

  NTC :: NTC(char _SENSOR_PIN , float _B_VALUE , float _NOMINAL_TEMPERATURE ,float _R_Series ,float _NTC_R)
  {
    SENSOR_PIN = _SENSOR_PIN;                                 //sensor connect to ADC pin
    B_VALUE = _B_VALUE;                                       //coefficient for read temp
    NOMINAL_TEMPERATURE = _NOMINAL_TEMPERATURE + 273.15;      //for change Temp to kelvin
    
    R_Series = _R_Series;                                     //value resistor series
    NTC_R = _NTC_R;                                           //value sensor resistor on 25 degree centigrade
  }

//-----------------------------------------------------------------------------------------------------------------------
  
  float NTC :: read_value_adc(char _SENSOR_PIN , int _Number_Read)
  {
    int i=0;
    float ADC_READ=0;
    
    if(_Number_Read<1)
      Number_Read = 1;
    else
      Number_Read = _Number_Read;

    SENSOR_PIN = _SENSOR_PIN;
    
    for(i=0;i<Number_Read;i++)
      ADC_READ += analogRead(SENSOR_PIN);
    ADC_READ = ADC_READ/Number_Read;
    return ADC_READ;
  }
  float NTC :: read_value_adc()
  {
    int i=0;
    float ADC_READ=0;
    
    for(i=0;i<Number_Read;i++)
      ADC_READ += analogRead(SENSOR_PIN);
    ADC_READ = ADC_READ/Number_Read;
    return ADC_READ;
  }
//-----------------------------------------------------------------------------------------------------------------------

 
  float NTC :: read_voltage_NTC_Sensor(float _Resolution , float _REF_Volt , char _SENSOR_PIN , int _Number_Read)
  {
    Resolution = _Resolution;
    REF_Volt = _REF_Volt;
    float Voltage_NTC_Resistor=0;
    Voltage_NTC_Resistor = (REF_Volt / Resolution) * read_value_adc(_SENSOR_PIN , _Number_Read);  //Conversion to voltage
    return Voltage_NTC_Resistor;
  }
  float NTC :: read_voltage_NTC_Sensor()
  {
    float Voltage_NTC_Resistor=0;
    Voltage_NTC_Resistor = (REF_Volt / Resolution) * read_value_adc();                            //Conversion to voltage
    return Voltage_NTC_Resistor;
  }
//-----------------------------------------------------------------------------------------------------------------------

  
  float NTC :: NTC_resistor()
  {
    float voltage_NTC = read_voltage_NTC_Sensor();
    float NTC_Resistor=0;
    
    Voltage_on_series_resistor = VCC_series_resistor - voltage_NTC;
    NTC_Resistor = voltage_NTC / (Voltage_on_series_resistor / R_Series);                     

    return NTC_Resistor;
  }
//-----------------------------------------------------------------------------------------------------------------------

  
  float NTC :: Temperature_K()
  {
    float Temp=0 , ln=0;
    ln = log(NTC_resistor() / NTC_R);
    Temp = (1 / ((ln / B_VALUE) + (1 / NOMINAL_TEMPERATURE)));                      //Temperature from thermistor
    return Temp;
  }
//-----------------------------------------------------------------------------------------------------------------------

  float NTC :: Temperature_C()
  {
    float Temp=0;
    Temp = Temperature_K() - 273.15;
    return Temp;
  }
