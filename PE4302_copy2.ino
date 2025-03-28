//esptool -p /dev/ttyUSB0 write_flash 0x00000  PE4302_eeprom2.bin

#include <EEPROM.h>

#define pin0 D0
#define pin1 D1
#define pin2 D2
#define pin3 D3
#define pin4 D4
#define pin5 D5
String val = "";
String attn = "";
float attn_f;
byte attn_b; 
byte eeprom_attn;
float last_attn;
void setup() {
 pinMode(pin0, OUTPUT);
 pinMode(pin1, OUTPUT);
 pinMode(pin2, OUTPUT);
 pinMode(pin3, OUTPUT); 
 pinMode(pin4, OUTPUT);
 pinMode(pin5, OUTPUT);  
 EEPROM.begin(1);
eeprom_attn = EEPROM.read(0);
set_pins(eeprom_attn);
Serial.begin(115200); 
             }
void loop() 
    {
  if (Serial.available() > 0) 
    {
val = Serial.readString();
if (val.indexOf("attn:") != -1)
{
attn = val.substring(5,10);
eeprom_attn = EEPROM.read(0);
last_attn = eeprom_attn / 2;
Serial.println("Read attn from eeprom: " + String(last_attn,1) + " dB " + "Set attn to: " + attn + "dB");
attn_f = attn.toFloat() * 2;
attn_b = attn_f;
set_pins(attn_b);
EEPROM.write(0, attn_b);
EEPROM.commit();
}
if (val.indexOf("get") != -1)
{
eeprom_attn = EEPROM.read(0);
last_attn = eeprom_attn / 2;
Serial.println("Current attn is: " + String(last_attn,1)+ " dB"); 
  }
    }
      }
    
    
void set_pins( byte argument)
{
if (bitRead(argument,0) == 1) { GPOS = (1 << pin0);}
else {GPOC = (1 << pin0);}
if (bitRead(argument,1) == 1) {GPOS = (1 << pin1);}
else {GPOC = (1 << pin1);}
if (bitRead(argument,2) == 1) {GPOS = (1 << pin2);}
else {GPOC = (1 << pin2);}
if (bitRead(argument,3) == 1) {GPOS = (1 << pin3);}
else {GPOC = (1 << pin3);}
if (bitRead(argument,4) == 1) {GPOS = (1 << pin4);}
else {GPOC = (1 << pin4);}
if (bitRead(argument,5) == 1) {GPOS = (1 << pin5);}
else {GPOC = (1 << pin5);}
}
