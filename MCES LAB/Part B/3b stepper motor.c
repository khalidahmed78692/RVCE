#include <lpc214x.h>

void delay_ms(unsigned int j);

int main(){
	unsigned int no_of_steps_clk = 100, no_of_steps_aclk = 100;
	IO0DIR |= 0x000F0000;
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
