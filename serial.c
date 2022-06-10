#include<lpc214x.h>
int c;
int main()
{
		PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=97;
	U0LCR=0x03;
	
	while(1)
	{
		while(!(U0LSR & 0x01));
		c=U0RBR;
		c++;
	while(!(U0LSR & 0X20));
		U0THR=c;
	}
	
}