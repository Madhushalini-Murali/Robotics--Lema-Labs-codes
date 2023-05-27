#include<avr/io.h>
#include<util/delay.h>
void main()
{
	DDRD=0b00000000; // port D input, sensors. right and left- line, middle-obstacle, another-cave.
	DDRB=0b11111111; //output, motor and buzzer
	PORTD=0b11111111; // port D pull-up
	int c;
	
	while(1)
	{   
	    
		
		c=PIND;
		if(c==0b11111010)        // 0- light line, 1- no obstacle.
			PORTB=0b00001010;
			
		if(c==0b11111011)
			PORTB=0b00001001;
			
		if(c==0b11111000)
		
			PORTB=0b00000000;
			
		if(c==0b11111001)
			PORTB=0b00000000;
			
		if(c==0b11111100)
			PORTB=0b00000000;
			
		if(c==0b11111101)
			PORTB=0b00000000;
			
		if(c==0b11111110)
			PORTB=0b00000110;
			
		if(c==0b11111111)
			PORTB=0b00001010;
	}
}