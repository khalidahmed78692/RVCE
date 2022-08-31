#include <lpc214x.h>

#define LED_ON (IOSET0=1<<21)
#define LED_OFF (IOCLR0=1<<21)

void delay_ms(unsigned char);

int main(){
	unsigned int i;
	IODIR0=1<<21;
	PINSEL1=1<<24; // P0.28 pin is connected to light sensor
	LED_ON;
	do{
		AD0CR=1<<1|1<<21|1<<24; // AD0.1 channel is selected
		while((AD0GDR&1U<<31)==0);
		i=(AD0GDR>>6)&0X3FF;
		if(i>100)
			LED_OFF;
		else
			LED_ON;
		delay_ms(10);
	}while(1);
}

void delay_ms(unsigned char i){
	for(unsigned char j=0;j<i;j++)
		for(unsigned int x=0;x<10000;x++);
}
