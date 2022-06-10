#include<lpc214x.h>
void pll()
{
	PLL0CON = 0x1;
	PLL0CFG = 0x24;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	while(!(PLL0STAT & (1<<10)));
	PLL0CON = 0x3;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	VPBDIV = 0x1;
}
void delay(int y)
{
	T0CTCR = 0x0;
	T0TCR = 0x00;
	T0PR = 59999;
	T0TCR = 0x2;
	T0TCR = 0x1;
	while(T0TC < y);
	T0TCR = 0x00;
	T0TC = 0x0;
}
int main()
{
	int j=0x00800000;//23
	int i=0x00010000;//16
	
	int toggle=0;
	PINSEL0=0x00000000;
	PINSEL1=0x0;
	PINSEL2=0x0;
	
	IO1DIR=0xffffffff;
	pll();
	
	while(1)
	{
		if(i==0x00080000 && j==0x00100000)
		{
			toggle=1;
		}
		if(toggle==0)
		{
			IO1SET=i|j;
			
			delay(300);
			
			IO1CLR=i|j;
			delay(300);
			
			i=i<<1;
			j=j>>1;
			
			
		}
		else
		{
			IO1SET=i|j;
			
			delay(1000);
			
			IO1CLR=i|j;
			delay(1000);
			
			i=i>>1;
			j=j<<1;
		}
	}
	

}