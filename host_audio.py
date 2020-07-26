# copied some snippets from https://swharden.com/wp/2016-07-19-realtime-audio-visualization-in-python/
import numpy as np
import serial, time, pyaudio

CHUNK = 2**11
# Audio sample rate
RATE = 44100
AUDIO_INPUT_ID = 3
ARDUINO_PORT = 'COM3'

ser = serial.Serial()
# Be sure to match the baudrate of your ardiuno
ser.baudrate = 19200
# Choose the port of your arduino
ser.port = ARDUINO_PORT
ser
ser.open()
ser.is_open                              
time.sleep(2)

p=pyaudio.PyAudio()

stream=p.open(format=pyaudio.paInt16,channels=2,rate=RATE,input=True,output=True,
              frames_per_buffer=CHUNK, input_device_index=AUDIO_INPUT_ID)

for i in range(int(60*RATE/1024)): #go for a few seconds
    data = np.fromstring(stream.read(CHUNK),dtype=np.int16)
    peak=np.average(np.abs(data))*2
    amount=int(50*peak/2**16)

    # Printing the result to monitor output
    print(int(50*peak/2**16))
    ser.write(("% s" % amount).encode('utf-8'))

stream.stop_stream()
stream.close()
p.terminate()