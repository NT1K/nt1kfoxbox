# CW FOX BOX BY: NT1K

http://www.NT1K.com

My first project ever so give me a break

A simple project that allows you to turn your Arduino (or equiv) into a Beacon that could 
be used in "FoxHunting" or RDF when hooked up to a transceiver. The code will active the
PTT (Through the Speaker/Mic Jack), Send tones in CW/Morse Code through the mic input, Send
a solid tone (optional), de-active PTT and repeat. All can be adjusted in the code

## Materials Needed

+ 3 LEDS (Optional) 
+ 3 Resistors (For LEDs)
+ 1 Resistor (Value Unknown ATM)
+ 1 100mF Ceramic Cap (Not Sure ATM)
+ 1 4N34 Optoisolator (Could also use Relay)
+ 1 2.5mm MONO (TS) plug
+ 1 3.5mm Streao (TRS) plug
+ 1 SPST Push Button Switch (Normally Open)
+ 1 Arduino UNO (Or Equiv)

## Board layout

<img src="http://i.imgur.com/OH72Szq.jpg">

## Known Issues:

1: RF - When HT is transmitting, RF is distrubing the Arduino causing it to reset

2: Voltage in Audio - Noticible "hum" in audio

This is my first project involving programing and circuit design. If you make any changes please 
explain in detail how and why you made that change so others can learn. 
