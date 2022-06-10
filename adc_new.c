#include<lpc214x.h>
int main()
{
	int val;
	PINSEL1=0x01000000;
	SCS=0x02;
	FIO1MASK=0xff00ffff;
	FIO1DIR=0x00ff0000;
	
	AD0CR=0x00200E02;
	
	while(1)
	{
			AD0CR |= 0x01000000;
			do
			{
				val=AD0DR1;
				
				
			}
			while((val &0x80000000)==0);
			
			FIO1PIN=(val<<8);
			
	}
}
