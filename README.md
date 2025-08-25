# Automatic-Lottery-Machine
Motor Control and Electrical Subsystem code for my EGR 2800 Final Project - Automatic Lottery Machine. The code files present are both the prototype code and the production code stemming from their respective electrical subsystems/circuits. 

# Project Overview:
My group and I created an Automatic Lottery Machine as our Final Project for our EGR 2800 Design and Analysis of Electromechanical Systems course. The user pulls a 3D Printed Lever resulting in the center Greartisan DC Motor spin in a clockwise direction flipping the balls over and over again until a small hatch controlled by a single servo motor opens up to let in a ball into the trey. Once the ball is in the trey, the hatch closes releasing the ball and sliding down to where the second servo motor acting as the gate is present. As the ball rolls by, the Ultrasonic Sensor tracks the motion of the ball resulting in the small hatch of the first servo motor to unlock once more releasing another ball from the machine. This keeps going until there are five balls in total waiting to be relased back into the Lottery Machine. Once all five balls are present, the second servo motor's hatch unlocks and the balls head straight towards the spinning auger. The spinning auger activates when the second servo motor hatch releases the balls currently enqueued. The spinning auger has a Greartisan DC Motor attached to it allowing for the auger to spin in the clockwise direction pushing the balls directly up back into the lottery machine ready to be trialed once more. The Automatic Lottery Machine was built from the ground up using 3D printing (thanks to CAD Software), tools from the Arduino Kit, and Third Party Electronics. 

# Electronic Parts Included within the Prototype Circuit:
1 Arduino Mega 2560
<br>
<br>
1 Breadboard
<br>
<br>
1 Power Supply Module
<br>
<br>
1 Ultrasonic Sensor
<br>
<br>
1 9V1A Power Adapter
<br>
<br>
2 Small buttons
<br>
<br>
2 220 Ω Resistors
<br>
<br>
2 L293D H-Bridges
<br>
<br>
2 DC Motors (3-6V)
<br>
<br>
2 SG90 Servo Motors
<br>
<br>
Multiple Jumper Wires

# Prototype Circuit:
![Prototype Circuit 1](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Prototype_Circuit_1.jpeg?raw=true)
![Prototype Circuit 2](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Prototype_Circuit_2.jpeg?raw=true)

# Electronic Parts Included within the Project:
1 Arduino UNO R4 MINIMA
<br>
<br>
1 Breadboard
<br>
<br>
1 Power Supply Module (ALITOVE DC 12V 5A Power Supply Adapter Converter Transformer AC 100-240V Input with 5.5x2.5mm DC Output Jack for 5050 3528 LED Strip Module Light)
<br>
<br>
  Link: https://www.amazon.com/dp/B01GEA8PQA?ref=ppx_pop_mob_ap_share
<br>
<br>
1 Ultrasonic Sensor
<br>
<br>
1 Motor Driver (DROK DC Motor Driver, L298 Dual H Bridge Motor Speed Controller DC 6.5V-27V 7A PWM Motor Regulator Board 12V 24V Electric Motor Control Module Industrial 160W with Optocoupler Isolation)
<br> 
<br>
  Link: https://www.amazon.com/dp/B06XGD5SCB?ref=ppx_pop_mob_ap_share&th=1
<br>
<br>
2 Greartisan DC Gear Motors (12V RPM 150 High Torque Electric Micro Speed Reduction Geared Motor Centric Output Shaft 37mm Diameter Gearbox)
<br>
<br>
  Link: https://www.amazon.com/dp/B08D3SSG55?ref=ppx_pop_mob_ap_share&th=1
<br>
<br>
2 SG90 Servo Motors
<br>
<br>
Multiple Jumper Wires

# Final Project Circuit and Final Project Implementation:
![Final Circuit 1](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_1.jpeg?raw=true)
![Final Circuit 2](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_2.jpeg?raw=true)
![Final Circuit 3](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_3.jpeg?raw=true)
![Final Circuit 4](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_4.jpeg?raw=true)
![Final Circuit 5](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_5.jpeg?raw=true)
![Final Circuit 6](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_6.jpeg?raw=true)
![Final Circuit 7](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_7.jpeg?raw=true)
![Final Circuit 8](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_8.jpeg?raw=true)
![Final Circuit 9](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_9.jpeg?raw=true)
![Final Circuit 10](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_10.jpeg?raw=true)
![Final Circuit 11](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_11.jpeg?raw=true)
![Final Circuit 12](https://github.com/joshuapagonas/Automatic-Lottery-Machine/blob/main/Images/EGR_2800_Final_Project_Circuit_12.jpeg?raw=true)
