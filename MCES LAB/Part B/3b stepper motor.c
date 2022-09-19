#include <lpc214x.h>

#define LED_ON (IOCLR0=1U<<31)
#define LED_OFF (IOSET0=1U<<31)
#define PLOCK 0X00000400

void SystemInit(void);
void delay_ms(unsigned int j);

int main(){
	unsigned int no_of_steps_clk = 100, no_of_steps_aclk = 100;
	IO0DIR |= 0x000F0000|1u<<31;
	LED_ON;delay_ms(250);LED_OFF;
	SystemInit();
	do{
		IO0CLR = 0X000F0000;IO0SET = 0X00010000;delay_ms(10);if(--no_of_steps_clk == 0) break;
		IO0CLR = 0X000F0000;IO0SET = 0X00020000;delay_ms(10);if(--no_of_steps_clk == 0) break;
		IO0CLR = 0X000F0000;IO0SET = 0X00040000;delay_ms(10);if(--no_of_steps_clk == 0) break;
		IO0CLR = 0X000F0000;IO0SET = 0X00080000;delay_ms(10);if(--no_of_steps_clk == 0) break;
	}while(1);
	do{
		IO0CLR = 0X000F0000;IO0SET = 0X00080000;delay_ms(10);if(--no_of_steps_aclk == 0) break;
		IO0CLR = 0X000F0000;IO0SET = 0X00040000;delay_ms(10);if(--no_of_steps_aclk == 0) break;
		IO0CLR = 0X000F0000;IO0SET = 0X00020000;delay_ms(10);if(--no_of_steps_aclk == 0) break;
		IO0CLR = 0X000F0000;IO0SET = 0X00010000;delay_ms(10);if(--no_of_steps_aclk == 0) break;
	}while(1);
	IO0CLR = 0X00FF0000;
	while(1);
}

void delay_ms(unsigned int j){
  unsigned int x,i;
  for(i=0;i<j;i++)
    for(x=0; x<10000; x++);
}

void SystemInit(void)
{
  PLL0CON = 0x01;
  PLL0CFG = 0x24;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  while( !( PLL0STAT & PLOCK ))
   { ; }
  PLL0CON = 0x03;
  PLL0FEED = 0xAA; // lock the PLL registers after setting the required PLL
  PLL0FEED = 0x55;
  VPBDIV = 0x01; // PCLK is same as CCLK i.e 60Mhz
}
