import matplotlib.pyplot as plt
import numpy as np
import time
from collections import deque

import functions as f
import os

import serial
ser = serial.Serial(port = 'COM6',\
                    baudrate = 9600,\
                    timeout = None,\
                    xonxoff=False,\
                    rtscts=False,\
                    dsrdtr=False)
def Main():
    os.system('cls')
    print('Please select a mode:    SQUARE (1), CIRCLE (2), CORNER (3),')
    print('                         TRACEBACK (4), PATH (5), WELL (6), HILL (7)')
    state = input('Mode: ')
    if(len(state) > 1):
        print("error: too many characters to be valid input ")
    else:
        serial_input = bytes(state, 'utf-8')
        print(serial_input)
        ser.write(serial_input)
        try:
            g = f.GraphData()
            if int(state) == 1:
                print("state: SQUARE")
            elif int(state) == 2:
                print("state: CIRCLE")
            elif int(state) == 3:
                print("state: CORNER")
            elif int(state) == 4:
                print("state: TRACEBACK")
            elif int(state) == 5:
                print("state: PATH")
            elif int(state) == 6:
                print("state: WELL")
            elif int(state) == 7:
                print("state: HILL")
            else:
                print("error: non valid state selected, please choose between 1 - 7")
##      print current position to screen
            try:
                while True:
                    data = ser.readline()
                    g.graph(data)
            except KeyboardInterrupt:
                    plt.close()
        except ValueError:
            print("ValueError: invalid literal for int() as state")

while True:
    Main()
    

