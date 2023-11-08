# Internet of Things course

by Chanankorn Jandaeng, Ph.D.

## Hardware and Interfacing

**Aims**
* To describe the function of analog and digital sensor
* To describe the function of I2C and Serial communication
* To gather the analog and degital value via MCU

**LED**

* Light Emitting Diode (LED) is a semiconductor device that emits light when an electric current passes through it.
* LEDs play a significant role in IoT by providing visual feedback, notifications, and efficient lighting solutions, and they can also be used creatively in various applications to enhance user experience and communication.
* Example blink code in Adruino

<img src="images/02/ex_01.png" width="200"/>

```
void setup() {
  pinMode(8, OUTPUT);
}
void loop() {
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
}
```
* Example blink code in NodeMCU

<img src="images/02/ex_02.png" width="200"/>

```
void setup() {
  pinMode(D2, OUTPUT);
}
void loop() {
  digitalWrite(D2, HIGH);
  delay(1000);
  digitalWrite(D2, LOW);
  delay(1000);
}
```
**RGB Led**
* Pulse Width Modulation, or PWM, is a technique for getting analog results with digital means. 
* Digital control is used to create a square wave, a signal switched between on and off. 

<img src="images/02/pwm.png" width="250"/>

* The RGB LED bulb contains primary LED colors: red, green, and blue.
* It has four pins, including Common pins R, G, and B.
* Common pins connect to the LED color pins A (Anode) or K (Cathode).
* Common A (CA) requires a connection to the positive terminal and a logic 0 (LOW) input to activate the desired color.
* Common K (CK) needs a connection to ground and a logic 0 input to control and illuminate the desired color.

<img src="images/02/rgb_led.png" width="300"/>

* Example:

<img src="images/02/ex_03.png" width="300"/>

```
int RGBPin[] = {11, 10, 9};

void setup() {
  pinMode(RGBPin[0], OUTPUT);
  pinMode(RGBPin[1], OUTPUT);
  pinMode(RGBPin[2], OUTPUT);
}

void setRGB(int r, int g, int b) {
  analogWrite(RGBPin[0], r);
  analogWrite(RGBPin[1], g);
  analogWrite(RGBPin[2], b);
}

void loop() {
  setRGB(255, 0, 0);
  delay(500);
  setRGB(0,255, 0);
  delay(500);
  setRGB(0, 0, 255);
  delay(500);
}
```
