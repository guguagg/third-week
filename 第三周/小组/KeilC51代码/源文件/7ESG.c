#include <REGX51.H>


void Delay(unsigned int xms)
{
	unsigned int i,j;
	for(i = 0;i < xms; i++)
	{
		for(j = 0; j < 110; j++);
	}
}



void main()
{
	while(1)
	{
		P2 = 0xFE;
		
		P0 = 0x3F;//ÊÏÔÊ¾0
		Delay(500);

		P0 = 0x06;//ÏÔÊ¾1
		Delay(500);
		
		P0 = 0x5B;//ÏÔÊ¾2
		Delay(500);
		
		P0 = 0X4f;//ÏÔÊ¾3
		Delay(500);
		
		P0 = 0x66;//ÏÔÊ¾4
		Delay(500);
		
		P0 = 0x6D;//ÏÔÊ¾5
		Delay(500);
		
		P0 = 0x7D;//ÏÔÊ¾6
		Delay(500);
	
		P0 = 0x07;//ÏÔÊ¾7
		Delay(500);

		P0 = 0x7F;//ÏÔÊ¾8
		Delay(500);

		P0 = 0x6F;//ÏÔÊ¾9
		Delay(500);

	}
}