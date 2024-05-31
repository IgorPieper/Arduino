import serial
import time

arduino_port = 'COM9'
baud_rate = 9600

ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2)

def send_command(command):
    ser.write((command + '\n').encode())
    time.sleep(1)
    response = ser.readline().decode().strip()
    print("Arduino:", response)

while True:
    user_input = input("Wpisz 'r', 'g', 'b' aby zmienić kolor LED lub 'c' aby wyłączyć: ").strip().lower()
    if user_input in ['r', 'g', 'b', 'c']:
        send_command(user_input)
    else:
        print("Nieznana komenda. Użyj 'r', 'g', 'b' lub 'c'.")

ser.close()
