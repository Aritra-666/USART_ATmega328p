#define PORTB *((volatile unsigned char *)0x25) 
#define DDRB *((volatile unsigned char *)0x24)
#define UDR0 *((volatile unsigned char *)0xC6)
#define UBRROH *((volatile unsigned char *)0xC5)
#define UBRROL *((volatile unsigned char *)0xC4)
#define UCSR0C *((volatile unsigned char *)0xC2)
#define UCSR0B *((volatile unsigned char *)0xC1)
#define UCSR0A *((volatile unsigned char *)0xC0)


