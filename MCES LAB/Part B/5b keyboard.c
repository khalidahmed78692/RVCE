#include <lpc214x.h>

#define PLOCK 0x00000400
#define LED_ON (IOSET0=0X80000000)
#define COL0 (IOPIN1&1<<19)
#define COL1 (IOPIN1&1<<18)
#define COL2 (IOPIN1&1<<17)
#define COL3 (IOPIN1&1<<16)

unsigned char lookup_table[4][4]=       {{'0','1','2','3'},
					{'4','5','6','7'},
					{'8','9','a','b'},
					{'c','d','e','f'}};

void delay_ms(unsigned int);
void uart_init(void);
void SystemInit(void);

int main(){
	SystemInit();
	uart_init();
	IODIR0=0X000F000|1U<<31;
	LED_ON;
	unsigned char rowsel,colsel;
	while(1){
		while(1){
			rowsel=0;IO0SET=0X000F0000;IO0CLR=1<<16;
			if(COL0==0){colsel=0;break;}
			if(COL1==0){colsel=1;break;}
			if(COL2==0){colsel=2;break;}
			if(COL3==0){colsel=3;break;}
			rowsel=1;IO0SET=0X000F0000;IO0CLR=1<<17;
			if(COL0==0){colsel=0;break;}
			if(COL1==0){colsel=1;break;}
			if(COL2==0){colsel=2;break;}
			if(COL3==0){colsel=3;break;}
			rowsel=2;IOSET0=0X000F0000;IOCLR0=1<<18;
			if(COL0==0){colsel=0;break;}
			if(COL1==0){colsel=1;break;}
			if(COL2==0){colsel=2;break;}
			if(COL3==0){colsel=3;break;}
			rowsel=3;IO0SET=0X000F0000;IO0CLR=1<<19;
			if(COL0==0){colsel=0;break;}
			if(COL1==0){colsel=1;break;}
			if(COL2==0){colsel=2;break;}
			if(COL3==0){colsel=3;break;}
		}
		delay_ms(50);// for key debouncing
		while(COL0==0||COL1==0||COL2==0||COL3==0);
		delay_ms(50);
		IOSET0=0X000F0000;
		U0THR=lookup_table[rowsel][colsel];
	}
}

void delay_ms(unsigned int j){
	for(unsigned char i=0;i<j;i++)
		for(int x=0;x<10000;x++);
}

void uart_init(void){
	PINSEL0|=0X00000005;
	U0LCR=0X83;
	U0DLM=0;
	U0DLL=8;
	U0LCR=0X03;
	U0FCR=0X07;
}
