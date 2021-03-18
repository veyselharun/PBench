#include <rtems.h>
#include <stdio.h>

void prime_control(int num1, int num2) 
{
    int number1 = num1;
    int number2 = num2;
    int is_prime, i;
  
    while (number1 <= number2) 
    {
        is_prime = 1;
        for (i = 2; i < number1 && is_prime; i++)
        {
            if (number1 % i == 0) 
            {
                is_prime = 0;
            }
        }
        if (is_prime == 1) 
        {	
           /*
	   printf("%d", number1);
	   printf(" ");
	   */
        }
        number1++;
    }
}
rtems_task Init(rtems_task_argument arg)
{
prime_control(10, 30);
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




