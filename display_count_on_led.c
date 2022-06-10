#include<lpc214x.h>
int i,j;
int count=0;
void delay()
{
	for( i=0;i<1000;i++)
	{
	for( j=0;j<1000;j++)
		{}
	}
}
int main()
{
	PINSEL0=0X00000000;
	PINSEL1=0X00000000;
	PINSEL2=0X00000000;
	
	IO0DIR=0X00000000;
	IO1DIR=0XFFFFFFFF;
	
	while(1)
	{
		if(IO0PIN &(1<<14))
		{
			count++;
			IO1CLR=0X00FF0000;
			delay();
			IO1SET=(count<<16);
			delay();
			
			if(count==2255)
				count=0;
			
		}
	}
	
}