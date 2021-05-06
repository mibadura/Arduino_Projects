
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
import math
import traceback


devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))

def setVolume(input_target_volume):

    vl = volume.GetMasterVolumeLevel()
    vl_prc = round(2**(vl/10),2)*100
    print("Current volume ", vl_prc)

    try:
        target_volume = float(input_target_volume)
    except Exception as e:
        print(traceback.format_exc())
        print(e)

    try:
        if(target_volume == 333 and vl_prc > 0):
            vl_prc -= 0.01
            target_volume = vl_prc
        elif(target_volume == 444 and vl_prc < 100):
            vl_prc += 0.01
            target_volume = vl_prc
    except Exception as e:
        print(traceback.format_exc())
        print(e)   

    try:
        target_volume_db = 10*math.log2(target_volume/100)
        print("\tSetting volume in prc: ", target_volume)
        print("\tSetting volume in db: ", target_volume_db)
        volume.SetMasterVolumeLevel(target_volume_db, None)
    except Exception as e:
        print("target volume: ",target_volume)
        print(traceback.format_exc())
        print(e)

        

    

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