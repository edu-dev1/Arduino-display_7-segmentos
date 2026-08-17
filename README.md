# Arduino-display_7-segmentos
A simple Arduino library for 7-segments Display.

## Features
- Easy to use.
- Compatible with Arduino.

## Example of usage
```c++
#include <Arduino.h>
#include <display.h>

uint16_t segs[7] = {2, 3, 4, 5, 6, 7, 8};
bool is_common_cathode = true;
Display my_display(segs, is_common_cathode);

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino listo");
}

void loop() {
  /*Turn on*/
  my_display.high();
  delay(500);
  /*Displaying numbers*/
  for (int i = 0; i < 10; i++){
    my_display.print(i);
    Serial.println(i);
    delay(500);
  }
  /*Displaying a character*/
  my_display.print('E');
  delay(500);
  /*Displaying a string*/
  my_display.print("Seven Segments Display", 500);
  delay(500);
  /*Turn off*/
  my_display.low();
  delay(500);
}
```
