# CS207FinalProject-Robo Garden
This is an Arduino controlled plant growth system

**AIM OF PROJECT**

A fully automated plant growth system with watering (based on soil moisture content), temperature control and lights. The final goal of this project is to create a system that could fully grow a plant without any additional outside input. The most important control is water (because light and temperature can be controlled simply by putting the plant near a window). The project is easily scalable and can accomodate more soil moisture sensors and/or temperature control units. 

**Repository Contents*

/README.md -ReadMe document explaining the build
/hardware - Fritzing schematic for build
/Code - Archived previous versions of code
/

**BUILD**
Quick Instructions

Relay VCC to board 5V
Relay GND to GND
Relay 1 common to 5V
Relay 1 NO to Pump 5V
Relay 2 common to 5V
Relay 2 NO to DC fan

Pin 2 to relay IN1
Pin 3 to relay IN2
Pin 13 to float pump 

Soil moisture(SM) VCC to 5V
SM GND to GND
SM AOUT to A0

TMP 5V to 5V
TMP GND to GND
TMP analog (middle pin) to A1

Extended Instructions

Analog Pins


Relay Board


**FUNCTIONALITY**

Version 2.0: Working pump and float sensor

Version 3.0: Most experimenting was done with this version. Attempted to use all commands as functions. Moisture sensor and pump work well but modules do not interface properly. 

Version 4.0: Moisture control and temperature control work smoothly together. 

**HARDWARE**

1 X Arduino Uno board
1 X 4 channel relay
1 X Soil moisture sensor
1 X DC pump
1 X Hose
1 X Water reservoir

1 X TMP36GZ
1 X DC Fan
Jumper cables (generic)

1 X Sad plant in need of TCL

**Building the Plant Growth System**

Soil Moisture Module
1. Connect the SM 5V to power, GND to ground and AOUT (yellow wire) to A0. 
2. Connect relay VVC to 5V, GND to ground and IN1 to digital Pin 2. 
3. Connect Relay 1 common (middle port of relay) to 5V
4. Connect Relay 1 Normally Open (bottom port) to Pump 5V. Connect pump ground to ground. 
5. Connect one lead from float sensor to Pin 13 and the other to ground. 
6. Place float sensor and pump in water reservoir. Be careful to keep water away from bare leads and boards. 
7. Attach hose to pump and place one end in/near plant.
8. Set float MstLvl = to desired soil moisture content level (May require some experimenting).
9. Upload code to board and bring life to a dying plant.

Temperature Control Module
1. Connect TMP36 to 5V (left pin), ground (right pin) and A1 (middle pin).
2. Connect relay VVC to 5V, GND to ground and IN1 to digital Pin 2 (unless relay has been a;lready set up for SM Module!). 
3. Connect Relay 2 common (middle port of relay) to 5V
4. Connect Relay 2 Normally Open (bottom port) to DC Fan 5V. Connect  fan ground to ground. 
5. Set float TempLvl = to desired temperature threshold (in degrees Celsius).
6. Upload code to board. 

A note on building:
To save space, I refrained from using the breadboard in my final build, and instead made several dirty splices. There is a 5V pin attached to the board with 5 wires spliced to it for the relay board, Relay1, Relay2, SM and TMP. A ground pin attaches to the board then has leads going to the relay board, SM, TMP, pump and fan. This could be done with a breadboard to avoid cutting jumper cables. 

**Future Goals:**
Time based LED control. An attempt was made to add a timer function (controlling relay channel 3), but it did not mesh properly with the other modules. 


