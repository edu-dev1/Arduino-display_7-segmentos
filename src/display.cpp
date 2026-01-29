#include <display.h>
        
Display::Display(int a, int b, int c, int d, int e, int f, int g, bool common_cathode){//
    self_a = a;
    self_b = b;
    self_c = c;
    self_d = d;
    self_e = e;
    self_f = f;
    self_g = g;
    self_common_cathode = common_cathode;
    
    pinMode(self_a, OUTPUT);
    pinMode(self_b, OUTPUT);
    pinMode(self_c, OUTPUT);
    pinMode(self_d, OUTPUT);
    pinMode(self_e, OUTPUT);
    pinMode(self_f, OUTPUT);
    pinMode(self_g, OUTPUT);

    if (self_common_cathode){
        self_state_on = 1;
        self_state_off = 0;
    }else{
        self_state_on = 0;
        self_state_off = 1;
    }
}
void Display::print_number(int number){//Muestra un número del 0-9.

    const int N0[6] = {self_a, self_b, self_c, self_d, self_e, self_f};
    const int N1[2] = {self_b, self_c};
    const int N2[5] = {self_a, self_b, self_d, self_e, self_g};
    const int N3[5] = {self_a, self_b, self_c, self_d, self_g};
    const int N4[4] = {self_b, self_c, self_f, self_g};
    const int N5[5] = {self_a, self_c, self_d, self_f, self_g};
    const int N6[6] = {self_a, self_c, self_d, self_e, self_f, self_g};
    const int N7[3] = {self_a, self_b, self_c};
    const int N8[7] = {self_a, self_b, self_c, self_d, self_e, self_f, self_g};
    const int N9[5] = {self_a, self_b, self_c, self_f, self_g};
    const int self_SEGMENTS[7] = {self_a, self_b, self_c, self_d, self_e, self_f, self_g};
    
    const PairN NUMBERS[] = {
        {0, N0, sizeof(N0) / sizeof(N0[0])},
        {1, N1, sizeof(N1) / sizeof(N1[0])},
        {2, N2, sizeof(N2) / sizeof(N2[0])},
        {3, N3, sizeof(N3) / sizeof(N3[0])},
        {4, N4, sizeof(N4) / sizeof(N4[0])},
        {5, N5, sizeof(N5) / sizeof(N5[0])},
        {6, N6, sizeof(N6) / sizeof(N6[0])},
        {7, N7, sizeof(N7) / sizeof(N7[0])},
        {8, N8, sizeof(N8) / sizeof(N8[0])},
        {9, N9, sizeof(N9) / sizeof(N9[0])}
    };

    for (int segment : self_SEGMENTS){
        bool on = false;
        for (int j = 0; j < 10; j++){
            if (NUMBERS[j].n == number){
                on = __segment_in(segment, NUMBERS[j].Nn, NUMBERS[j].size);
                break;
            }
        }
        digitalWrite(segment, on ? self_state_on : self_state_off);
    }
}

void Display::print_string(String string, int seconds){//Muestra los caracteres (- si no está disponible) de una cadena esperando los segundos dados entre caracteres.
    const int L_A[] = {self_a, self_b, self_c, self_e, self_f, self_g};
    const int L_b[] = {self_c, self_d, self_e, self_f, self_g};
    const int L_c[] = {self_d, self_e, self_g};
    const int L_d[] = {self_b, self_c, self_d, self_e, self_g};
    const int L_E[] = {self_a, self_d, self_e, self_f, self_g};
    const int L_F[] = {self_a, self_e, self_f, self_g};
    const int L_g[] = {self_a, self_b, self_c, self_d, self_f, self_g};
    const int L_H[] = {self_b, self_c, self_e, self_f, self_g};
    const int L_h[] = {self_c, self_e, self_f, self_g};
    const int L_I[] = {self_e, self_f};
    const int L_i[] = {self_e};
    const int L_J[] = {self_b, self_c, self_d};
    const int L_L[] = {self_d, self_e, self_f};
    const int L_o[] = {self_c, self_d, self_e, self_g};
    const int L_P[] = {self_a, self_b, self_c, self_e, self_f, self_g};
    const int L_r[] = {self_e, self_f, self_g};
    const int L_S[] = {self_a, self_c, self_d, self_f, self_g};
    const int L_U[] = {self_b, self_c, self_d, self_e, self_f};
    const int L_u[] = {self_c, self_d, self_e};
    const int self_SEGMENTS[7] = {self_a, self_b, self_c, self_d, self_e, self_f, self_g};

    const PairC LETTERS[] = {
        {'A', L_A, sizeof(L_A) / sizeof(L_A[0])},
        {'a', L_A, sizeof(L_A) / sizeof(L_A[0])},
        {'B', L_b, sizeof(L_b) / sizeof(L_b[0])},
        {'b', L_b, sizeof(L_b) / sizeof(L_b[0])},
        {'C', L_c, sizeof(L_c) / sizeof(L_c[0])},
        {'c', L_c, sizeof(L_c) / sizeof(L_c[0])},
        {'D', L_d, sizeof(L_d) / sizeof(L_d[0])},
        {'d', L_d, sizeof(L_d) / sizeof(L_d[0])},
        {'E', L_E, sizeof(L_E) / sizeof(L_E[0])},
        {'e', L_E, sizeof(L_E) / sizeof(L_E[0])},
        {'F', L_F, sizeof(L_F) / sizeof(L_F[0])},
        {'f', L_F, sizeof(L_F) / sizeof(L_F[0])},
        {'G', L_g, sizeof(L_g) / sizeof(L_g[0])},
        {'g', L_g, sizeof(L_g) / sizeof(L_g[0])},
        {'H', L_H, sizeof(L_H) / sizeof(L_H[0])},
        {'h', L_h, sizeof(L_h) / sizeof(L_h[0])},
        {'I', L_I, sizeof(L_I) / sizeof(L_I[0])},
        {'i', L_i, sizeof(L_i) / sizeof(L_i[0])},
        {'J', L_J, sizeof(L_J) / sizeof(L_J[0])},
        {'j', L_J, sizeof(L_J) / sizeof(L_J[0])},
        {'L', L_L, sizeof(L_L) / sizeof(L_L[0])},
        {'l', L_L, sizeof(L_L) / sizeof(L_L[0])},
        {'O', L_o, sizeof(L_o) / sizeof(L_o[0])},
        {'o', L_o, sizeof(L_o) / sizeof(L_o[0])},
        {'P', L_P, sizeof(L_P) / sizeof(L_P[0])},
        {'p', L_P, sizeof(L_P) / sizeof(L_P[0])},
        {'R', L_r, sizeof(L_r) / sizeof(L_r[0])},
        {'r', L_r, sizeof(L_r) / sizeof(L_r[0])},
        {'S', L_S, sizeof(L_S) / sizeof(L_S[0])},
        {'s', L_S, sizeof(L_S) / sizeof(L_S[0])},
        {'U', L_U, sizeof(L_U) / sizeof(L_U[0])},
        {'u', L_u, sizeof(L_u) / sizeof(L_u[0])}
    };
    
    for (char c : string) {
        if (c == ' ') {
            low();
            delay(seconds * 1000);
            continue;
        }

        bool found = false;
        const PairC* letter = nullptr;

        // Buscar letra
        for (int j = 0; j < 32; j++) {
            if (c == LETTERS[j].c) {
                letter = &LETTERS[j];
                found = true;
                break;
            }
        }

        // Encender segmentos
        for (int segment : self_SEGMENTS) {
            bool on = false;
            if (found) {
                on = __segment_in(segment, letter->Cc, letter->size);
            }
            else {
                on = (segment == self_g);
            }
            digitalWrite(segment, on ? self_state_on : self_state_off);
        }
        delay(seconds * 1000);
    }
}

void Display::print_char(char ch){//Muestra un caracter (- si no está disponible).
    const int L_A[] = {self_a, self_b, self_c, self_e, self_f, self_g};
    const int L_b[] = {self_c, self_d, self_e, self_f, self_g};
    const int L_c[] = {self_d, self_e, self_g};
    const int L_d[] = {self_b, self_c, self_d, self_e, self_g};
    const int L_E[] = {self_a, self_d, self_e, self_f, self_g};
    const int L_F[] = {self_a, self_e, self_f, self_g};
    const int L_g[] = {self_a, self_b, self_c, self_d, self_f, self_g};
    const int L_H[] = {self_b, self_c, self_e, self_f, self_g};
    const int L_h[] = {self_c, self_e, self_f, self_g};
    const int L_I[] = {self_e, self_f};
    const int L_i[] = {self_e};
    const int L_J[] = {self_b, self_c, self_d};
    const int L_L[] = {self_d, self_e, self_f};
    const int L_o[] = {self_c, self_d, self_e, self_g};
    const int L_P[] = {self_a, self_b, self_c, self_e, self_f, self_g};
    const int L_r[] = {self_e, self_f, self_g};
    const int L_S[] = {self_a, self_c, self_d, self_f, self_g};
    const int L_U[] = {self_b, self_c, self_d, self_e, self_f};
    const int L_u[] = {self_c, self_d, self_e};
    const int self_SEGMENTS[7] = {self_a, self_b, self_c, self_d, self_e, self_f, self_g};

    const PairC LETTERS[] = {
        {'A', L_A, sizeof(L_A) / sizeof(L_A[0])},
        {'a', L_A, sizeof(L_A) / sizeof(L_A[0])},
        {'B', L_b, sizeof(L_b) / sizeof(L_b[0])},
        {'b', L_b, sizeof(L_b) / sizeof(L_b[0])},
        {'C', L_c, sizeof(L_c) / sizeof(L_c[0])},
        {'c', L_c, sizeof(L_c) / sizeof(L_c[0])},
        {'D', L_d, sizeof(L_d) / sizeof(L_d[0])},
        {'d', L_d, sizeof(L_d) / sizeof(L_d[0])},
        {'E', L_E, sizeof(L_E) / sizeof(L_E[0])},
        {'e', L_E, sizeof(L_E) / sizeof(L_E[0])},
        {'F', L_F, sizeof(L_F) / sizeof(L_F[0])},
        {'f', L_F, sizeof(L_F) / sizeof(L_F[0])},
        {'G', L_g, sizeof(L_g) / sizeof(L_g[0])},
        {'g', L_g, sizeof(L_g) / sizeof(L_g[0])},
        {'H', L_H, sizeof(L_H) / sizeof(L_H[0])},
        {'h', L_h, sizeof(L_h) / sizeof(L_h[0])},
        {'I', L_I, sizeof(L_I) / sizeof(L_I[0])},
        {'i', L_i, sizeof(L_i) / sizeof(L_i[0])},
        {'J', L_J, sizeof(L_J) / sizeof(L_J[0])},
        {'j', L_J, sizeof(L_J) / sizeof(L_J[0])},
        {'L', L_L, sizeof(L_L) / sizeof(L_L[0])},
        {'l', L_L, sizeof(L_L) / sizeof(L_L[0])},
        {'O', L_o, sizeof(L_o) / sizeof(L_o[0])},
        {'o', L_o, sizeof(L_o) / sizeof(L_o[0])},
        {'P', L_P, sizeof(L_P) / sizeof(L_P[0])},
        {'p', L_P, sizeof(L_P) / sizeof(L_P[0])},
        {'R', L_r, sizeof(L_r) / sizeof(L_r[0])},
        {'r', L_r, sizeof(L_r) / sizeof(L_r[0])},
        {'S', L_S, sizeof(L_S) / sizeof(L_S[0])},
        {'s', L_S, sizeof(L_S) / sizeof(L_S[0])},
        {'U', L_U, sizeof(L_U) / sizeof(L_U[0])},
        {'u', L_u, sizeof(L_u) / sizeof(L_u[0])}
    };

    bool found = false;
    const PairC* letter = nullptr;

    // Buscar letra
    for (int j = 0; j < 32; j++) {
        if (ch == LETTERS[j].c) {
            letter = &LETTERS[j];
            found = true;
            break;
        }
    }

    // Encender segmentos
    for (int segment : self_SEGMENTS) {
        bool on = false;
        if (found) {
            on = __segment_in(segment, letter->Cc, letter->size);
        }
        else {
            on = (segment == self_g);
        }
        digitalWrite(segment, on ? self_state_on : self_state_off);
    }
}
void Display::high(void){//Enciende el display.
    const int self_SEGMENTS[7] = {self_a, self_b, self_c, self_d, self_e, self_f, self_g};
    for (int segment : self_SEGMENTS){
        digitalWrite(segment, self_state_on);
    }
}

void Display::low(void){//Apaga el display.
    const int self_SEGMENTS[7] = {self_a, self_b, self_c, self_d, self_e, self_f, self_g};
    for (int segment : self_SEGMENTS){
        digitalWrite(segment, self_state_off);
    }
}

bool Display::__segment_in(int s, const int *N, int size){
    bool segment_in = false;
    for(int i = 0; i < size; i++){
        if (s == N[i]){
            segment_in = true;
            break;
        }
    }
    return segment_in;
}