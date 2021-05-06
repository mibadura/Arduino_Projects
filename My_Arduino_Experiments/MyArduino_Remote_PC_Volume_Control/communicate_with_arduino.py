import serial
import volume_control


arduino = serial.Serial('COM6', 9600, timeout=.25)

while True:
    data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars

    if data:
        received_string = data.decode('UTF-8')
        print(received_string)
        volume_control.setVolume(received_string)
        volume_control.getInfo()