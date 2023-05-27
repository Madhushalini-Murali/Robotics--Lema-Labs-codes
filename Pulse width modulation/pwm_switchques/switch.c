#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRD=0b00000000; //port D input (TO CONNECT SWITCH)
	DDRA=0b11111111;  //port A output
	PORTD=0b11111111;	//port D pull up
	int c;
	while(1)
	{
	  c=PIND;
	  if(c==0b11111110)
	    PORTA=0b00000000;
	  else
		PORTA=0b00000001;
	}	
}