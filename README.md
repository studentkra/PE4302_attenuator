# PE4302_attenuator
PE4302 and ESP8266

![PE4302_pic](https://github.com/user-attachments/assets/929d80d2-3979-4085-9cbc-4bddab69d525)

Sketch for ArduinoIDE to control PE4302 attenuator from ESP8266 via USB connection.

In Linux system:

Use "python attn.py get" to get current value of attenuator

User "python attn.py 10.0" to set 10.0 dB attenuation.

Current value of attenuation is stored in EEPROM of ESP8266 and will restore after power failure.
