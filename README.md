# LUMAUDIONO
Visualizing audio input streams with data sent over USB Serial to an Arduino.

## Dependencies
[Pyaudio](http://people.csail.mit.edu/hubert/pyaudio/) on Windows

[Neopixel](https://github.com/adafruit/Adafruit_NeoPixel) for Arduino.

## Requirements
- Arduino (I did this on an Uno R3)
- An addressable RGB strip (I used the ws2812b LEDs)
- Windows system (Pyaudio is cross-compatible, though)

## Set Up
Connect your Arduino to your PC and the Lights to an appropriate data pin (power is your own business).  

In [lumaudiono.ino](lumaudiono.ino)
Set your LED amount and your data pin  
Upload the lumaudiono.ino to your Arduino. It'll now be waiting for usb serial traffic.  

In the poorly named (host_audio.py)[host_audio.py]
Set `AUDIO_INPUT_ID` to any active audio input id. If you don't know an id, be sure to run printSystemAudioInput.py and find an apropriate input device.

Select your correct ARDUINO_PORT  
and run!
