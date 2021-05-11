
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
import math
import traceback


devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))

current_vl_db = -10.0
current_vl_prc = 50.0
target_value_db = -10.0
target_value_prc = 50.0

DB_MIN = volume.GetVolumeRange()[0]
DB_MAX = volume.GetVolumeRange()[1]

def DBToPrc(value_in_db):
    return round(2**(value_in_db/10),6)*100

def PRCToDB(value_in_prc):
    output = 10*math.log2(value_in_prc/100)
    if(output < DB_MIN):
        return DB_MIN
    elif(output>DB_MAX):
        return DB_MAX
    else:
        return output 

def getCurrentInfo():
    global current_vl_db, current_vl_prc
    current_vl_db = volume.GetMasterVolumeLevel()
    print("Current volume in DB: ", current_vl_db)

    current_vl_prc = DBToPrc(current_vl_db)
    print("Current volume in PRC: ", current_vl_prc)

def lowerVol():
    global current_vl_prc, target_value_prc
    
    if(current_vl_prc >= 1):
        print("\nLowering volume")
        target_value_prc = current_vl_prc - 1
    else:
        print("Volume LOW")
        target_value_prc = 0

def increaseVol():
    global current_vl_prc, target_value_prc
    if(current_vl_prc <= 99):
        print("\nIncreasing volume")
        target_value_prc = current_vl_prc + 1
    else:
        print("\nVolume MAXED")
        target_value_prc = 100

def setVolume(input_value):
    global current_vl_db, current_vl_prc, target_value_db, target_value_prc
    print("\n\t--------------")
    
    getCurrentInfo()
    
    if(input_value == 333):
        lowerVol()
            
    elif(input_value == 444):
        increaseVol()
    elif(input_value == 0):
        return 255
    else:
        target_value_prc = input_value
  

    try:
        target_value_db = PRCToDB(target_value_prc)
        print("\nSetting volume in DB: ", target_value_db)
        print("Setting volume in PRC: ", target_value_prc)        
        volume.SetMasterVolumeLevel(target_value_db, None)
    except Exception as e:
        print("ERROR: target volume: ",input_value)
        print(traceback.format_exc())
        print(e)

    return target_value_prc
    
def getInfo():

    mute = volume.GetMute()
    print("Is muted?\t->\t", "Yes!" if mute == 1 else "No")

    vl = volume.GetMasterVolumeLevel()
    print("Volume level\t->\t",vl, " = ", DBToPrc(vl),"%")

    vr = volume.GetVolumeRange()
    print("Volume range\t->\t",vr)

def getVolume():
    vl = volume.GetMasterVolumeLevel()
    return DBToPrc(vl)

def main():
    
    getInfo()

    print("Input target volume %: ")
    input_value = float(input())
    
    setVolume(input_value)


if __name__ == "__main__":
    main()