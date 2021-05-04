
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
import math

devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))

def setVolume(input_target_volume):

    try:
        target_volume = float(input_target_volume)
        target_volume_db = 10*math.log2(target_volume/100)
        volume.SetMasterVolumeLevel(target_volume_db, None)
    except Exception as e:
        
        print(e)
        print("INPUT: ", input_target_volume)
        

    

def getInfo():

    mute = volume.GetMute()
    print("Is muted?\t->\t", "Yes!" if mute == 1 else "No")

    vl = volume.GetMasterVolumeLevel()
    print("Volume level\t->\t",vl, " = ", round(2**(vl/10),2),"%")

    vr = volume.GetVolumeRange()
    print("Volume range\t->\t",vr)

def main():
    
    getInfo()

    print("Input target volume %: ")
    target_volume = float(input())
    
    setVolume(target_volume)


if __name__ == "__main__":
    main()