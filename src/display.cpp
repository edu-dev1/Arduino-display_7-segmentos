#include <display.h>
        
Display::Display(uint16_t a, uint16_t b, uint16_t c, uint16_t d, uint16_t e, uint16_t f, uint16_t g, bool common_cathode){
    __a = a;
    __b = b;
    __c = c;
    __d = d;
    __e = e;
    __f = f;
    __g = g;
    __common_cathode = common_cathode;

    if (__common_cathode){
        __state_on = HIGH;
        __state_off = LOW;
    }else{
        __state_on = LOW;
        __state_off = HIGH;
    }

    const uint16_t seg_aux[S] = {__a, __b, __c, __d, __e, __f, __g};
    for(int i = 0; i < S; i++){
        __segments[i] = seg_aux[i];
        pinMode(__segments[i], OUTPUT);
    }

}

Display::Display(uint16_t segments[S], bool common_cathode){
    
    __a = segments[0];
    __b = segments[1];
    __c = segments[2];
    __d = segments[3];
    __e = segments[4];
    __f = segments[5];
    __g = segments[6];

    const uint16_t seg_aux[S] = {__a, __b, __c, __d, __e, __f, __g};
    for(int i = 0; i < S; i++){
        __segments[i] = seg_aux[i];
        pinMode(__segments[i], OUTPUT);
    }
    
    __common_cathode = common_cathode;
    if (__common_cathode){
        __state_on = HIGH;
        __state_off = LOW;
    }else{
        __state_on = LOW;
        __state_off = HIGH;
    }
}

void Display::print(int number){

    const uint16_t N0[6] = {__a, __b, __c, __d, __e, __f};
    const uint16_t N1[2] = {__b, __c};
    const uint16_t N2[5] = {__a, __b, __d, __e, __g};
    const uint16_t N3[5] = {__a, __b, __c, __d, __g};
    const uint16_t N4[4] = {__b, __c, __f, __g};
    const uint16_t N5[5] = {__a, __c, __d, __f, __g};
    const uint16_t N6[6] = {__a, __c, __d, __e, __f, __g};
    const uint16_t N7[3] = {__a, __b, __c};
    const uint16_t N8[7] = {__a, __b, __c, __d, __e, __f, __g};
    const uint16_t N9[5] = {__a, __b, __c, __f, __g};
    
    const PairN NUMBERS[PairsN] = {
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

    for (uint16_t i = 0; i < S; i++){
        bool on = false;
        for (int j = 0; j < PairsN; j++){
            if (NUMBERS[j].n == number){
                on = __segment_in(__segments[i], NUMBERS[j].Nn, NUMBERS[j].size);
                break;
            }
        }
        digitalWrite(__segments[i], on ? __state_on : __state_off);
    }
}

void Display::print(char* string, unsigned long ms){
    const uint16_t L_A[] = {__a, __b, __c, __e, __f, __g};
    const uint16_t L_b[] = {__c, __d, __e, __f, __g};
    const uint16_t L_c[] = {__d, __e, __g};
    const uint16_t L_d[] = {__b, __c, __d, __e, __g};
    const uint16_t L_E[] = {__a, __d, __e, __f, __g};
    const uint16_t L_F[] = {__a, __e, __f, __g};
    const uint16_t L_g[] = {__a, __b, __c, __d, __f, __g};
    const uint16_t L_H[] = {__b, __c, __e, __f, __g};
    const uint16_t L_h[] = {__c, __e, __f, __g};
    const uint16_t L_I[] = {__e, __f};
    const uint16_t L_i[] = {__e};
    const uint16_t L_J[] = {__b, __c, __d};
    const uint16_t L_L[] = {__d, __e, __f};
    const uint16_t L_o[] = {__c, __d, __e, __g};
   const uint16_t L_P[] = {__a, __b, __e, __f, __g};
    const uint16_t L_r[] = {__e, __f, __g};
    const uint16_t L_S[] = {__a, __c, __d, __f, __g};
    const uint16_t L_U[] = {__b, __c, __d, __e, __f};
    const uint16_t L_u[] = {__c, __d, __e};

    const PairC LETTERS[PairsC] = {
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
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == ' ') {
            low();
            delay(ms);
        }

        bool found = false;
        const PairC* letter = nullptr;

        // Buscar letra
        for (int j = 0; j < PairsC; j++) {
            if (string[i] == LETTERS[j].c) {
                letter = &LETTERS[j];
                found = true;
                break;
            }
        }

        // Encender segmentos
        for (uint16_t i = 0; i < S; i++) {
            bool on = false;
            if (found) {
                on = __segment_in(__segments[i], letter->Cc, letter->size);
            }
            else {
                on = (__segments[i] == __g);
            }
            digitalWrite(__segments[i], on ? __state_on : __state_off);
        }
        delay(ms);
        i++;
    }
}

void Display::print(char character){
    const uint16_t L_A[] = {__a, __b, __c, __e, __f, __g};
    const uint16_t L_b[] = {__c, __d, __e, __f, __g};
    const uint16_t L_c[] = {__d, __e, __g};
    const uint16_t L_d[] = {__b, __c, __d, __e, __g};
    const uint16_t L_E[] = {__a, __d, __e, __f, __g};
    const uint16_t L_F[] = {__a, __e, __f, __g};
    const uint16_t L_g[] = {__a, __b, __c, __d, __f, __g};
    const uint16_t L_H[] = {__b, __c, __e, __f, __g};
    const uint16_t L_h[] = {__c, __e, __f, __g};
    const uint16_t L_I[] = {__e, __f};
    const uint16_t L_i[] = {__e};
    const uint16_t L_J[] = {__b, __c, __d};
    const uint16_t L_L[] = {__d, __e, __f};
    const uint16_t L_o[] = {__c, __d, __e, __g};
    const uint16_t L_P[] = {__a, __b, __e, __f, __g};
    const uint16_t L_r[] = {__e, __f, __g};
    const uint16_t L_S[] = {__a, __c, __d, __f, __g};
    const uint16_t L_U[] = {__b, __c, __d, __e, __f};
    const uint16_t L_u[] = {__c, __d, __e};
     
    const PairC LETTERS[PairsC] = {
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
    for (int j = 0; j < PairsC; j++) {
        if (character == LETTERS[j].c) {
            letter = &LETTERS[j];
            found = true;
            break;
        }
    }

    // Encender segmentos
    for (uint16_t i = 0; i < S; i++) {
        bool on = false;
        if (found) {
            on = __segment_in(__segments[i], letter->Cc, letter->size);
        }
        else {
            on = (__segments[i] == __g);
        }
        digitalWrite(__segments[i], on ? __state_on : __state_off);
    }
}
void Display::high(void){
    for (uint16_t s = 0; s < S; s++){
        digitalWrite(__segments[s], __state_on);
    }
}

void Display::low(void){
    for (uint16_t s = 0; s < S; s++){
        digitalWrite(__segments[s], __state_off);
    }
}

bool Display::__segment_in(uint16_t s, const uint16_t *N, uint16_t size){
    bool segment_in = false;
    for(uint16_t i = 0; i < size; i++){
        if (s == N[i]){
            segment_in = true;
            break;
        }
    }
    return segment_in;
}
