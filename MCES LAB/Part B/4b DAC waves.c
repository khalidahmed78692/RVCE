#include <lpc214x.h>
#include <stdio.h>

#define PLOCK 0x00000400
#define LED_OFF (IOSET0=1U<<31)
#define LED_ON (IOCLR0=1U<<31)
#define SW2 (IOPIN0 & (1<<14))
#define SW3 (IOPIN0 & (1<<15))
#define SW4 (IOPIN1 & (1<<18))
#define SW5 (IOPIN1 & (1<<19))
#define SW6 (IOPIN1 & (1<<20))

void SystemInit(void);
static void delay_ms(unsigned int j);
short int sine_table[]={
	512+0,512+53,512+106,512+158,512+208,512+256,512+300,512+342,512+380,512+413,
	512+442,512+467,512+486,512+503,512+510,512+511,
	512+510,512+503,512+486,512+467,512+442,512+413,512+380,512+342,512+300,512+256,
	512+208,512+158,512+106,512+53,512+0,
	512-53,512-106,512-158,512-208,512-256,512-300,512-342,512-380,512-413,
	512-442,512-467,512-486,512-503,512-510,512-511,
	512-510,512-503,512-486,512-467,512-442,512-413,512-380,512-342,512-300,
	512-256,512-208,512-158,512-106,512-53};
short int sine_rect_table[]={
	512+0,512+53,512+106,512+158,512+208,512+256,512+300,512+342,512+380,512+413,
	512+442,512+467,512+486,512+503,512+510,512+511,
	512+510,512+503,512+486,512+467,512+442,512+413,512+380,512+342,512+300,512+256,
	512+208,512+158,512+106,512+53,512+0};

int main(){
	short int value,i=0;
	SystemInit();
	PINSEL1=0X00080000;
	IODIR0=1U<<31|0X00FF0000;
	while(1){
		if(!SW2){
			while(i!=60){
				value=sine_table[i++];
				DACR=((1<<16)|(value<<6));
				delay_ms(1);
			}
			i=0;
		}
		else if(!SW3){
			while(i!=30){
				value=sine_rect_table[i++];
				DACR=((1<<16)|(value<<6));
				delay_ms(1);
			}
			i=0;
		}
		else if(!SW4){
			value=0;
			while(value!=1023){
				DACR=((1<<16)|(value<<6));
				value++;
			}
			while(value!=0){
				DACR=((1<<16)|(value<<6));
				value--;
			}
		}
		else if(!SW5){
			value=0;
			while(value!=1023){
				DACR=((1<<16)|(value<<6));
				value++;
			}
		}
		else if(!SW6){
			value=1023;
			DACR=((1<<16)|(value<<6));
			delay_ms(1);
			value=0;
			DACR=((1<<16)|(value<<6));
			delay_ms(1);
		}
		else{
			value=1023;
			DACR=((1<<16)|(value<<6));
		}
	}
}

void SystemInit(void){
	PLL0CON=0X01;
	PLL0CFG=0X24;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
	while(!(PLL0STAT&PLOCK)){;}
	PLL0CON=0X03;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
}

void delay_ms(unsigned int j){
	unsigned int x,i;
	for(i=0;i<j;i++)
		for(x=0;x<10000;x++);
}
