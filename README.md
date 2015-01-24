# Count Up Timer
* * *
# New Style Kitchen Timer
Conventional timers have simple display because they are based on **Count-Down** system.
They need to show only one time that is counted down.
But the simplification causes demerits:
* Must set time before starting the timer
 * Need time to prepare
 * Risk of forgetting (It causes time loss)
* Modifying time at halfway is not friendly
 * Be afraid of mistake
* Extension requires re-timer
 * Complicated

How to improve the user-fiendly?

***Use Count-Up!!***

<img src="img/count_up_timer.png" alt="Count Up Timer App" width="25%" height="25%" class="left">
[![Get it on Google Play](http://www.android.com/images/brand/get_it_on_play_logo_small.png)](https://play.google.com/store/apps/details?id=jp.tkgktyk.countuptimer)
iOS version is comming soon.

And to use it in the kitchen, I create the timer as hardware.
**Let's prototyping!**

# Prototyping
Preparation:
 * Arduino Leonardo
 * Arduino IDE 1.5.x and 1.0.4
 * arduino-tiny: [ATtiny core for Arduino](https://code.google.com/p/arduino-tiny/ "ATtiny core for Arduino")

## Breadboard
Arudino sketch: [uptimer_arduino](Arduino/sketch/uptimer_arduino "Arduino Sketch for Breadboard")

<img src="img/breadboard.png" alt="Breadboard" width="33%" height="33%">

|Part Name | Quantity | Notes |
|----------|:--------:|-------|
|I2C 8x2 LCD | 1 | |
|pitch converter board | 1 | 1.5mm to 2.54mm pitch for LCD |
|Push button | 6 | tactile switch |
|Speaker | 1 | piezoelectric speaker |

## Universal Board
Arudino sketch: [uptimer_arduino](Arduino/sketch/uptimer_arduino "Arduino Sketch for Universal Board")
(the same scketch as Breadboard)

<img src="img/universal.png" alt="Universal Board" width="33%" height="33%">

|Part Name | Quantity | Notes |
|----------|:--------:|-------|
|I2C 8x2 LCD | 1 | |
|pitch converter board | 1 | 1.5mm to 2.54mm pitch for LCD |
|Push button | 6 | tactile switch |
|Speaker | 1 | piezoelectric speaker |

## ATTiny84 Programming
Arudino sketch: [uptimer_attiny84](Arduino/sketch/uptimer_attiny84 "Arduino Sketch for ATTiny84")

<img src="img/attiny84.png" alt="ATTiny84 Programming" width="33%" height="33%">

|Part Name | Quantity | Notes |
|----------|:--------:|-------|
|I2C 8x2 LCD | 1 | |
|pitch converter board | 1 | 1.5mm to 2.54mm pitch for LCD |
|Push button | 1 | tactile switch |
|ATTiny84 | 1 | DIP |

## PCB Prototyping
### ~~Gen. 1~~
~~First prototype: 4.2mm x 3.7mm~~

<img src="img/PCB Design_ UpTimer.pcb.png" alt="PCB Gen.1 layout" width="33%" height="33%">
<img src="img/pcb_gen1.jpg" alt="PCB Gen.1 photo" width="33%" height="33%">

It works fine, but I need to update.

### Gen. 2
 * Same layout as the mobile app
 * 4.2mm x 4.2mm

<img src="img/PCB Design_ UpTimer2.pcb.png" alt="PCB Gen.2 layout" width="33%" height="33%">

After function check, I'll upload schematic and layout data.

## License
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
