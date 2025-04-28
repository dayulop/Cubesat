# backend/main.py

import serial
from flask import Flask, render_template, jsonify

app = Flask(__name__)

# Configuración del puerto serial (ajustá el nombre del puerto y baudrate)
SERIAL_PORT = 'COM8'     # En Linux puede ser '/dev/ttyUSB0'
BAUDRATE = 9600

# Variables globales para guardar los últimos datos
datos_sensor = {
    'temperatura': None,
    'humedad':     None,
    'latitud':     None,
    'longitud':    None,
    'altitud' :    None,
    'velocidad':   None
}

def leer_serial():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUDRATE, timeout=1)
        print(f"Conectado a {SERIAL_PORT}")
        while True:
            linea = ser.readline().decode('utf-8').strip()
            if linea:
                print(f"Datos recibidos: {linea}")
                procesar_datos(linea)
                print("Actualizado:", datos_sensor)  # ✅ Esto te confirma que actualizó
    except serial.SerialException as e:
        print(f"Error al conectar al puerto serial: {e}")

def procesar_datos(linea):
    try:
        partes = linea.split(",") #divide en diferentes segmentos lo recibido.
        for parte in partes:
            if ':' in parte:
                clave, valor = parte.split(":")#divide la etiqueta del valor que tiene este.
                clave = clave.strip().lower()
                valor = valor.strip()
                if clave == "temp" or clave == "temperatura":
                    datos_sensor['temperatura'] = float(valor)
                elif clave == "hum" or clave == "humedad":
                    datos_sensor['humedad'] = float(valor)
                elif clave == "lat":
                    datos_sensor['latitud'] = float(valor)
                elif clave == "lon":
                    datos_sensor['longitud'] = float(valor)
                elif clave == "alt":
                    datos_sensor['altitud'] = float(valor)
                elif clave == "vel":
                    datos_sensor['velocidad'] = float(valor)
    except Exception as e:
        print(f"Error procesando datos: {e}")

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/api/datos')
def api_datos():
    return jsonify(datos_sensor)

if __name__ == '__main__':
    import threading
    import os
    if os.environ.get('WERKZEUG_RUN_MAIN') == 'true':
        hilo_serial = threading.Thread(target=leer_serial, daemon=True)
        hilo_serial.start()
    app.run(debug=True)
