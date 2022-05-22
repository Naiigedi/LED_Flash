#include <xc.h>

// CONFIG
#pragma config FOSC = INTOSC    // Oscillator Selection bits (INTOSC oscillator: CLKIN function disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)
#pragma config LPBOR = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

#define _XTAL_FREQ 8000000

int main(void) {
    TRISA = 0b000;//Output
    ANSELA = 0b000;//for Digital I/O
    int s = 0;
    while(1){
        if(RA3 == 0){
            s = s + 1;
            __delay_ms(200);
            if(s>3){
                s = 0;
                LATA2 = 0;
                __delay_ms(100);
                
            }
        }
        if(s == 0){  // OFF
            LATA2 = 0;
            __delay_ms(300);
        }
        if(s == 1){  // Blinking pattern 1
            LATA2 = 1;
            __delay_ms(500);
            LATA2 = 0;
            __delay_ms(500);
        }
        if(s == 2){  // Blinking pattern 2
            LATA2 = 1;
            __delay_ms(1000);
            LATA2 = 0;
            __delay_ms(500);
        }
        if(s == 3){  // ON
            LATA2 = 1;
            __delay_ms(300);
        }        
    }
}