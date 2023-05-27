#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRA=0b11111111; //making port A as outport port
PORTA=0b00000000;
while(1)
{
	PORTA=0b00000000;
	_delay_ms(1000);
	PORTA=0b00000001;
	_delay_ms(1000);
	PORTA=0b00000010;
	_delay_ms(1000);
	PORTA=0b0000011;
	_delay_ms(1000);
	PORTA=0b00000100;
	_delay_ms(1000);
	PORTA=0b00000101;
	_delay_ms(1000);
	PORTA=0b00000110;
	_delay_ms(1000);
	PORTA=0b00000111;
	_delay_ms(1000);
}
}	
	