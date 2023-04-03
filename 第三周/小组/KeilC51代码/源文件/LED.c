#include <REGX52.H>

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
		Delay(500);
		P2 = 0xFD;
		Delay(500);
		P2 = 0xFB;
		Delay(500);
		P2 = 0xF7;
		Delay(500);
		P2 = 0xEF;
		Delay(500);
		P2 = 0xDF;
		Delay(500);
		P2 = 0xBF;
		Delay(500);
		P2 = 0x7F;
		Delay(500);

	}
}