# PE4302_attenuator
PE4302 and ESP8266
Sketch for ArduinoIDE to control PE4302 attenuator from ESP8266 via USB connection.
Use "attn.py get" to get current value of attenuator
User attn.py 10.0" to set 10.0 dB attenuation.
Current value of attenuation is stored in EEPROM of ESP8266 and will restore after power failure.
