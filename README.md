# Arduino-display_7-segmentos
Display de 7 segmentos.

## Features
- Easy to use.
- Compatible with Arduino.

## Example of usage
```c++
#include <display.h>

Display my_display(2,3,4,5,6,7,8, true);

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino listo");
}

void loop() {
  my_display.high();
  delay(500);
  for (int i = 0; i < 10; i++){
    my_display.print_number(i);
    Serial.println(i);
    delay(500);
  }
  my_display.low();
  delay(500);
}
