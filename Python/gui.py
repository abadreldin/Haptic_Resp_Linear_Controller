import matplotlib.pyplot as plt
import numpy as np
import time
from collections import deque

import functions as f
import os

import serial
ser = serial.Serial(port = 'COM8',\
                    baudrate = 9600,\
                    timeout = None,\
                    xonxoff=False,\
                    rtscts=False,\
                    dsrdtr=False)
def Main():
    os.system('cls')
    print('Please select a mode:    MOTOROFF (0), SQUARE (1), CIRCLE (2), CORNSTARCH WALL (3)')
    print('                         TRACEBACK (4), PATH (5), WELL (6), DIAGONAL (7)')
    print('                         INNER SQUARE (8), HARD SQUARE (9)')
    state = input('Mode: ')

    serial_input = bytes(state, 'utf-8')
##    print(serial_input)
    ser.write(serial_input)
    try:
        g = f.GraphData()
        if int(state) == 0:
            print("state: MOTOROFF")
        elif int(state) == 1:
            print("state: SQUARE")
        elif int(state) == 2:
            print("state: CIRCLE")
        elif int(state) == 3:
            print("state: CORNSTARCHWALL")
        elif int(state) == 4:
            print("state: TRACEBACK")
        elif int(state) == 5:
            print("state: PATH")
        elif int(state) == 6:
            print("state: WELL")
        elif int(state) == 7:
            print("state: DIAGONAL")
        elif int(state) == 8:
            print("state: INNERSQUARE")
        elif int(state) == 9:
            print("state: HARDSQUARE")
        else:
            print("error: non valid state selected, please choose between 0 - 9")
##      print current position to screen
        try:
            while True:
                if(int(state) != 0):
                    while True:
                        data = ser.readline()
                        g.graph(data)
        except KeyboardInterrupt:
                plt.close()
                ser.write(bytes('0', 'utf-8'))
                print('Motors Off')
    except ValueError:
        print("ValueError: invalid literal for int() as state")

while True:
    Main()
    

