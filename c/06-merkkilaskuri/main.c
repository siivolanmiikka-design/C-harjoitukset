#include <stdio.h>
#include <stdint.h>

void merkkilaskuri(char *str, uint8_t *tulos);

void merkkilaskuri(char *str, uint8_t *tulos) {
    tulos[0] = 0;
    tulos[1] = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    tulos[0]++;
                } else tulos[1]++;
        }
    }
}

int main(void) {
    uint8_t tulos[2];
    merkkilaskuri("Hello, World!", tulos);
    printf("vokaalit: %d, konsonantit: %d\n", tulos[0], tulos[1]);
    return 0;
}