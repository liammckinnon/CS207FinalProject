# CS207FinalProject-Robo Garden
**AIM OF PROJECT**

A fully automated plant growth system with watering (based on soil moisture content), temperature control and lights. The final goal of this project is to create a system that could fully grow a plant without any additional outside input. The most important control is water (because light and temperature can be controlled simply by putting the plant near a window). The project is easily scalable and modular. It can accommodate more (or less) soil moisture sensors and/or temperature control units. 
This project was inspired by my own inability to keep plants properly watered. Hopefully allocating this task to my MechaGardenzilla will give my plants a better shot at life.  

**DISCLAIMER**

I am not an electrical engineer or botanist. I take no responsibility for any harm that may come to person, property or botany as a result of this project.


**Version Information**

Version 4 is the current code. Found under 1_Chnl_Plant_watering_V4

**Repository Contents**

**/README.md -ReadMe document explaining the build*

**/hardware - Fritzing schematic for build and parts list*

**/images – Pictures of the build*

**/1_Chnl_Plant_watering - Archived version of software*

**/1_Chnl_Plant_watering_v2 - Archived version of software*

**/1_Chnl_Plant_watering_v3 - Archived version of software*

**/1_Chnl_Plant_watering_v4 - Current version of software*


**BUILD**

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

![CS207 Final Project_bb](https://user-images.githubusercontent.com/78987271/114496442-2bcf0f80-9bdd-11eb-9101-6dcf0127cf9d.jpg)



**FUNCTIONALITY**

Version 4.0
The system’s watering control functions well. When the soil moisture sensor detects a certain level of moisture (set beforehand in the program), it turns on the pump in one second intervals and waters the plant. The pump stops when desired moisture content is exceeded. The pump will not run if the water level in the reservoir is low, as controlled by the float switch. 
The temperature sensor reads ambient temperature and turns on the DC fan when a certain temperature level is exceeded (set beforehand in the program, in degrees Celsius). The fan turns off when desired temperature is reached. 
The two modules mesh well together. Both will run independently or at the same time (ex. Pump will run while fan is on). The temperature control module will continue to run after the float switch stops the pump from running. 
An enclosure for the system/plants has not been built yet, so the temperature control unit is not very useful at this point. Though the fan does work, it is not powerful enough to change the temperature of an entire room. This module would be more useful in a future, entirely enclosed build. Temperature control can also help offset excess heat caused by growing lights. 

Version 4.0 code has more controls integrated in the main void Loop() function. The initial goal was to have all module running as separate functions, to make the code more modular. However, this did not prove to work well in practice. The Version 4.0 code has a separate function to run the pump, but the rest of the controls are in the main body of the code. However, the temperature and soil moisture controls are separate in the body of the code, and the whole system will still run smoothly with the removal of one portion, making the build modular. Adding more SM or TMP sensors is as simple as declaring new pins for the analog sensors and relay control, and the copying the necessary code and changing the variables for the added sensor/relay. 


Version 4.0: Moisture control and temperature control work smoothly together. 

Version 3.0: Most experimenting was done with this version. Attempted to use all commands as functions. Moisture sensor and pump work well but modules do not interface properly. 
Version 2.0: Working pump and float sensor

**HARDWARE**

•	1 X Arduino Uno board
•	1 X 4 channel relay
•	1 X Soil moisture sensor
•	1 X DC pump
•	1 X Hose
•	1 X Water reservoir

•	1 X TMP36GZ
•	1 X DC Fan
•	Jumper cables (generic)
• 1 X Float switch (Amazon)

•	1 X Sad plant in need of TCL


I bought the soil moisture sensor, relay board and pump as a kit. It is available from the following link:
https://www.amazon.ca/WayinTop-Automatic-Irrigation-Watering-Capacitive/dp/B07WS71JC1/ref=sr_1_10?dchild=1&keywords=arduino+plant+watering&qid=1618285295&sr=8-10


**Building the Plant Growth System**

Soil Moisture Module
The soil moisture module measures the moisture content of the plant’s soil. It does this by testing resistivity across the board. Wet soil is less resistive (because water is conductive) than dry soil. The Soil moisture sensor is connected to analog pin A0. The sensor generally seems to give readings between 250 (sensor in water, max moisture content/conductivity) and 700 (dry sensor in the air, max resistivity). For this build, I did not map the values, and instead chose to make my threshold value based on the analog values that have been returned. 
To water the plant, a relay board is used, controlling a DC pump. Relay boards can be used to mechanically control larger voltages than the Arduino can typically handle. In a relay, a positive wire is run into the relay’s common port and then into either the “Normally Open” or “Normally Closed” ports of the relay. To control voltage, a digital signal is sent to the pins on the relay board. In this build, the pump relay is controlled by digital Pin 2. Then, the relay board sends a signal to either open or close the circuit. This will provide power (or stop providing power) to any device that is connected to the relay’s higher voltage wires. For this build I used a four channel relay, so it can control four devices (and potentially current from four different sources) at once. The DC pump that I used in this build is only rated for 5V, so an additional power source was not needed for the relay, and the pump run off of the Arduino’s 5V pin. 
 
 ![Relay example annotated](https://user-images.githubusercontent.com/78987271/114496421-2245a780-9bdd-11eb-951f-96e0e2d9e92d.jpg)

A float switch is used to control the water level, stopping the pump from running if the water reservoir is empty. The float switch is simply a piece of floating foam with an integrated magnet, which gives a digital signal (so it is attached to digital Pin 13). When the float is floating (or up), the senor gives a “HIGH” output. If the float drops to the bottom of the sensor, it gives a “LOW” output (indicating that the water level has dropped).

Temperature Control Module
A TMP36 temperature sensor is used to measure ambient temperature. The TMP36 produces an analog signal, and is hooked to analog Pin A1. The TMP36 also requires 5V and ground connections to function properly. In the program, code is used to convert the TMP36’s analog signal to degrees Celsius, to make reading and setting thresholds more convenient. To change the temperature, a DC fan is used. The DC fan is attached to the relay module board in the same fashion as the DC pump, expect the fan is connected to relay 2. On the Arduino, digital Pin 3 controls the fan’s relay switch. The fan is also running off of the Arduino’s provided 5V current, but I believe it could handle more power, and therefore decrease temperature quicker. However, my 2$ Princess Auto fans did not include a spec sheet, and for simplicities sake I wanted to keep the build to a single power source. 

LED Light Control Module
LED light control does not appear in V4 of the build, but will likely be added in future iterations. I would like to control grow lights using relay 3. I believe controlling the lights with a relay would be fairly straight forward, the positive wire just needs to be spliced into the relay’s common and NC ports, then attached to power. I did not include lights in this version because a) I do not currently have any lights and b) I had issues trying to make the light control code mesh with the rest of the system. 

Quick Build Instructions
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
2. Connect relay VVC to 5V, GND to ground and IN1 to digital Pin 2 (unless relay has been already set up for SM Module!). 
3. Connect Relay 2 common (middle port of relay) to 5V
4. Connect Relay 2 Normally Open (bottom port) to DC Fan 5V. Connect  fan ground to ground. 
5. Set float TempLvl = to desired temperature threshold (in degrees Celsius).
6. Upload code to board. 

A note on building:

To save space, I refrained from using the breadboard in my final build, and instead made several dirty splices. There is a 5V pin attached to the board with 5 wires spliced to it for the relay board, Relay1, Relay2, SM and TMP. A ground pin attaches to the board then has leads going to the relay board, SM, TMP, pump and fan. This could be done with a breadboard to avoid cutting jumper cables. 

**Future Goals:**

Time based LED control. An attempt was made to add a timer function (controlling relay channel 3), but it did not mesh properly with the other modules, so it was abandoned for now. 
WiFi monitoring/data logging/control. The long term goal for this project is to have data sent to a server, accessible through an app. The app would also allow manual control of the pump/fan/lights, and an option for changing LED timers and temp/moisture thresholds. 


Sources:

WayInTop Arduino Plant Watering System:
https://github.com/WayinTop/Automatic-Watering-System-JP
Float Sensor:
https://www.instructables.com/PP-Float-Switch-Tutorial/



