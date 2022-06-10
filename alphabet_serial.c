#include<lpc214x.h>

int main()
{
	int c='A';
	PINSEL0=0x00000005;
	PINSEL1=0x00000000;
	
	U0LCR=0x83;
	U0DLL=97;
	U0LCR=0x03;
	
	IO0DIR=0x00000000;
	
	while(1)
	{
		if(IO0PIN &(1<<14))
		{
			while(!(U0LSR &0X20));
			U0THR=c;
			c++;
		}
	}
	
	
	
}