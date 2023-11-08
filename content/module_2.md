# Internet of Things course

by Chanankorn Jandaeng, Ph.D.

## Hardware and Interfacing

The integration of light-emitting diodes (LEDs) into the Internet of Things (IoT) ecosystem has revolutionized the way we perceive and interact with smart devices. This document not only highlights the significance of LEDs in IoT applications but also delves into the intricacies of Pulse Width Modulation (PWM) and Analog-to-Digital Conversion (ADC). This extended exploration aims to provide IT students with a comprehensive understanding of these critical concepts.


**Aims**
* To describe the function of analog and digital sensor
* To describe the function of I2C and Serial communication
* To gather the analog and degital value via MCU

**LED**

* LEDs, as semiconductor devices that emit light upon the passage of an electric current, have emerged as indispensable components in the IoT landscape.
* LEDs play a significant role in IoT by providing visual feedback, notifications, and efficient lighting solutions, and they can also be used creatively in various applications to enhance user experience and communication.
 Their versatile utility includes:
    * Visual Feedback: LEDs serve as visual indicators, conveying information, status updates, and notifications to users. This capability enhances user experience and fosters seamless communication between devices and users.
    * Energy-Efficient Lighting: LEDs have redefined the concept of energy-efficient lighting solutions within IoT applications. Low power consumption and extended lifespans make them the ideal choice for illuminating IoT devices.
    * Creative Applications: Beyond their conventional uses, LEDs offer a canvas for creativity in various IoT applications. They can be programmed to produce captivating light patterns and colors, enriching the interactive experience.
* To master LED control in IoT, IT students should become familiar with essential functions such as:
    * pinMode(): This function configures a digital pin as an input or output, setting the stage for controlling LEDs.
    * digitalWrite(): Controlling the state of digital output pins is essential for managing LED behavior, including turning them on or off.
    * delay(): Implementing time delays using this function is vital for creating precise LED sequences and effects.
    * setup(): This function plays a pivotal role in initializing the configuration of IoT devices, including LED behavior.
    * loop(): The loop() function encapsulates the core logic and operations in IoT applications, including LED interactions.

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
**Pulse Width Modulation**

To achieve analog-like outcomes in a digital realm, IT students should acquaint themselves with Pulse Width Modulation (PWM). This technique entails generating a square wave, wherein the signal oscillates between ON and OFF states.
    * Duty Cycle: Understanding the duty cycle, which represents the ratio of time the signal is in the ON (HIGH) state relative to the entire signal period, is crucial for controlling LED brightness and intensity.
    * analogWrite(): Leveraging this function empowers IT students to manipulate the duty cycle, enabling the production of varying brightness levels and dynamic visual effects in LEDs.

* Pulse Width Modulation, or PWM, is a technique for getting analog results with digital means. 
* Digital control is used to create a square wave, a signal switched between on and off. 

<img src="images/02/pwm.png" width="250"/>

**RGB Led**

RGB LEDs, capable of displaying red, green, and blue primary colors, are pivotal components in the realm of LED technology. For IT students, comprehending their operation is fundamental.

An RGB LED typically comprises four pins, including Common pins R, G, and B, each serving a distinct role:
* Common A (CA): Connecting to the positive terminal and applying a logic 0 (LOW) input activates the desired color within the RGB spectrum.
* Common K (CK): A grounding connection is established, and a logic 0 input controls and illuminates the desired color in the RGB LED.


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

**Analog-to-Digital Conversion (ADC)**
Analog-to-Digital Conversion (ADC) is a cornerstone in the arsenal of tools available to IT students for interfacing between the analog and digital worlds. This conversion process involves translating analog signals, characterized by continuous variations in value and time, into discrete digital representations.

* Analog Signals: Analog signals exhibit continuous fluctuations in value and time, making them appear as continuous lines on graphs.  
    * Therefore, when plotting an analog contract in a graph It will look like a continuous line.

* Digital Signals: These signals undergo stepwise value changes and are created through sampling and quantization, offering discrete data points.
* Analog signals go through the process of sampling and quantization into digital signals.

<img src="images/02/sampling.png" width="400"/>

**Volume Resistor or Potentiometer**

* In this experiment, we will simulate an analog signal with voltage from volume Resistor or potentiometer from ADC pin (A0 or Pin 6) of Board NodeMCU/ESP8266. 
* Where the resolution of ADC is 10 bits (1024 values, 0-1023) means that if the voltage readings are analog signals, 3.3 V (equivalent to ESP8266 power supply), converted to digital values.
* The board NodeMCU/ESP8266 is seen as the value 1023 and in the same way. 
* When reading an analog voltage of 0 V, the digital value that the board sees will be 0.

**Experiment Using NodeMCU/ESP8266**

In an immersive hands-on experiment, IT students can gain firsthand experience in simulating analog signals. This is achieved by introducing voltage from a volume resistor or potentiometer into the ADC pin (A0 or Pin 6) of the NodeMCU/ESP8266 board. The board's 10-bit ADC resolution (equating to 1024 values, ranging from 0 to 1023) is integral to this exercise. Students will learn that the board interprets 3.3 V (the ESP8266 power supply) as 1023 and 0 V as 0.

Key functions and concepts for this experiment encompass:
* Serial.begin(): This function initializes serial communication, enabling data output for analysis and interpretation.
* Serial.println(): IT students can employ this function to print data to the serial monitor, facilitating real-time data evaluation.

<img src="images/02/ex_04.png" width="300"/>

```
void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  Serial.begin(val);
  delay(100);
}
```
<img src="images/02/ex_04_2.png" width="300"/>

* Challenge your self:

<img src="images/02/ex_05.png" width="400"/>

**The Light sensor**

Light Sensor Module: This component is employed for detecting ambient light levels. It offers both digital and analog outputs, granting students the flexibility to fine-tune the threshold for digital output using an onboard variable resistor (potentiometer).

* The Light sensor module comes with the basic components for light detection. 
* Use it to detect the light brightness in your environment and decide to switch OFF or ON light. 
    * Or maybe adjust the brightness of the LED for your house? It comes with digital and analog output. 
* You can adjust the threshold (sensitivity) of the digital output by tuning the onboard variable resistor (potentiometer). 
* Simple usage as it is a digital output, so you will know if the light is presented and decide what to do with it.  
* Example: LDR in analog & digital mode

<img src="images/02/ex_06.png" width="300"/>

* Example: LDR in  mode

```
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
  int d = digitalRead(7);
  int a = analogRead(A0);
  Serial.print(d);  
  Serial.print(" ");  
  Serial.println( a);

  delay(100);
}
```

**DHT11**

DHT11: For environmental monitoring, the DHT11 sensor provides digital signals for temperature and humidity readings. Operating within the voltage range of 3.5-5.5 V DC, it offers temperature accuracy within the range of 0-60°C (+/- 2%) and humidity accuracy within the range of 20-90% RH (+/- 5%).

* DHT11: Digital Temperature and Humidity Sensor 
    * To monitor temperature and humidity
    * The output is digital signal
    * Consume 3.5 - 5.5 V DC 
    * Temperature in 0-60° c (+/- 2%)
    * Humidity in 20-90 % RH. (+/- 5%)
* Example

<img src="images/02/ex_07.png" width="300"/>

* Add library named DHT11
    * Search DHT11 and install
    * Install -> Install All

<img src="images/02/add_dht11.png" width="300"/>

* Code

```
#include "DHT.h"
void setup(){
    Serial.begin(9600);
    Serial.println();
    Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

    dht.setup(2); // data pin 2
}

void loop()
{
    delay(dht.getMinimumSamplingPeriod());

    float humidity = dht.getHumidity(); // ดึงค่าความชื้น
    float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ

    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.println(dht.toFahrenheit(temperature), 1);
}

```

**I2C**

In the domain of microprocessors and microcontrollers, Inter-Integrated Circuit (I2C) communication takes center stage. IT students are encouraged to explore this low-speed data communication protocol, known for its versatility and compatibility with numerous devices on a single bus.


* Inter-Integrated Circuit (I2C) is the data communication for low-speed communication.
    * Use in microprocessor or microcontroller
    * Compatible many devices in a single bus
        * SDA (Serial Data): This pin serves as the conduit for transmitting data between devices, enabling seamless communication within the I2C network.
        * SCL (Serial Clock): Control over the data transmission process is vested in the Serial Clock, ensuring synchronization and reliability in data transfer.


<img src="images/02/i2c.png" width="400"/>

* I2C on NodeMCU

<img src="images/02/i2c2.png" width="400"/>

* Add downloaded Library
    * Download: https://github.com/cjundang/IoTWorkshop6Hr/blob/master/Arduino-LiquidCrystal-I2C-library-master.zip 
    * Add to Arduino IDE
        * Select Sketch > Include Library > Add zip Library

<img src="images/02/add_lib.png" width="400"/>

* Code:
```
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup(){
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("Hello Word");
  lcd.setCursor(5, 1);
  lcd.print("School of Informarics");
}

void loop(){
}
```
* OLED
    * Add Library
        * Search “adafruit ssd1306”
        * Install ALL library
```
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 16
Adafruit_SSD1306 display(OLED_RESET);
void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  
    display.clearDisplay();  
    display.setTextSize(1);  
    display.setTextColor(WHITE);
    display.setCursor(0,0);  
    display.println("Hello");

    display.setCursor(0,10);
    display.setTextSize(2);
    display.setTextColor(BLACK, WHITE);  
    display.println("World");
    display.display();
}
void loop() {
}
```