#include<lpc214x.h>
void delay(int x)
{
	int i,j;
	for( i=0;i<100;i++)
	{
	for( j=0;j<x;j++)
		{}
	}
}

unsigned long i;
int main()
{
	int a=5;
	 
	IODIR1=0x00FF0000;
	
	i=0x00010000;
	
	
	while(a)
	{
		IO1SET=i;
		delay(100);
		IO1CLR=0x00ff0000;
	
		i=i<<1;
		
		if(i==0x00100000)
		{
			i=0x00010000;
			
		}
		a--;
		
	
	}
	
	
	
	
	
	
	

}