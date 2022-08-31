#include <lpc214x.h>

#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
#define SW2 (IO0PIN & (1 << 14))

void delay_ms(unsigned int j);

int main( )
{
	IO0DIR = 1U << 31;
	IO0SET = 1U << 31;
	while(1){
		if (!(IO0PIN & (1 << 14))){ // (if(!SW2 )
			IO0CLR = 1U << 31; //LED_ON
			delay_ms(250);
			IO0SET = 1U << 31; //LED_OFF
			delay_ms(250);
		}
	}
}

void delay_ms(unsigned int j) // assume delay_ms(1) produces 1ms
{
  unsigned int x, i;
  for(i=0; i<j; i++){
    for(x=0; x<1000; x++);
  }
}
