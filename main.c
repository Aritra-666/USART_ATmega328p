#include "usart.h"

#define F_CLK 16000000UL                //sets the clk frequency to 16MHz
#define UBRR_VALUE(x) F_CLK/16/x-1  //Formula to calculate UBRR's value

int usart_init(int x){

    unsigned int UBRR = UBRR_VALUE(x); 
    
    UBRR0H = (unsigned char)(UBRR>>8);   // sets the higher bits
    UBRR0L = (unsigned char)UBRR;        // sets the lower bits
    
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

    char str[] = "Hello World!!";

    DDRB |= (1 << 5);
 
    usart_init(9600);  //initialize hardware
    
    while(1){
    
        int index;
        
        usart_transmit('\r');
        
        for( index = 0 ; str[index] != '\0' ; index++){
        
            PORTB |= (1<<5);                        //turn on the led indicator
            
            for( long int i = 0; i<=500000 ; i++){}  //delay
            
            usart_transmit(str[index]);                    //transmit char
            
            PORTB &= ~(1<<5);                       //turn off the led indicator
        }
        
        for( unsigned long int i = 0; i<=1000000 ; i++){}  //delay
        
        index=0;
        
        usart_transmit('\n');
        
    
    }
 
    return 0;

}
