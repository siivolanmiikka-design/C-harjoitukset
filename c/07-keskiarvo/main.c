#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float keskiarvo(char *lista);

int main(void) {
    char lista[] = "201,53,12,31,5";
    printf("%.1f\n", keskiarvo(lista));
}

float keskiarvo(char *lista) {
    char *token;
    token = strtok(lista, ",");
    int summa = 0;
    int maara = 0;

    while(token != NULL) {
        summa += atoi(token);
        maara++;

        token = strtok(NULL, ",");
    }
    if(maara == 0) return 0;
    return (float) summa / maara;
}