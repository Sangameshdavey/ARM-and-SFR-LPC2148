#include<lpc214x.h>
int i,j;
void delay()
{
	for( i=0;i<100;i++)
	{
	for( j=0;j<100;j++)
		{}
	}
}

int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	
	IODIR1=0XFFFFFFFF;
	
	IODIR0=0X00000000;
	
	while(1)
	{
		if(IO0PIN & (1<<14))
		{
			IO1SET=0X00005555;
			delay();
			IO1CLR=0X00005555;
			delay();
		
		}
		else
		{
			IO1SET=0XAAAA0000;
			delay();
			IO1CLR=0XAAAA0000;
			delay();
			
		}
	}

}