#include "CORE.h"
#include "mcu.h"

void RT_Delay_ms(unsigned long ms)
{	
	unsigned int i;
	while(ms--)
	{
		for (i = 0; i < 200; i++)
			asm("nop");
	}
}

/***********************************************************
 *�������ƣ�RAM����
 *�������ܣ����RAM�ӳ���
 *��ڲ�������
 *���ڲ�������
 *�м��������
 *˵����
 *˵����
**********************************************************/
void RT_Clr_Ram()  
{
    unsigned long i;
    for(i=0;i<2048;i++)
    {
      (*(volatile unsigned char *)(0x01000000 + i)) = 0; 
    }
}
