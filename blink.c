#pragma config FOSC = EXTRC // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON // Low-Voltage Programming enabled
#pragma config CPD = OFF // Data EEPROM Code Protection off
#pragma config WRT = OFF // Flash Program Memory Write Enable off
#pragma config CP = OFF // Flash Program Memory Code Protection off

#include <xc.h>

#define _XTAL_FREQ 20000000

static void init_config(void){
TRISB = 0xFF; // PORTB all inputs (for buttons)
PORTB = 0x00; // Clear PORTB latch
TRISC = 0x00; // PORTC all outputs (for LEDs)
PORTC = 0x00; // Clear PORTC latch
}

void main(void) {
init_config();
while(1){
// Check status of push button connected to RB7
if(PORTBbits.RB7 == 1){
PORTCbits.RC0 = 1; // Turn ON LED at RC0
}
// Check status of push button connected to RB1
else if(PORTBbits.RB1 == 0){
PORTCbits.RC3 = 1; // Turn ON LED at RC3
}
else {
PORTCbits.RC3 = 0; // Turn OFF LEDs
PORTCbits.RC0 = 0;
}
}
}
