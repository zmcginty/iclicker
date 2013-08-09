iclicker
========

warning-assembly


Another security analysis of the iclicker


The iclicker is a 900MHz band voting device for which each remote has a unique identifier number which is an 
8-byte hex word. The remote can be used in a classroom setting to let people vote for A,B,C,D or E. This iclicker
ID is really only 6 hex-bytes with the last two as a checksum(still unclear as to the exact calculation of this 
checksum). 

After opening the iclicker’s plastic case I found that there is only one PCB which contains everything including 
the RF antenna. From my observation I found multiple sections of the PCB. One section contained the voltage input
from the battery and a few transistors (probably regulators) going to the two main IC’s on the board. There were 
also the power and A,B,C,D,E vote buttons and a section of discrete circuitry around the transceiver which included 
an IC switch which went from the antenna to the RX and TX pins of the transceiver which is assumed to swtich
between transmit and receive mode. There is also a 6 pin spi pad near the ATMEGA 8 microcontroller which is the 
read/write programming debugging interface to the microcontroller. 

The two main IC’s on the board were identified as the Atmel ATMEGA 8 8-bit avr-core microprocessor and the Semtech
XE1203F 433, 868, 915 MHz band RF transceiver. Two main data lines were traced which go between the two IC’s.
One of which was an SPI line coming from the (3-wire) SPI pins (PORTB) on the ATMEGA 8 going to the 3-wire
configuration serial pins on the XE1203F. A raw data line was also found coming from PORTD of the ATMEGA 8 which 
is the UART section of the microcontroller. This raw data line goes to the DATA pin on the XE1203F and includes 
a synchronous clock signal and a SWITCH line which is used to declare a data direction/who generates the clock of
a given communication session. I believe this SWITCH line is used to use the transceiver as both a receiver and 
transmitter setting the line to send when the microcontroller wants the transceiver to transmit data on the DATA
line, and set to receive(other data direction) when the microcontroller wanted the transceiver to listen for a
signal, although I’m not completely sure how the triggering and interrupts work for this sequence. 
