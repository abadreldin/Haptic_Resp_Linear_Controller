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
    print('Please select a mode:    SQUARE (1), CIRCLE (2), CORNSTARCH WALL (3), TRACEBACK (4)')
    print('                         PATH (5), WELL (6), HILL (7), INNER SQUARE (8)')
    print('                         HARD SQUARE (9), DIAGONAL (12)')
    state = input('Mode: ')

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
            print("state: CORNSTARCHWALL")
        ##elif int(state) == 3:
        ##    print("state: CORNER")
        elif int(state) == 4:
            print("state: TRACEBACK")
        elif int(state) == 5:
            print("state: PATH")
        elif int(state) == 6:
            print("state: WELL")
        elif int(state) == 7:
            print("state: HILL")
        elif int(state) == 8:
            print("state: INNERSQUARE")
        elif int(state) == 9:
            print("state: HARDSQUARE")
        elif int(state) == 11:
            print("state: BUTTON")
        elif int(state) == 12:
            print("state: DIAGONAL")
        else:
            print("error: non valid state selected, please choose between 1 - 8")
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
    

