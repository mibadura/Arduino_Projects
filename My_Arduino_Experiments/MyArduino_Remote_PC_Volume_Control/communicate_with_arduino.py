import serial
import volume_control
import time


arduino = serial.Serial('COM6', 9600)
starting_volume = volume_control.getVolume()
arduino.write(bytearray(str(starting_volume), 'utf-8'))

while True:
    
    data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars

    if data:
        t0 = time.time()
        received_string = data.decode('UTF-8')
        message = round(volume_control.setVolume(float(received_string)),2)
        # arduino.write(str(message), 'utf-8')
        arduino.write(bytearray(str(message), 'utf-8'))
        print("Sending message: ", str(message))
        t1 = time.time()
        print("Time: {}".format(t0-t1))