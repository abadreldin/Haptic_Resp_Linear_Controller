import matplotlib.pyplot as plt
import numpy as np
import time
from collections import deque

class GraphData:
##  create two queues with max length for x and y data
    def __init__(self):
        tailLength1 = 1
        tailLength2 = 4
        self.x_axis1 = deque(maxlen = tailLength1)
        self.y_axis1 = deque(maxlen = tailLength1)

        self.x_axis2 = deque(maxlen = tailLength2)
        self.y_axis2 = deque(maxlen = tailLength2)

        self.fig, self.ax = plt.subplots()

##        self.data = parse(ser.readline())

        self.x_axis1.append(0)
        self.y_axis1.append(0)

        self.x_axis2.append(self.x_axis1[0])
        self.y_axis2.append(self.y_axis1[0])

        self.ax.set_xlim(0, 84)
        self.ax.set_ylim(84, 0)

        self.line1, = self.ax.plot(self.x_axis1, self.y_axis1, "ro", markersize = 8)
        self.line2, = self.ax.plot(self.x_axis2, self.y_axis2, "r-", markersize = 1)

        plt.show(block = False)
        
    def parse(self, data):
        self.data_str = str(data).split(' ')
        try:
            self.x_data = str(self.data_str[0])[2:]
        except IndexError:
            self.x_data = 0
            print("IndexError: x set to 0, exception handled!!!")
        try:
            self.y_data = str(self.data_str[1])[:-3]
        except IndexError:
            self.y_data = 0
            print("IndexError: y set to 0, exception handled!!!")
        try:
            self.x = int(self.x_data)
        except ValueError:
            self.x = 0
            print("ValueError: x set to 0, exception handled!!!")
        try:
            self.y = int(self.y_data)
        except ValueError:
            self.y = 0
            print("ValueError: y set to 0, exception handled!!!")
##  if x and y go out of bounds (pushed to hard), set to boundry condition
        if self.x > 100:
            self.x = 0
        if self.y > 100:
            self.y = 0
        return (self.x, self.y)

    def graph(self, data):
##          set head of tail
                self.x_axis1.append(self.parse(data)[1])
                self.y_axis1.append(self.parse(data)[0])
##          add head point to tail
                self.x_axis2.append(self.x_axis1[0])
                self.y_axis2.append(self.y_axis1[0])
##          draw head
                self.line1.set_data(self.x_axis1, self.y_axis1)
                self.ax.draw_artist(self.line1)
                self.ax.draw_artist(self.ax.patch)
##          draw tail               
                self.line2.set_data(self.x_axis2, self.y_axis2)
                self.ax.draw_artist(self.line2)
                self.ax.draw_artist(self.ax.patch)
##          update plot              
                self.fig.canvas.draw()
                self.fig.canvas.flush_events()

