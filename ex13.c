#include "REGX51.H"
#include <INTRINS.h>
void time50ms(unsigned char i)
{
	unsigned char k;
	for(k=0;k<i;k++)
	{
		TH1 = (65536-50000)/256;	
		TL1 = (65536-50000)%256;
		TR1 = 1;
		while(!TF1);
		TF1 = 0;
	}
}

void main()
{
	unsigned char i,k,w;
	TMOD = 0x10;
	P1 = 0xff;
	while(1)
	{
		w = 0xfe;
		for(i=0;i<8;i++)
		{
			for(k=0;k<10;k++)
			{
				P1&=w;
				time50ms(10);
				P1 = 0xff;
				time50ms(20);
			}
			w = _crol_(w,1);
		}
	}
}
