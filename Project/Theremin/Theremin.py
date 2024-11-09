import pygame
import serial
import time

# Inicjalizacja pygame do odtwarzania dźwięku
pygame.mixer.init()

# Ładowanie plików dźwiękowych
sounds = [
    pygame.mixer.Sound("m1.mp3"),
    pygame.mixer.Sound("m2.mp3"),
    pygame.mixer.Sound("m3.mp3"),
    pygame.mixer.Sound("m4.mp3"),
    pygame.mixer.Sound("m5.mp3")
]

# Ustawienie portu szeregowego (zmień COM9 na odpowiedni port)
try:
    arduino = serial.Serial('COM9', 9600, timeout=1)
    time.sleep(2)
    print("Połączono z Arduino.")
except Exception as e:
    print(f"Nie udało się połączyć z Arduino: {e}")
    exit()

# Inicjalne ustawienia głośności dla każdego utworu
current_volumes = [0.0, 0.0, 0.0]  # Zakomentowany czwarty czujnik
last_set_volumes = [0.0, 0.0, 0.0]  # Przechowuje ostatnio ustawione głośności

for sound in sounds:
    sound.set_volume(0.0)  # Początkowo wyciszone
    sound.play(-1)  # Odtwarzanie w pętli

try:
    while True:
        data = arduino.readline().decode().strip()

        # Debugowanie: Wyświetl odebrane surowe dane
        print(f"Odebrane dane: {data}")

        try:
            # Sprawdź, czy dane są zgodne z oczekiwaniami
            if "Czujnik" in data:
                values = data.replace("Czujnik ", "").replace(" cm", "").split(", ")

                # Upewnij się, że mamy dokładnie 3 wartości
                if len(values) == 3:
                    distances = [float(value.split(": ")[1]) if ": " in value else 0 for value in values]

                    # Przetwarzanie danych dla każdego czujnika
                    for i in range(3):  # Zakomentowany czwarty czujnik
                        if distances[i] < 30:
                            target_volume = max(0.0, min(1.0, (30 - distances[i]) / 30))
                            if current_volumes[i] != target_volume:
                                current_volumes[i] = target_volume
                                last_set_volumes[i] = target_volume  # Zapisujemy ostatnią ustawioną głośność

                                # Ustawienie głośności dla par utworów
                                if i == 1:  # Czujnik 2
                                    sounds[1].set_volume(current_volumes[i])  # M2
                                    sounds[4].set_volume(current_volumes[i])  # M5
                                    print(f"Ustawiono głośność utworów M2 i M5 na: {current_volumes[i]}")
                                elif i == 2:  # Czujnik 3
                                    sounds[2].set_volume(current_volumes[i])  # M3
                                    sounds[3].set_volume(current_volumes[i])  # M4
                                    print(f"Ustawiono głośność utworów M3 i M4 na: {current_volumes[i]}")
                                else:
                                    sounds[i].set_volume(current_volumes[i])
                                    print(f"Ustawiono głośność utworu {i + 1} na: {current_volumes[i]}")
                        else:
                            # Ustaw głośność na ostatnią zapamiętaną, gdy ręka jest poza zasięgiem
                            current_volumes[i] = last_set_volumes[i]
                            if i == 1:  # Czujnik 2
                                sounds[1].set_volume(current_volumes[i])  # M2
                                sounds[4].set_volume(current_volumes[i])  # M5
                            elif i == 2:  # Czujnik 3
                                sounds[2].set_volume(current_volumes[i])  # M3
                                sounds[3].set_volume(current_volumes[i])  # M4
                            else:
                                sounds[i].set_volume(current_volumes[i])
                            print(f"Utrzymano głośność utworu {i + 1} na: {current_volumes[i]}")

                    # Wyświetl stan końcowy dla aktualnej iteracji
                    print(f"Stan głośności: {current_volumes}")
                else:
                    print("Odebrano niepełne lub nieprawidłowe dane dla 3 czujników.")

        except ValueError:
            print("Błąd przetwarzania danych. Odebrane dane nie są liczbami.")

except KeyboardInterrupt:
    print("\nPrzerwano działanie programu.")

finally:
    for sound in sounds:
        sound.stop()
    arduino.close()
    print("Muzyka zatrzymana, połączenie z Arduino zamknięte.")
