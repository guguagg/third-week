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
		
		P0 = 0x3F;//���ʾ0
		Delay(500);

		P0 = 0x06;//��ʾ1
		Delay(500);
		
		P0 = 0x5B;//��ʾ2
		Delay(500);
		
		P0 = 0X4f;//��ʾ3
		Delay(500);
		
		P0 = 0x66;//��ʾ4
		Delay(500);
		
		P0 = 0x6D;//��ʾ5
		Delay(500);
		
		P0 = 0x7D;//��ʾ6
		Delay(500);
	
		P0 = 0x07;//��ʾ7
		Delay(500);

		P0 = 0x7F;//��ʾ8
		Delay(500);

		P0 = 0x6F;//��ʾ9
		Delay(500);

	}
}