#include <TM1637Display.h>

#define CLK 9
#define DIO 8

const int colon = 0b01000000;
const bool to_show_colon = true;
const int brightness_level = 7; //max

TM1637Display display(CLK, DIO);

int calculate_output(int num1, int num2){
  return num1 * 100 + num2;
}

void setup() {
  Serial.begin(9600);
  display.setBrightness(brightness_level);  
}

void loop() {
  Serial.print("OUT: ");
  while (Serial.available() == 0) {}
  int player_out = Serial.parseInt();
  clearSerial();
  
  Serial.print("IN: ");
  while (Serial.available() == 0) {}
  int player_in = Serial.parseInt();
  clearSerial();

  Serial.print("\n");
  Serial.print("out = ");
  Serial.print(player_out);
  Serial.print(", ");
  Serial.print("in = ");
  Serial.print(player_in);
  delay(1000);
  int display_output = calculate_output(player_out, player_in);
  display.showNumberDecEx(display_output, colon, to_show_colon);

  delay(5000);
}

void clearSerial(){
  while (Serial.available() > 0) {
    Serial.read();
  }
}
