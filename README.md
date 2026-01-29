# Arduino-display_7-segmentos
A simple Arduino library for 7-segments Display.

## Features
- Easy to use.
- Compatible with Arduino.

## Example of usage
```c++
#include <display.h>

Display my_display(2,3,4,5,6,7,8, true);

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino ready");
}

void loop() {
  my_display.high();
  delay(500);
  for (int n = 0; n < 10; n++){
    my_display.print_number(n);
    Serial.println(n);
    delay(500);
  }
  my_display.low();
  delay(500);
}
