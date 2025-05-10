#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <errno.h>
#include <sys/select.h>

#include "FreeRTOS.h"
#include "task.h"

void vAssertCalled( const char * const pcFileName, unsigned long ulLine )
{
   taskENTER_CRITICAL();
   {
      while( 1 )
      {
         __asm volatile ( "NOP" );
         __asm volatile ( "NOP" );
      }
   }
   taskEXIT_CRITICAL();

}

void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer, StackType_t ** ppxIdleTaskStackBuffer, uint32_t * pulIdleTaskStackSize )
{
   static StaticTask_t xIdleTaskTCB;
   static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
   *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
   *ppxIdleTaskStackBuffer = uxIdleTaskStack;
   *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

void vApplicationMallocFailedHook(void) {
  vAssertCalled(__FILE__, __LINE__);
}
