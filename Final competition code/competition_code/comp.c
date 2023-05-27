#include<avr/io.h>
#include<util/delay.h>

void init_adc()
{
	ADCSRA=ADCSRA|(0b00000001<<ADEN); // Enable ADC
	ADCSRA=ADCSRA|(0b00000001<<ADPS2);//Sampling rate select
	ADMUX|=(0b00000001<<REFS0);// Voltage reference
}

int readpot_adc()
{
	int p=0b00000000; // pot connected to ADC0
	ADMUX=ADMUX|p; // Input pin
	ADCSRA=ADCSRA|(0b00000001<<ADSC); //Start of Conversion
	while(ADCSRA&(0b00000001<<ADIF)==0); // Until conversion stops
	ADCSRA=ADCSRA|(0b00000001<<ADIF);// Clearing ADIF pin
	return(ADC);
}	
	
void main()
{
	DDRD=0b00000000; // port D input, sensors. right and left- line, middle-obstacle, another-cave.
	DDRB=0b11111111; //output, motor and buzzer
	PORTD=0b11111111; // port D pull-up
	init_adc(); //initialising ADC0
	_delay_ms(50);
	unsigned int a,p,T,TON,TOFF; // for PWM
	int c;
	
	while(1)
	{   
	    p=readpot_adc(); // reads pot;s analog value, converts it, and returns digital value to p
		a=p/40; // scaling factor 40
		T=25.6; // scaled value of max time 1024 (# of quantisation levels)
		TOFF=a; 
		TON=T-TOFF;
		
		c=PIND;
		
		if(c==0b11111010)        // 0- light line, 1- no obstacle.
			PORTB=0b00001010;
			
		if(c==0b11111011)
			PORTB=0b00001001;
			
		if(c==0b11111000)
			PORTB=0b00010000;
			
		if(c==0b11111001)
			PORTB=0b00010000;
			
		if(c==0b11111100)
			PORTB=0b00010000;
			
		if(c==0b11111101)
			PORTB=0b00010000;
			
		if(c==0b11111110)
			PORTB=0b00000110;
			
		if(c==0b11111111)
			PORTB=0b00011010;
		
		// TILL THIS, NO CAVE
		// FROM NOW, WE HAVE CAVE
		
		if(c==0b11110010)        // 0- light line, 1- no obstacle, another 0 means presence of cave
		{	
			PORTB=0b00001010;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
			
		if(c==0b11110011)
		{	
			PORTB=0b00001001;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		
			
		if(c==0b11110000)
		{
			PORTB=0b00010000;
			_delay_ms(TON);
			PORTB=0b00010000;
			_delay_ms(TOFF);
		}
		
		if(c==0b11110001)
		{
			PORTB=0b00010000;
			_delay_ms(TON);
			PORTB=0b00010000;
			_delay_ms(TOFF);
		}
			
			
		if(c==0b11110100)
		{
			PORTB=0b00010000;
			_delay_ms(TON);
			PORTB=0b00010000;
			_delay_ms(TOFF);
		}
			
		if(c==0b11110101)
		{
			PORTB=0b00010000;
			_delay_ms(TON);
			PORTB=0b00010000;
			_delay_ms(TOFF);
		}
			
		if(c==0b11110110)
		{	
			PORTB=0b00000110;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
			
		if(c==0b11110111)
		{
			PORTB=0b00011010;
			_delay_ms(TON);
			PORTB=0b00010000;
			_delay_ms(TOFF);
		}
	}
}