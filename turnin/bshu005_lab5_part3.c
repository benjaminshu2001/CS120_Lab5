/*	Author: bshu005
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * Link to Demo: https://www.youtube.com/watch?v=9Mhgg_59BOo
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Init, Wait1, Light1, Wait2, Light2, Wait3, Light3, Wait4, Light4, Wait5, Light5, Wait6, Light6, Wait} State;

void Tick_LED() {
    switch(State) {
        case Start:
            State = Init;
            break;
        case Init:
            if((~PINA & 0x01) == 0x01) {
                State = Light1;
            }
            else {
                State = Init;
            }
            break;
        case Light1:
            if((~PINA & 0x01) == 0x01) {
                State = Light1;
            }
            else {
                State = Wait1;
            }
            break;
        case Wait1:
            if((~PINA & 0x01) == 0x01) {
                State = Light2;
            }
            else {
                State = Wait1;
            }
            break;
        case Light2:
            if((~PINA & 0x01) == 0x01) {
                State = Light2;
            }
            else {
                State = Wait2;
            }
            break;
        case Wait2:
            if((~PINA & 0x01) == 0x01) {
                State = Light3;
            }
            else {
                State = Wait2;
            }
            break;
        case Light3:
            if((~PINA & 0x01) == 0x01) {
                State = Light3;
            }
            else {
                State = Wait3;
            }
            break;
        case Wait3:
            if((~PINA & 0x01) == 0x01) {
                State = Light4;
            }
            else {
                State = Wait3;
            }
            break;
        case Light4:
            if((~PINA & 0x01) == 0x01) {
                State = Light4;
            }
            else {
                State = Wait4;
            }
            break;
        case Wait4:
            if((~PINA & 0x01) == 0x01) {
                State = Light5;
            }
            else {
                State = Wait4;
            }
            break;
        case Light5:
            if((~PINA & 0x01) == 0x01) {
                State = Light5;
            }
            else {
                State = Wait5;
            }
            break;
        case Wait5:
            if((~PINA & 0x01) == 0x01) {
                State = Light6;
            }
            else {
                State = Wait5;
            }
            break;
        case Light6:
            if((~PINA & 0x01) == 0x01) {
                State = Light6;
            }
            else {
                State = Wait6;
            }
            break;
        case Wait6:
            if((~PINA & 0x01) == 0x01) {
                State = Wait;
            }
            else {
                State = Wait6;
            }
            break;
        case Wait:
            if((~PINA & 0x01) == 0x01) {
                State = Wait;
            }
            else {
                State = Init;
            }
            break;
        default:
            PORTB = 0x00;
            break;
    }   
    switch(State) {
        case Start:
            PORTB = 0x00;
            break;
        case Init:
            PORTB = 0x00;
            break;
        case Light1:
            PORTB = 0x01;
            break;
        case Wait1:
            PORTB = 0x01;
            break;
        case Light2:
            PORTB = 0x02;
            break;
        case Wait2:
            PORTB = 0x02;
            break;
        case Light3:
            PORTB = 0x04;
            break;
        case Wait3:
            PORTB = 0x04;
            break;
        case Light4:
            PORTB = 0x08;
            break;
        case Wait4:
            PORTB = 0x08;
            break;
        case Light5:
            PORTB = 0x10;
            break;
        case Wait5:
            PORTB = 0x10;
            break;
        case Light6:
            PORTB = 0x20;
            break;
        case Wait:
            PORTB = 0x00;
            break;
    } 
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    State = Start;
    while (1) {
        Tick_LED();
    }
    return 0;
}
