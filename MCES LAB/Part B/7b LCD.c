#include <lpc214x.h>

#define PLOCK 0x00000400
#define LED_ON (IOCLR0=1U<<31)
#define LED_OFF (IOSET0=1U<<31)
#define RS_ON (IOSET0=1U<<20)
#define RS_OFF (IOCLR0=1U<<20)
#define EN_ON (IOSET1=1U<<25)
#define EN_OFF (IOCLR1=1U<<25)

void SystemInit(void);
static void delay_ms(unsigned int);
static void delay_us(unsigned int);
static void LCD_Reset(void);
static void LCD_Init(void);
static void LCD_cmdWrite(unsigned char);
static void LCD_DisplayString(const char *ptr_string);
static void LCD_sendHigherNibble(unsigned char);
static void LCD_sendcmdSignal(void);
static void LCD_SendDataSignal(void);
static void LCD_dataWrite(unsigned char);

int main(){
	SystemInit();
	IODIR0=1U<<31|0X001F0000;
	IODIR1=1U<<25;// ENABLE PIN
	LED_ON;delay_ms(500);LED_OFF;delay_ms(500);
	LCD_Reset();
	LCD_Init();
	delay_us(100);
	LCD_cmdWrite(0x80);LCD_DisplayString("RV College of Engrng");
	LCD_cmdWrite(0XC0);LCD_DisplayString("Computer Science");
	LCD_cmdWrite(0X94);LCD_DisplayString("4th semester");
	LCD_cmdWrite(0XD4);LCD_DisplayString("B Section");
	while(1);
}

static void delay_ms(unsigned int j){
	for(unsigned int i=0;i<j;i++)
		for(unsigned int x=0;x<10000;x++);
}

static void delay_us(unsigned int j){
	for(unsigned int i=0;i<j;i++)
		for(unsigned int x=0;x<10;x++);
}

static void LCD_cmdWrite(unsigned char cmdbyte){
	LCD_sendHigherNibble(cmdbyte);
	LCD_sendcmdSignal();
	cmdbyte=cmdbyte<<4;
	LCD_sendHigherNibble(cmdbyte);
	LCD_sendcmdSignal();
}

static void LCD_sendHigherNibble(unsigned char databyte){
	IOCLR0=0X000F0000;IOSET0=((databyte>>4)&0x0f)<<16;
}

static void LCD_sendcmdSignal(void){
	RS_OFF;
	EN_ON;delay_us(100);EN_OFF;
}

static void LCD_DisplayString(const char *ptr_string){
	while((*ptr_string)!=0)
		LCD_dataWrite(*ptr_string++);
}

static void LCD_dataWrite(unsigned char databyte){
	LCD_sendHigherNibble(databyte);
	LCD_SendDataSignal();
	databyte=databyte<<4;
	LCD_sendHigherNibble(databyte);
	LCD_SendDataSignal();
}

static void LCD_SendDataSignal(void){
	RS_ON;
	EN_ON;delay_us(100);EN_OFF;
}

static void LCD_Reset(void)
{
 /* LCD reset sequence for 4-bit mode*/
 LCD_sendHigherNibble(0x30);
 LCD_sendcmdSignal();
 delay_ms(100);
 LCD_sendHigherNibble(0x30);
 LCD_sendcmdSignal();
 delay_us(200);
 LCD_sendHigherNibble(0x30);
 LCD_sendcmdSignal();
 delay_us(200);
 LCD_sendHigherNibble(0x20);
 LCD_sendcmdSignal();
 delay_us(200);
}

static void LCD_Init(void)
{
delay_ms(100);
LCD_Reset();
LCD_cmdWrite(0x28u); //Initialize the LCD for 4-bit 5x7 matrix type
LCD_cmdWrite(0x0Eu); // Display ON cursor ON
LCD_cmdWrite(0x01u); //Clear the LCD
LCD_cmdWrite(0x80u); //go to First line First Position
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
