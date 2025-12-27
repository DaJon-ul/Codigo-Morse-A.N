# Codigo-Morse-A.N

# Objetivos del Proyecto 
- Comprender el funcionamiento del código Morse.
- Implementar medición de tiempo con Arduino.
- Traducir señales Morse a texto legible.
- Mostrar información en una pantalla LCD.
- Emitir retroalimentación acústica

# Lista de Materiales
- Arduino UNO R3
- Pantalla LCD 16x2 con interfaz I2C
- Botón pulsador momentáneo
- Resistencia 10kΩ
- Buzzer activo
- Protoboard
- Cables Dupont macho-macho

# Funcionamiento del Sistema
El sistema mide el tiempo durante el cual el botón permanece presionado. Presiones cortas se
interpretan como puntos y presiones largas como rayas. Al detectar una pausa mayor a 800 ms, el
sistema traduce el símbolo Morse a su correspondiente carácter alfabético.
