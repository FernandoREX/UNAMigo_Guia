#Para compilar y ejecutar: python3 BotR.py

import sys
import pyautogui as pg
import time
import webbrowser as web
import json


with open("DataBase.json", "r") as f:
        cadena_json = json.load(f)


phone_no = "+52" + sys.argv[1]

parsedMessage = "Instruciones: " + cadena_json["Instrucciones"] 
web.open('https://web.whatsapp.com/send?phone=' + phone_no + '&text=' + parsedMessage)
time.sleep(20)
for i in range(12) :
    pg.press('enter')
    print("enviando instrucciones...")
    pg
    pass
time.sleep(5)
pg.write("Ruta: " + cadena_json["Ruta"])
for i in range(12) :
    pg.press('enter')
    print("enviando ruta...")
    pg
    pass
time.sleep(5)
pg.write(cadena_json["Tiempo"])
for i in range(12) :
    pg.press('enter')
    print("enviando tiempo... ")
    pg
    pass
