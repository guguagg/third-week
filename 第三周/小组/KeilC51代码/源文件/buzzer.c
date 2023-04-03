#include <REGX51.H>

void main()
{
	while(1)
	{
		if(P3_2 == 0)
		{
			P2_2 = 1;
		}
		else
		{
			P2_2 = 0;
		}
	}
}