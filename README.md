# SE_12

## Introduction
This project is a small IoT device that is able to change the state of a smart home lamp over the internet with an IoT application provider such as IFTTT.

## Hardware Requirements

- Arduino Uno
- NodeMCU ESP8266-12E
- 16x2 LCD Display
- Breadboard
- 2 x buttons
- 2 x 220ohm resistors
- 4 x female to male jumper wires
- ~30 x male to male jumper wires

## Setup

![image](https://user-images.githubusercontent.com/36240574/118476273-952acc80-b70d-11eb-9197-fa92c2045ff6.png)

After connecting all components correctly, the two .ino files need to be uploaded to the arduino (arduino.ino) and the esp(wifi_programmer.ino) respectively.

### ESP

The ESP module needs further setup of your IDE as described in this tutorial -> https://create.arduino.cc/projecthub/electropeak/getting-started-w-nodemcu-esp8266-on-arduino-ide-28184f

You also have to enter your wifi name and password and the correct HTTP endpoint to trigger the smart lamps

### Arduino

Since we controll the LCD display with this application, we also need to add the LiquidCristal library as explained here -> https://www.arduino.cc/en/guide/libraries
