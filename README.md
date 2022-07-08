# ArduinoProject
#GETTING STARTED

To begin, this project requires the Arduino IDE to run the code, which must first be downloaded and configured. Do you not have an Arduino IDE? Copy and paste* https://support.arduino.cc/hc/en-us into your browser*. You can, on the other hand, use the Arduino web ide, but this will be dependent on the strength and availability of your internet. You will then be ready to go.
This project consists of a car chassis, two motorized wheels, one non-motorized 360° wheel, and a few sensors. It is powered by a 9-volt battery and is controlled by an Arduino Nano connected to a mini breadboard. When you turn it on, it immediately begins driving straight ahead. When it comes across an obstacle, it looks around for both sides and turns to the side with more open space. If there is no free space ahead or on both sides, it reverses the motors to drive backward. However, if there is no space or if it is too close to an object, it will come to a halt.


**1.#COMPONENTS**


1.1x Car Chassis Kit:
2.  2x Gear Motor
3.  1x Car Chassis
4.  2x Car Tire
5.  1x 360° Wheel
 6. 1x Arduino Nano
 7. 1x Mini Breadboard
8.  1x Motor Drive L293D
9.3x Ultrasonic Sensor HC SR04
10.  3x Sensor support 
 11.1x 9v Battery
 12.1x On-off switch
 13.5x 100uF capacitors
  14.2x 0.1uF capacitors
   15.1x IR Receiver
   16.1x Remote Control
2.#IMAGES
 





3.#Assembling the Chassis Tips
The breadboard can be attached to the chassis at the back.
Because of its weight, the battery must be installed in the front of the chassis.
The sensor supports on the front of the chassis should be screwed or glued in place.
Pressure can be applied to the sensor's supports. It is not necessary to glue or screw it together.



5:# Code
This project's code is available on my github page. Simply copy the provided link and paste it into your browser(). Simply copy and clone the code. Use your Arduino IDE to open the code. The file also requires you to download a (Iremote.h)LIbrary, which is used to return the sensor's ultrasonic infrared light. Download it from this link: https://www.ardu-badge.com/IRremote/zip
Please keep in mind that the project requires you to have three ultrasonic sensors for each side sensor (in my case I only used only one Ultrasonic Sensor HC SR04 ).The code is written in the C++ programming language.


Follow the steps below to include this library:
Open the Arduino IDE and select Sketch.
Include a library from the drop down menu
Proceed to the next step.
ZIP archive library
It will then locate the zip folder on your desktop.
You are now ready to go.



6.#WIRING

If you notice, the above-mentioned component requirements are missing the connection cables(Male and Female), but once you get the arduino uno kit, you will have met all of the requirements. I apologize for not mentioning it earlier. Follow the diagram below to connect. I'm sorry it was assigned based on my availability.those who use a different type of Arduino, such as the LilyPad ... Arduino Mega.... Arduino Leonardo.... Arduino Red Board....
Shields for Arduino,the  drawing may appear different,since this is based on arduino nano














 7:# You're done!!! Begin the Engines


Now that the car is complete, you can begin playing with it.

Turn on the switch to power the car after it has been placed on the ground. Then, using the remote control, press the PLAY button to start the motors. To turn it off, press the PREV button on the remote controller and turn off the car switch. While it is turned on, it continues to drive and avoid obstacles.



#CAUTION!!


It is critical to keep it from going to places with stairs or holes.        
