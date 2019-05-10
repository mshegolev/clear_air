import time
from datetime import datetime

import serial as s

arduino_port = "/dev/cu.usbserial-1440"
#speed = 9600
speed = 115200
datafile = "data.csv"
try:
    arduino = s.Serial(port=arduino_port, baudrate=speed, timeout=1)
except:
    print("Please check the port")

rawdata = []
count = 0
while count < 10:
    rawdata.append(str(datetime.now()) + "," + str(arduino.readline().decode()))
    count += 1
    print(rawdata.pop())
    time.sleep(1)


def write(L):
    file = open(file=datafile, mode='a')
    for i in range(len(L)):
        file.write(L[i])
    file.close()


write(rawdata)
print(rawdata)
