#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void shuffle(uint8_t *list, uint16_t list_size);

void shuffle(uint8_t *list, uint16_t list_size) {
    //Mikäli taulukko sisältää vain yhden alkion, paha mennä sekoittamaan :)
    if (list_size <= 1) {
        return;
    }
    //Alustetaan temp-taulukko ja remaining muuttuja.
    uint8_t temp[list_size];
    uint16_t remaining = list_size;
    //Kopioidaan alkuperäisen taulukon alkiot temp-taulukkoon.
    for (uint16_t i = 0; i < list_size; i++) {
        temp[i] = list[i];
    }

    for (uint16_t i = 0; i < list_size; i++) {
        uint16_t j = rand() % remaining;

        list[i] = temp[j];

        for(;j < remaining - 1; j++) {
            temp[j] = temp[j + 1];
        }

        remaining--;
    }
}