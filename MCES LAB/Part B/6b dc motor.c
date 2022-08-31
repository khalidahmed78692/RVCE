#include <lpc214x.h>
#include <stdio.h>

#define LED_OFF (IO0SET = 1U << 31)
#define LED_ON (IO0CLR = 1U << 31)
#define PLOCK 0x00000400

void delay_ms(unsigned int j);
void SystemInit(void);
unsigned char getAlphaCode(unsigned char alphachar);
void alphadisp7SEG(char *buf);
unsigned int adc(int no,int ch);
void runDCMotor(int direction,int dutycycle);

int main(){	
  long int dig_val;
  char buf[5];
  IO0DIR |= 1U << 31 | 1U << 19 | 1U << 20 | 1U << 30 ; // to set as o/ps 
  LED_ON; // make D7 Led on .. just indicate the program is running
  SystemInit();
 
  do{
  dig_val = adc(1,2);
  sprintf(buf,"%05lu",dig_val);
  alphadisp7SEG(buf);
  runDCMotor(2,dig_val/10);
  delay_ms(200);
  }while(1);
//	do{
//	  dig_val = adc(1,2) / 10;
//		if(dig_val > 100) dig_val =100;
//		runDCMotor(2,dig_val);
//	//for(int j =0;j<99;j++){
//		i = adc(1,2);
//		sprintf(buf,"%05lu",i);
//		alphadisp7SEG(buf);
//	}while(1);
}

unsigned char getAlphaCode(unsigned char alphachar){
	switch (alphachar){
// dp g f e d c b a - common anode: 0 segment on, 1 segment off
		case 'f':return 0x8e; 
		case 'i':return 0xf9;
		case 'r':return 0xce;
		case 'e':return 0x86; // 1000 0110
		case 'h':return 0x89;
		case 'l':return 0xc7;
		case 'p':return 0x8c;
		case ' ': return 0xff;
		case '1':return 0xf9; 
		case '2':return 0xa4;
		case '3':return 0xb0;
		case '4':return 0x99; // 1000 0110
		case '5':return 0x92;
		case '0':return 0xc0; 
		case '6':return 0x82;
		case '7':return 0xf8;
		case '8':return 0x80; // 1000 0110
		case '9':return 0x98;
//simmilarly add for other digit/characters
		default : break;
	}
	return 0xff;
}

void alphadisp7SEG(char *buf){
	unsigned char i,j;
	unsigned char seg7_data,temp=0;
	for(i=0;i<5;i++){ // because only 5 seven segment digits are present
		seg7_data = getAlphaCode(*(buf+i)); //instead of this look up table can be used
 //to shift the segment data(8bits)to the hardware (shift registers) using 

		for (j=0 ; j<8; j++){
//get one bit of data for serial sending
			temp = seg7_data & 0x80; // shift data from Most significan bit (D7)
			if(temp == 0x80)
				IOSET0 |= 1 << 19; //IOSET0 | 0x00080000;
			else
				IOCLR0 |= 1 << 19; //IOCLR0 | 0x00080000;
//send one clock pulse
			IOSET0 |= 1 << 20; //IOSET0 | 0x00100000;
			delay_ms(1); 
			IOCLR0 |= 1 << 20; //IOCLR0 | 0x00100000;
			seg7_data = seg7_data << 1; // get next bit into D7 position
		}
	}

// send the strobe signal
	IOSET0 |= 1 << 30; //IOSET0 | 0x40000000;
	delay_ms(1); //nop();
	IOCLR0 |= 1 << 30; //IOCLR0 | 0x40000000;
	return;
}

void runDCMotor(int direction,int dutycycle){
	IO0DIR |= 1U << 28; //set P0.28 as output pin
	PINSEL0 |= 2 << 18; //select P0.9 as PWM6 (option 2)
	if (direction == 1)
		IO0SET = 1 << 28; //set to 1, to choose anti-clockwise direction
	else
		IO0CLR = 1 << 28; //set to 0, to choose clockwise direction
 
	PWMPCR = (1 << 14); // enable PWM6
	PWMMR0 = 1000; // set PULSE rate to value suitable for DC Motor operation
	PWMMR6 = (1000U*dutycycle)/100; // set PULSE period
	PWMTCR = 0x00000009; // bit D3 = 1 (enable PWM), bit D0=1 (start the timer)
	PWMLER = 0X70; // load the new values to PWMMR0 and PWMMR6 registers
}

unsigned int adc(int no,int ch){
 // adc(1,4) for temp sensor LM34, digital value will increase as temp increases
// adc(1,3) for LDR - digival value will reduce as the light increases
// adc(1,2) for trimpot - digital value changes as the pot rotation
	unsigned int val;
	PINSEL0 |= 0x0F300000; /* Select the P0_13 AD1.4 for ADC function */
 /* Select the P0_12 AD1.3 for ADC function */
 /* Select the P0_10 AD1.2 for ADC function */
	switch (no){ //select adc
	case 0: AD0CR=0x00200600|(1<<ch); //select channel
					AD0CR|=(1<<24); //start conversion
					while((AD0GDR& (1U<<31))==0);
					val=AD0GDR;
					break;
	case 1: AD1CR=0x00200600|(1<<ch); //select channel
					AD1CR|=(1<<24); //start conversion
					while((AD1GDR&(1U<<31))==0);
					val=AD1GDR;
					break;
	}
	val=(val >> 6) & 0x03FF; // bit 6:15 is 10 bit AD value
	return val;
}

void SystemInit(void){
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

void delay_ms(unsigned int j){
	unsigned int x,i;
	for(i=0;i<j;i++)
		for(x=0; x<10000; x++); 
}
