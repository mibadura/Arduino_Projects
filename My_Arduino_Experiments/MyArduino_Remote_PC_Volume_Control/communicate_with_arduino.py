import serial
import volume_control


arduino = serial.Serial('COM6', 9600, timeout=.25)
starting_volume = volume_control.getVolume()
arduino.write(bytearray(str(starting_volume), 'utf-8'))

while True:
    data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars

    if data:
        received_string = data.decode('UTF-8')
        message = round(volume_control.setVolume(float(received_string)),2)
        # arduino.write(str(message), 'utf-8')
        arduino.write(bytearray(str(message), 'utf-8'))
        print("Sending message: ", str(message))