#include <stdio.h>
#include <stdint.h>

struct accelerometer_t {
    float ax, ay, az;
};

struct gyroscope_t {
    float gx, gy, gz;
};

struct mpu_status_t {
    int status_code;  // MPU:n tila
    int battery_level;  // Akun varausprosentti
};

struct mpu_sample_t {
    uint32_t timestamp;
    struct accelerometer_t accel;  // Kiihtyvyysanturin tiedot (ax, ay, az)
    struct gyroscope_t gyro;  // Gyroskoopin tiedot (gx, gy, gz)
    struct mpu_status_t status;  // Tilatiedot
};

void printcsv(struct mpu_sample_t *samples, int size);

void printcsv(struct mpu_sample_t *samples, int size) {
    for (int i = 0; i < size; i++) {
        if(samples[i].status.status_code == 2) {
            printf("%lu", (unsigned long)samples[i].timestamp);
            printf(",%.2f", samples[i].accel.ax);
            printf(",%.2f", samples[i].accel.ay);
            printf(",%.2f\n", samples[i].accel.az);
        }
    }
}
