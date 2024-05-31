import serial
import time
from PIL import ImageGrab
import numpy as np

arduino_port = 'COM9'
baud_rate = 9600

ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2)

def send_command(command):
    ser.write((command + '\n').encode())
    time.sleep(1)
    response = ser.readline().decode().strip()
    print("Arduino:", response)

def get_average_color():
    screenshot = ImageGrab.grab()
    img_np = np.array(screenshot)
    avg_color_per_row = np.average(img_np, axis=0)
    avg_color = np.average(avg_color_per_row, axis=0)
    return int(avg_color[0]), int(avg_color[1]), int(avg_color[2])

while True:
    r, g, b = get_average_color()
    print(f"Average color: R={r}, G={g}, B={b}")
    send_command(f"{r} {g} {b}")
    time.sleep(1)

ser.close()
