# **Week04.** Embedded programming


|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |  compare the performance and development workflows for other architectures
| *individual*      | browse through the data sheet for your microcontroller; program a microcontroller development board; to interact (with local input &/or output) and communicate (remotely); extra credit: use different languages &/or development environments |



## Photo of the week



##Intro to electronics

The started the work this week only on Saturday, joining the open global time session. Rico gave us a very useful brief introduction. Below there is a note from the meeting.

![](../images/week04/FabAcademy2023 - page 40.png)

Rico also recommended a youtube video - A simple guide to electronic components [**link**](https://www.youtube.com/watch?v=6Maq5IyHSuc).


##RP2040 data sheet



![](../images/week04/xinfront.jpg)
![](../images/week04/Seeed-XIAO-RP2040-Pinout.jpg)

### RP2040 Project Examples
- https://projecthub.arduino.cc/Aboubakr_Elhammoumi/77347b69-2ade-4a44-b724-3bb91e954188
- https://how2electronics.com/getting-started-with-seeed-xiao-rp2040-with-projects/

##RP2040 with Arduino

source: https://wiki.seeedstudio.com/XIAO-RP2040-with-Arduino/
I took the following steps:

1. Step 1. Download and Install the latest version of Arduino IDE according to your operating system
2. Step 2. Launch the Arduino application.
3. Step 3. Add Seeed Studio XIAO RP2040 board package to your Arduino IDE
4. Navigate to File > Preferences, and fill Additional Boards Manager URLs with the url below: *https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json*. **This packacage doesn't work anymore!**


5. Therefore, I used board Raspberry Pi Pico and the example codes worked as expected for the user LED.
6. For blinkng the RGB LED, the library “Adafruit_NeoPixel”. The operationed worked. 
![](../images/week04/WhatsApp Image 2023-02-21 at 11.20.58.jpeg)



##RP2040 with MicroPython
source: https://wiki.seeedstudio.com/XIAO-RP2040-with-MicroPython/
![](../images/week04/Screenshot 2023-02-20 202832x.png)

1. Step 1. Download and Install the latest version of Thonny according to your operating system
2. Step 2. Launch the Arduino application.
3. Step 3. Add Seeed Studio XIAO RP2040 board package to your Thonny - navigate to Tools > Options > Choose MicroPython (Raspberry Pi Pico), Port: <Try to detect port automatically >, 
4. Click Install or updat MircoPython, to have the Seeed Studio XIAO RP2040 board detected, you need to double-tap the reset buttom.
![](../images/week04/WhatsApp Image 2023-02-21 at 11.52.47.jpeg)

5. For blinking  LED the ws2812.py library has to be downloaded, opened with Tonny and saved as RaspberryPi file "ws2812.py".Blinking LED works correctly. 
![](../images/week04/Screenshot 2023-02-20 204107x.png)

Loading the code in MircoPython is much faster than through Arduiono IDE. 

##The Morse Code in MicoroPython
I wanted to blink the LED light as the morse code communicator.
To symbolize dots, turn your light on for 1 second.
To symbolize dashes, turn your light on for 3 seconds.
The time gap between dots and dashes is 1 second with the light off.
The time gap between full letters is 3 seconds with the light off.
The pause between complete words is 7 seconds with the light off. source: https://the-daily-dabble.com/morse-code-light/

I followed below rules to create the code:
![](../images/week04/morse-code-chart.png)

```
from ws2812 import WS2812
import utime
import machine
power = machine.Pin(11,machine.Pin.OUT)
power.value(1)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

A = (BLACK,WHITE,BLACK,WHITE,WHITE,WHITE)
C = (WHITE,WHITE,WHITE,BLACK,WHITE,BLACK,WHITE,WHITE,WHITE,BLACK,WHITE)
L = (WHITE,BLACK,WHITE,WHITE,WHITE,BLACK,WHITE,BLACK,WHITE)
S = (WHITE,BLACK,WHITE,BLACK,WHITE)
T = (WHITE,WHITE,WHITE)
I = (WHITE,BLACK,WHITE)
M = (WHITE,WHITE,WHITE,BLACK,WHITE,WHITE,WHITE)
E = (WHITE,BLACK)
LETTERPAUSE = (BLACK,BLACK,BLACK)
WORDPAUSE = (BLACK,BLACK,BLACK,BLACK,BLACK,BLACK,BLACK)
word = "CLASS TIME "
CLASSTIME = (C,L,A,S,S, WORDPAUSE, T, I, M,E, WORDPAUSE)

led = WS2812(12,1)#WS2812(pin_num,led_count)
 
while True:
    for i in range(len(word)):
        print (word[i])
        letter =  CLASSTIME[i] + LETTERPAUSE
        for color in letter:
            led.pixels_fill(color)
            led.pixels_show()
            utime.sleep(1)
```


## Conclusions/Problems/Questions/Dilemas
- double click on reset button to reset?
- Loading the code in MircoPython is much faster than through Arduiono IDE. 
- Reset Button & Boot Button 
