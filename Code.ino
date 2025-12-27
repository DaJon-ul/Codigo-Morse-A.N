#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BOTON 2
#define BUZZER 8
LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long tInicio, tFin;
unsigned long ultimoEvento = 0;
String morseActual = "";
String texto = "";
void setup() {
pinMode(BOTON, INPUT);
pinMode(BUZZER, OUTPUT);
lcd.init();
lcd.backlight();
Serial.begin(9600);
}
void loop() {
if (digitalRead(BOTON) == HIGH) {
tInicio = millis();
while (digitalRead(BOTON) == HIGH);
tFin = millis();
unsigned long duracion = tFin - tInicio;
if (duracion < 300) {
morseActual += ".";
tono(100);
} else {
morseActual += "-";
tono(300);
}
ultimoEvento = millis();
actualizarLCD();
}
if (morseActual.length() > 0 && millis() - ultimoEvento > 800) {
texto += traducirMorse(morseActual);
morseActual = "";
actualizarLCD();
}
}
void tono(int d) {
digitalWrite(BUZZER, HIGH);
delay(d);
digitalWrite(BUZZER, LOW);
}
void actualizarLCD() {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("M:");
lcd.print(morseActual);
lcd.setCursor(0,1);
lcd.print("T:");
lcd.print(texto);
}
char traducirMorse(String m) {
if (m == ".-") return 'A';
if (m == "-...") return 'B';
if (m == "-.-.") return 'C';
if (m == "-..") return 'D';
if (m == ".") return 'E';
if (m == "....") return 'H';
if (m == "---") return 'O';
if (m == "...") return 'S';
return '?';
}
