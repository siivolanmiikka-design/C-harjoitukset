#include <stdio.h>
#include <math.h>
#include <stdint.h>

struct piste {
  int koordinaatit[3];
  struct piste *seuraava;
};

struct polku {
  double matka;
  struct piste *pisteet;
};

void laske_kuljettu_matka(struct polku *polku);

void laske_kuljettu_matka(struct polku *polku) {

    polku->matka = 0;
    struct piste *nyt = polku->pisteet;

    while (nyt != NULL && nyt->seuraava != NULL) {
        polku->matka += sqrt(pow(nyt->koordinaatit[0] - nyt->seuraava->koordinaatit[0], 2)
                            + pow(nyt->koordinaatit[1] - nyt->seuraava->koordinaatit[1], 2)
                            + pow(nyt->koordinaatit[2] - nyt->seuraava->koordinaatit[2], 2));
        nyt = nyt->seuraava;
    }
}