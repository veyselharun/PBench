#include <rtems.h>
#include <stdio.h>

int factorial(int number)
{
        int result;

        if(number <= 1)
                return 1;

        result = number * factorial(number - 1);

        return result;
}

rtems_task Init(rtems_task_argument ignored)
{
      
        int result;
        result = factorial(10);    
        return 0;
}
#include <bsp.h>
/* NOTICE: the clock driver is explicitly disabled */
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_USE_DEVFS_AS_BASE_FILESYSTEM

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_MAXIMUM_TASKS 1

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
/* end of file */
