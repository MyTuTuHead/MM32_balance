/*
��Ŀ��
�ļ�����
����ʱ�䣺2021/11/25
�����ˣ�MiaoA
�ο���Դ�ٷ�Demo--->>MT9V03X_TFT1.8

���ܣ�


�޸���־��




����BUG��




*/

#include "headfile.h"
//#include "SEEKFREE_ICM20602.h"
#include "SEEKFREE_IIC.h"
#include "SEEKFREE_MPU6050.h"
#include "zf_systick.h"


int main(void)
{
	board_init(true);//��ʼ�� debug �������->UART1->printf


	mt9v03x_init();//��ʼ������ͷ
	lcd_init();//������ɫ
	
	//icm20602_init_spi();
	simiic_init();
	systick_delay_ms(80);
	mpu6050_init();
	
	while(1)
	{
		
//		get_icm20602_gyro_spi();
//		lcd_showint16(10,10,icm_gyro_x);
//		lcd_showint16(10,20,icm_gyro_y);
//		lcd_showint16(10,30,icm_gyro_z);

		get_gyro();//mpu6050��ȡ�����ǽǶ�
		lcd_showint16(20,0,mpu_gyro_x);
		lcd_showint16(20,1,mpu_gyro_y);
		lcd_showint16(20,2,mpu_gyro_z);
		
		if(mt9v03x_finish_flag){//һ֡ͼƬ�ɼ����
			//lcd_displayimage032(mt9v03x_image[0], MT9V03X_W, MT9V03X_H);
			systick_delay_ms(100);
			mt9v03x_finish_flag = 0;
		}

	}//while
}//main
// **************************** �������� ****************************
