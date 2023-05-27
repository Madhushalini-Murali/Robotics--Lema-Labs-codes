#include<avr/io.h>
#include<util/delay.h>

void init_adc()
{
	ADCSRA=ADCSRA|(0b00000001<<ADEN);
	ADCSRA=ADCSRA|(0b00000001<<ADPS2);
	ADMUX=ADMUX|(0b00000001<<REFS0);

}

unsigned int read_adc1()
{
	int p=0b00000001;
	ADMUX=ADMUX&(0b11111000);
	ADMUX=ADMUX|p;
	ADCSRA=ADCSRA|(0b00000001<<ADSC);
	while((ADCSRA&(0b00000001<<ADIF))==0)
	{}
	ADCSRA=ADCSRA|(0b00000001<<ADIF);
	
	return(ADC);
}

unsigned int read_adc0()
{
	int q=0b00000000;
	ADMUX=ADMUX&(0b11111000);
	ADMUX=ADMUX|q;
	ADCSRA=ADCSRA|(0b00000001<<ADSC);
	while((ADCSRA&(0b00000001<<ADIF))==0)
	{}
	ADCSRA=ADCSRA|(0b00000001<<ADIF);
	
	return(ADC);
}


void main()
{   DDRB=0b11111111;
	init_adc();
	unsigned int a;
	unsigned int p;
	unsigned int q;
	unsigned int T;
	unsigned int TON;
	unsigned int TOFF;
	
	while(1)
	{
		p=read_adc1();
		q=read_adc0();
		a=(p/40);
		T=25.6;
		TOFF=a;
		TON=T-TOFF;
	

		if((q<=1024)&&(q>=756))
			{	PORTB=0b00001001;
				_delay_ms(TON);
				PORTB=0b00000000;
				_delay_ms(TOFF);
			}	
			else if((q<756)&&(q>=512))
			{	PORTB=0b00000110;
				_delay_ms(TON);
				PORTB=0b00000000;
				_delay_ms(TOFF);
			}
				else if((q<512)&&(q>=256))
			{	PORTB=0b00000101;
				_delay_ms(TON);
				PORTB=0b00000000;
				_delay_ms(TOFF);
			}
				else
			{	PORTB=0b00001010;
				_delay_ms(TON);
				PORTB=0b00000000;
				_delay_ms(TOFF);
			}
	}	

}		