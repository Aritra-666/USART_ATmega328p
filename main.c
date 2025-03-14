#include "usart.h"

#define F_CLK 16000000UL                //sets the clk frequency to 16MHz
#define UBRR_VALUE(x) (F_CLK/(16*x)-1)  //Formula to calculate UBRR's value

int usart_init(int x){

    unsigned long int UBRR = UBRR_VALUE(x); 
    
    UBRR0H = (UBRR>>8);   // sets the higher bits
    UBRR0L = UBRR;        // sets the lower bits
    
    UCSR0C |= (3<<1);      //sets UCSZ01 and UCSZ00 for 8 bit
    
    UCSR0B |= (3<<3);      //Enable TX and RX
    
    return 0;
}

int usart_transmit(char ch){

    while(!(UCSR0A & (1<<5))){}   //wait for the buffer to be empty
    
    UDR0 = ch;  // write the char in buffer
    
    return 0;
}


int main(void){

    DDRB |= (1 << 5);
 
    usart_init(9600);  //initialize hardware
    
    while(1){
    
        for( long int i = 0; i<=50000 ; i++){}
        PORTB |= (1<<5);   //turn off the led indicator
        
        usart_transmit('A');  //transmit char 'A'
        
        for( long int i = 0; i<=50000 ; i++){}
        PORTB &= ~(1<<5);    //turn on the led indicator
    }
 
    return 0;

}
