#ifndef display_h
#define display_h

#include <Arduino.h>
#include <string.h>

class Display{
    public:
        Display(int, int, int, int, int, int, int, bool);
        void print_number(int);
        void print_string(String, int);
        void print_char(char);
        void high(void);
        void low(void);
    private:
        int self_a, self_b, self_c, self_d, self_e, self_f, self_g;
        bool self_common_cathode;
        int self_state_on, self_state_off;

        struct PairN{
            int n;
            const int *Nn;
            uint8_t size;
        };
        struct PairC{
            char c;
            const int *Cc;
            uint8_t size;
        };
        bool __segment_in(int s, const int *N, int size);
};
#endif
