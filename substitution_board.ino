#include <TM1637Display.h>

#define CLK 9
#define DIO 8

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  display.setBrightness(3);

  
}

void loop() {
  Serial.print("Player in jersey number: ");
  while (Serial.available() == 0) {

  }
  int player_in = Serial.parseInt();
  clearBuffer();
  
  Serial.print("Player out jersey number: ");
  while (Serial.available() == 0) {

  }
  int player_out = Serial.parseInt();
  clearBuffer();
  Serial.print("\n");
  Serial.print(player_in);
  Serial.print(" : ");
  Serial.print(player_out);
  delay(1000);
  display.showNumberDecEx(player_in * 100 + player_out, 0b11110000, true);

  delay(5000);
  display.clear();
}

void clearBuffer(){
  while (Serial.available() > 0) {
    Serial.read();
  }
}
