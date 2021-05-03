
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
import math


def main():
    devices = AudioUtilities.GetSpeakers()

    interface = devices.Activate(
        IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = cast(interface, POINTER(IAudioEndpointVolume))
    
    mute = volume.GetMute()
    print("Is muted?\t->\t", "Yes!" if mute == 1 else "No")

    vl = volume.GetMasterVolumeLevel()
    print("Volume level\t->\t",vl, " = ", round(2**(vl/10),2),"%")

    vr = volume.GetVolumeRange()
    print("Volume range\t->\t",vr)

    print("Input target volume %: ")
    target_volume = float(input())
    target_volume_db = 10*math.log2(target_volume/100)
    volume.SetMasterVolumeLevel(target_volume_db, None)


if __name__ == "__main__":
    main()