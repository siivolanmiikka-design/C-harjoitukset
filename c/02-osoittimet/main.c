#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void shuffle (uint8_t *list, uint16_t list_size);

int main(void) {
    srand((unsigned int)time(NULL));

    uint8_t list[8] = {1, 2,  3, 4, 5, 6, 7, 8};

    shuffle(list, 8);

    printf("Tulos: {");
    for(int i = 0; i < 8; i++) {
        printf("%d%s", list[i], (i < 7) ? ", " : "");
    }
    printf("}\n");
}

void shuffle(uint8_t *list, uint16_t list_size) {

    if (list_size <= 1) {
        return;
    }

    uint8_t temp[list_size];
    uint16_t remaining = list_size;

    for (uint16_t i = 0; i < list_size; i++) {
        temp[i] = list[i];
    }

    for (uint16_t i = 0; i < list_size; i++) {
        uint16_t j = rand() % remaining;

        list[i] = temp[j];

        for(; j < remaining - 1; j++) {
            temp[j] = temp[j + 1];
        }

        remaining--;
    }
}
