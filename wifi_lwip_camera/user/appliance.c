#include "wifi_base_config.h"
#include "appliance.h"

#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "debug.h"
#include "fsl_iomuxc.h"
/* FreeRTOS头文件 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


#include "./led/bsp_led.h"
#include "tcpecho.h"


/**************************** 任务句柄 ********************************/
/* 
 * 任务句柄是一个指针，用于指向一个任务，当任务创建好之后，它就具有了一个任务句柄
 * 以后我们要想操作这个任务都需要通过这个任务句柄，如果是自身的任务操作自己，那么
 * 这个句柄可以为NULL。
 */
static TaskHandle_t AppTaskCreate_Handle = NULL;/* 创建任务句柄 */



/********************************** 内核对象句柄 *********************************/
/*
 * 信号量，消息队列，事件标志组，软件定时器这些都属于内核的对象，要想使用这些内核
 * 对象，必须先创建，创建成功之后会返回一个相应的句柄。实际上就是一个指针，后续我
 * 们就可以通过这个句柄操作这些内核对象。
 *
 * 内核对象说白了就是一种全局的数据结构，通过这些数据结构我们可以实现任务间的通信，
 * 任务间的事件同步等各种功能。至于这些功能的实现我们是通过调用这些内核对象的函数
 * 来完成的
 * 
 */
 

/******************************* 全局变量声明 ************************************/
/*
 * 当我们在写应用程序的时候，可能需要用到一些全局变量。
 */


/*
*************************************************************************
*                             函数声明
*************************************************************************
*/
static void AppTaskCreate(void);/* 用于创建任务 */
static void Receive_Task(void* parameter);

extern void TCPIP_Init(void);


/**
 * @brief app_main
 *
 */
void app_main( void )
{
		/*配置wifi lwip信息*/
		Config_WIFI_LwIP_Info();
	  Camera_Init();
		while(1)
		{	
			img_sed_uart(); 
		}
		
	  BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
		
		/* 开发板硬件初始化 */
		LED_GPIO_Config();

//		/* 创建AppTaskCreate任务 */
//		xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,  /* 任务入口函数 */
//													(const char*    )"AppTaskCreate",/* 任务名字 */
//													(uint16_t       )512,  /* 任务栈大小 */
//													(void*          )NULL,/* 任务入口函数参数 */
//													(UBaseType_t    )1, /* 任务的优先级 */
//													(TaskHandle_t*  )&AppTaskCreate_Handle);/* 任务控制块指针 */ 
//		/* 启动任务调度 */           
//		if(pdPASS == xReturn)
//			vTaskStartScheduler();   /* 启动任务，开启调度 */
	
  /* 正常不会执行到这里 */    
    while (1)
    {
    }

}



/***********************************************************************
  * @ 函数名  ： AppTaskCreate
  * @ 功能说明： 为了方便管理，所有的任务创建函数都放在这个函数里面
  * @ 参数    ： 无  
  * @ 返回值  ： 无
  **********************************************************************/
//static void AppTaskCreate(void)
//{

//	/* 创建 BinarySem */
//	BinarySem_Handle = xSemaphoreCreateBinary();	 
//  
//  tcpecho_init();

//  taskENTER_CRITICAL();           //进入临界区
// 

//  /* 创建Receive_Task任务 */
//		xTaskCreate((TaskFunction_t )Receive_Task, /* 任务入口函数 */
//													(const char*    )"Receive_Task",/* 任务名字 */
//													(uint16_t       )512,   /* 任务栈大小 */
//													(void*          )NULL,	/* 任务入口函数参数 */
//													(UBaseType_t    )2,	    /* 任务的优先级 */
//													(TaskHandle_t*  )&Receive_Task_Handle);/* 任务控制块指针 */
//  
//													
//  vTaskDelete(AppTaskCreate_Handle); //删除AppTaskCreate任务
//  
//  taskEXIT_CRITICAL();            //退出临界区
//}




///**
// * @brief Receive_Task
// */

//static void Receive_Task(void* parameter)
//{	

//  BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
//	
//  while (1)
//  {
//    //获取二值信号量 xSemaphore,没获取到则一直等待
//		xReturn = xSemaphoreTake(BinarySem_Handle,/* 二值信号量句柄 */
//                              portMAX_DELAY); /* 等待时间 */

//    if(pdTRUE == xReturn)
//		{
//			PRINTF("收到数据:%s\r\n",recv_data);
//		}
//  }
//}

/********************************END OF FILE****************************/




