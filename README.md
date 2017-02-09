# ESP8266DM_RB
Firmware to be loaded to WiFi Bee ESP v1.0 module (DFROBOT) ESP8266 chipset 
using Arduino IDE. 

Relay board TOSR-04 (TinySine) will be used with default preset firmware (protocol) in its ATMEL MEGA328P chipset. 

Implemented HTTP server with buttons for manual relay control. 

URI = "/FF" + relay number + command. 

Relay numbers: 00 = all ; 01 = 1st ; 02 = 2nd ; 03 = 3rd ; 04 = 4th.

Commands: 00 = turn off ; 01 = turn on ; 02 = swap state.

Swap all is not supported.

Example command: http://1.1.1.1/FF0101
