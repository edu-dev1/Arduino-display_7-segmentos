#ifndef display_h
#define display_h

#include <Arduino.h>

#define S 7

class Display{//A 7 Segments Display class.
    public:
        Display(uint16_t a, uint16_t b, uint16_t c, uint16_t d, uint16_t e, uint16_t f, uint16_t g, bool common_cathode);
        Display(uint16_t segments[S], bool common_cathode);
        void print(uint16_t n); //Displays a number between 0 and 9.
        void print(const char* string, unsigned long ms); //Displays the characters (or a hyphen "-" if they are not available) of `string`, with a delay of `ms` between each character.
        void print(char character); //Displays the char `character` (or a hyphen "-" if they are not available).
        void high(void); //Turns on the display
        void low(void); //Turns off the display
    private:
        uint16_t __a, __b, __c, __d, __e, __f, __g;
        bool __common_cathode;
        bool __state_on, __state_off;
        const short int PairsC = 32;
        const short int PairsN = 10;
        uint16_t __segments[S];
        struct PairN{
            uint16_t n;
            const uint16_t *Nn;
            uint16_t size;
        };
        struct PairC{
            char c;
            const uint16_t *Cc;
            uint16_t size;
        };
        bool __segment_in(uint16_t s, const uint16_t *N, uint16_t size);
};
#endif
