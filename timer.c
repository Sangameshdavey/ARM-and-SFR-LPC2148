#include<lpc214x.h>
void delay(int count)
{
T0CTCR=0x0;
T0PR=59999;
T0TC=0;
T0TCR=0x01;
	
while(T0TC<count);
T0TCR=0x00;


}
void pll()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0XAA;
	PLL0FEED=0x55;
	while((PLL0STAT &(1<<10)) ==0);
	PLL0CON=0x11;
	PLL0FEED=0XAA;
	PLL0FEED=0x55;
	
	

}

int main()
{
	PINSEL0=0x00000000;
	IODIR0=0xffffffff;
	pll();
	
	while(1)
	{
	IO0SET=0xf0f0f0f0;
		delay(10);
		IO0CLR=0xf0f0f0f0;
		delay(10);
	}

}