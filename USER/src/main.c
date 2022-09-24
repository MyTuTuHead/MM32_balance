/*
项目：
文件名：
创建时间：2021/11/25
创建人：MiaoA
参考：源官方Demo--->>MT9V03X_TFT1.8

功能：


修改日志：




现有BUG：




*/

#include "headfile.h"
//#include "SEEKFREE_ICM20602.h"
#include "SEEKFREE_IIC.h"
#include "SEEKFREE_MPU6050.h"
#include "zf_systick.h"


int main(void)
{
	board_init(true);//初始化 debug 输出串口->UART1->printf


	mt9v03x_init();//初始化摄像头
	lcd_init();//背景白色
	
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

		get_gyro();//mpu6050读取陀螺仪角度
		lcd_showint16(20,0,mpu_gyro_x);
		lcd_showint16(20,1,mpu_gyro_y);
		lcd_showint16(20,2,mpu_gyro_z);
		
		if(mt9v03x_finish_flag){//一帧图片采集完成
			//lcd_displayimage032(mt9v03x_image[0], MT9V03X_W, MT9V03X_H);
			systick_delay_ms(100);
			mt9v03x_finish_flag = 0;
		}

	}//while
}//main
// **************************** 代码区域 ****************************
