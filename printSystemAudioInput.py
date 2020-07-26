# handy script from https://stackoverflow.com/a/39677871/7769378
import pyaudio
p = pyaudio.PyAudio()

# Printing out the audio inputs of your system by ID with their names

info = p.get_host_api_info_by_index(0)
numdevices = info.get('deviceCount')
for i in range(0, numdevices):
        if (p.get_device_info_by_host_api_device_index(0, i).get('maxInputChannels')) > 0:
            print ("Input Device id ", i, " - ", p.get_device_info_by_host_api_device_index(0, i).get('name'))