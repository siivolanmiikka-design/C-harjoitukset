#include <stdio.h>
#include <stdint.h>
#define DATA_MASK 0x07F8
#define RW_BIT 1
#define RESET_BIT 0
#define SET(reg, bit) ((reg) |= (uint16_t) (1U << (bit)))
#define CLEAR(reg, bit) ((reg) &= (uint16_t) ~(1U << (bit)))

void write_data_to_LCD(uint16_t* lcd_register, uint8_t data);
void reset_LCD(uint16_t* lcd_register);

// Write data to the LCD
void write_data_to_LCD(uint16_t* lcd_register,uint8_t data) {
    // Clear previous data
    *lcd_register = *lcd_register & ~DATA_MASK;// 0b0000011111111000
    // Set the new data
    *lcd_register = *lcd_register | ((uint16_t)data << 3); 
    // Clear the R/W bit to indicate we are in a writing operation
    CLEAR(*lcd_register,RW_BIT);
}

// Reset the LCD. It needs to put to 1 the Reset bit
void reset_LCD(uint16_t* lcd_register) {
    SET(*lcd_register,RESET_BIT);
}

// Write data on the LCD and then reset it.
int main() {
    uint16_t lcd_register = 0x00C8;
    write_data_to_LCD(&lcd_register,0x19);
    printf("Writen data to LCD. LCD register contain: %#06X \n",lcd_register);
    reset_LCD(&lcd_register);
    printf("Resetting register. LCD register contain: %#06X \n",lcd_register);

    return 0;
}