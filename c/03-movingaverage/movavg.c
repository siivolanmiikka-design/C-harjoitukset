#include <stdio.h>
#include <inttypes.h>

void movavg(float *array, uint8_t array_size, uint8_t window_size);

void movavg(float *array, uint8_t array_size, uint8_t window_size) {

    for(uint16_t i = 0; i <= array_size - window_size; i++) {
        float sum = 0.0f;

        for(uint16_t j = i; j < i + window_size; j++) {
            sum += array[j];
        }

        float avg = (float) sum / window_size;

        if(i > 0) {
            printf(",");
        }
        printf("%.2f", avg);
    }
}
