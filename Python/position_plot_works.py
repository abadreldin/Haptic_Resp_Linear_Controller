import matplotlib.pyplot as plt
import numpy as np
import time
from collections import deque
import msvcrt
import serial

ser = serial.Serial(port = 'COM8',\
                    baudrate = 9600,\
                    timeout = None,\
                    xonxoff=False,\
                    rtscts=False,\
                    dsrdtr=False)

def parse(data):
    data_str = str(data).split(" ")
##    print(data_str[0] + " " + data_str[1])
    x_data = str(data_str[0])[2:]
    y_data = str(data_str[1])[:-3]
##  print(x_data + " " + y_data)
    x = int(x_data)
    y = int(y_data)
    ##if x and y go out of bounds (pushed to hard), set to boundry condition
    if x > 100:
        x = 0
    if y > 100:
        y = 0
    cordinate = (x, y)
    return (x, y)

def graph_data():
    ##create two queues with max length for x and y data
    tailLength1 = 1
    tailLength2 = 50

    x_axis1 = deque(maxlen = tailLength1)
    y_axis1 = deque(maxlen = tailLength1)

    x_axis2 = deque(maxlen = tailLength2)
    y_axis2 = deque(maxlen = tailLength2)

    fig, ax = plt.subplots()

    data = parse(ser.readline())

    x_axis1.append(data[1])
    y_axis1.append(data[0])

    x_axis2.append(x_axis1[0])
    y_axis2.append(y_axis1[0])

    ax.set_xlim(0, 84)
    ax.set_ylim(84, 0)

    line1, = ax.plot(x_axis1, y_axis1, "ro", markersize = 8)
    line2, = ax.plot(x_axis2, y_axis2, "r-", markersize = 1)

    plt.show(block = False)

    tstart = time.time()
    num_plots = 0
    try:
        while True:
            lastTime = time.time()
            data = parse(ser.readline())
            
        ##set head of tail
            x_axis1.append(data[1])
            y_axis1.append(data[0])
            
        ##add head point to tail
            x_axis2.append(x_axis1[0])
            y_axis2.append(y_axis1[0])

            line1.set_data(x_axis1, y_axis1)
            ax.draw_artist(line1)
            ax.draw_artist(ax.patch)
            line2.set_data(x_axis2, y_axis2)
            ax.draw_artist(line2)
            ax.draw_artist(ax.patch)
            fig.canvas.draw()
            fig.canvas.flush_events()
            
    ##        fps = 1/(time.time() - lastTime)
    ##        print(fps)
            if(msvcrt.kbhit()):
                break
            ##print(data)
    except KeyboardInterrupt:
        print('Please select a mode: SQUARE (1), CIRCLE (2), CORNER (3),')
        print('TRACEBACK (4), PATH (5), WELL (6), HILL (7)')
        state = input('choice: ')
##
##print('Please select a mode: SQUARE (1), CIRCLE (2), CORNER (3),')
##print('TRACEBACK (4), PATH (5), WELL (6), HILL (7)')
##state = input('choice: ')
##print(state)
##if state s 1):
##    print("state = 1")
while True:
    graph_data()

##        graph_data()



print("end")

