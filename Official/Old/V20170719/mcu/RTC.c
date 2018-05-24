/***********************************************************
 * �ļ���:rtc.c
 * ����: ������ 
 * ����ʱ��:  2014.12.11
 * ������Ŀ: m2
 * ��˾: �������ѵ���
 * ���䣺guoyj_sejoy@163.com
 * �����д���ߣ�UltraEdit
 * ģ�鹦�ܣ�M2 RTC���Ӳ�����ú��ϵ��ʼ��
 * �޸ļ�¼: ��ʽ���޸����ڡ��޸��ˡ��޸����ݣ�
 *
 *
 *
 *
 *
 ***********************************************************/

/*Follow Is Include Files*/
#include "RTC.h"
#include "mcu.h"

/***********************************************************
 *�������ƣ�RT_RTC_Init12 RT_RTC_Init24
 *�������ܣ�RTCʱ�ӳ�ʼ��
 *��ڲ�������
 *���ڲ�������
 *�м��������
 *˵����RTCʹ�ܵ�ͬʱ����Ҳ�򿪣������ȷ����ʱ��Ҫ��һ��
 *˵����
**********************************************************/


void RT_RTC_Read(unsigned char *d_year,unsigned char *d_mon,unsigned char *d_day,unsigned char *d_hour,unsigned char *d_min,unsigned char *d_sec)
{
	unsigned long time;
	time = MemoryRead32(RTC_TIME_REG);
	if (d_year != 0)
		*d_year =(unsigned char)((time>>26)&0x3f);     //��ȡ�� 
	if (d_mon != 0)
      	*d_mon = (unsigned char)((time>>22)&0x0f);   //��ȡ�� 
	if (d_day != 0)                   
      	*d_day = (unsigned char)((time>>17)&0x1f);     //��ȡ��
	if (d_hour != 0)                                 
      	*d_hour = (unsigned char)((time>>12)&0x1f);    //��ȡʱ 
	if (d_min != 0)                                
      	*d_min = (unsigned char)((time>>6)&0x3f);   //��ȡ��   
	if (d_sec != 0)                              	
		*d_sec = (unsigned char)(time&0x3f);
}

