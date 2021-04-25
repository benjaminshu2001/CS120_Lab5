/*	Author: bshu005
 *  Partner(s) Name: None
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempA = 0x00;
    unsigned char tempC = 0x00;
	while(1) {
		// 1) Read input
		tempA = ~PINA & 0x0F; //0010 1101 = 8 + 4 + 1 = 13
        
		switch(tempA) {
            case 15:
            case 14:
            case 13:
                tempC = 0x3F; //13-15 ==> PC5-PC0 on, 0011 1111
                break;
            case 12:
            case 11:
            case 10:
                tempC = 0x3E; //10-12 ==> PC5-PC1 on, 0011 1110
                break;
            case 9:
            case 8:
            case 7: 
                tempC = 0x3C;  //7-9 ==> PC5-PC2 on, 0011 1100
                break;
            case 6:
            case 5:
                tempC = 0x38; //5-6 ==> PC5-PC3 on, 0011 1000
                break;
            case 4:
            case 3:
                tempC = 0x70; //3-4 ==> PC5-PC4 on, 0111 0000, PC6 = 1 since level <=4
                break;   
            case 2:
            case 1:
                tempC = 0x60;  //1-2 ==> PC5 on, PC6 = 1, 0110 0000
	            break;
            default:
                tempC = 0x40;
                break;
        }
        PORTC = tempC;
    }   
	return 1;
}
