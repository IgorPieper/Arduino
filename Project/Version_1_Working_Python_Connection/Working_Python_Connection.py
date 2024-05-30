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
    user_input = input("Wpisz 'on' aby włączyć LED, 'off' aby wyłączyć: ").strip().lower()
    if user_input in ['on', 'off']:
        send_command(user_input)
    else:
        print("Nieznana komenda. Użyj 'on' lub 'off'.")

ser.close()
