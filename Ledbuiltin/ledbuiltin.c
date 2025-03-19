#include <avr/io.h>       // AVR register definitions
#include <util/delay.h>   // For delay functions

int main(void) {
    DDRB |= (1 << DDB5);  // Set PB5 (pin 13) as output

    while (1) {
        PORTB |= (1 << DDB5);  // Set PB5 high (turn LED ON)
        _delay_ms(1000);       // Delay for 500 milliseconds

        PORTB &= ~(1 << DDB5); // Set PB5 low (turn LED OFF)
        _delay_ms(1000);       // Delay for 500 milliseconds
    }

    return 0;
}