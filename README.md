# Arduino-display_7-segmentos
A simple Arduino library for 7-segments Display.

## Features
- Easy to use.
- Compatible with Arduino.

## Example of usage
```c++
#include <display.h>

/*---Creating the object my_display---*/
int a_seg = 1, b_seg = 2, c_seg = 3, d_seg = 4, e_seg = 5, f_seg = 6, g_seg = 7;
bool common_cathode = true;
Display my_display(a_seg, b_seg, c_seg, d_seg, e_seg, f_seg, g_seg, common_cathode);

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino ready");
}

void loop() {
  my_display.high();//Turns on all segments
  delay(500);
  for (int n = 0; n < 10; n++){
    my_display.print_number(n);//displays the numbers from 0 to 9
    Serial.println(n);
    delay(500);
  }
  my_display.low();//Turns off all segments
  delay(500);
}
