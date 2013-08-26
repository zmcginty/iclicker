
#define F_CPU 1000000UL                                    /* Clock Frequency = 1Mhz */
#include <avr/io.h>
#include <util/delay.h>

int main(){
        // set PORTD for output
        DDRD = 0xF0;     //Set PortD Pin0 as an output
        while(1) {
                for(int i = 1; i <= 128; i = i*2){
                        PORTD = i;
                        _delay_loop_2(30000);
                        _delay_loop_2(30000);
                }
                for(int i = 128; i > 1; i -= i/2){
                        PORTD = i;
                        _delay_loop_2(30000);
                        _delay_loop_2(30000);
                }
        }
        return 1;
}
