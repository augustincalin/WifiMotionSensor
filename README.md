# Wireless Motion Sensor

This is a project for creating a Wireless Motion Sensor.  
It contains the code for the motion sensor and for the web server.  

## Materials required
- PIR
- ESP-01 (the black one)
- NodeMCU
- LED, resistor
- power source for 3,3V and 5V
- power adapter 220V --> power source above
- USB-COM adapter for writing the code to ESP-01

## Description
You will need Arduino IDE to write the code to ESP-01 and to NodeMCU.
The sensor is just half wireless because finding a solution for powering from batteries it's more difficult.  
The PIR detects the movement and sends the signal to ESP-01. This will call a GET hosted on NodeMCU. The web server hosted by NodeMCU will lit a LED.
The PIR is connected to 5V, the ESP-01 to 3,3, while the NodeMCU can be powered by laptop or a phone adapter.
The NodeMCU is set from the wifi router to a fixed IP, so that the ESP-01 will know which address to call (in case of a movement).

## Lessons learned
1. Pay attention to the USB cable between your laptop and USB Serial Adapter. Some cables are not working.
2. The ESP-01 works in 2,4 GHz, WPA. Is not working with WPA2!
3. If you don't know how to solder, don't do it! It will burn your circuit!
4. If you place the ESP-01 too close to PIR, the last one will detect movement even if placed under a cup. Looks like some interference.


