// this program enables SPI communication and
// // Sets the AVR into Master mode


#include <avr/io.h>


int main (void){
	char data;

		DDRB |= (1<<2)|(1<<3)|(1<<5);    // SCK, MOSI and SS as outputs
		DDRB &= ~(1<<4);                 // MISO as input
//		SPCR |= (1<<MSTR);               // Set as Master
//		SPCR |= (1<<SPR0)|(1<<SPR1);     // divided clock by 128
//		SPCR |= (1<<SPE);                // Enable SPI

		SPCR == 01011001;
		PORTB |= (1<<3);

		while(1){
			SPDR = data;                 // send the data
			while(!(SPSR & (1<<SPIF)));  // wait until transmission is complete

// if you have multiple slaves, this is where you want to switch
            }
            }
