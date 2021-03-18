#include <stdio.h>
#include <rtems.h>

long factorial(int number)
{
        int i;
        long result;


        result = 1;

        for(int i = 1; i <= number; i++)
                result = result * i;
        
        return result; 
}

double combination(int n, int k)
{
        double result = 0;


        result = factorial(n) / (factorial(n - k) * factorial(k));

        return result;
}

rtems_task Init(rtems_task_argument ignored)
{
        int n;
        int i;
        double p;
        double result;


        n = 14;
        p = 0.3;
        i = 5;
        result = 0;
	double a=1,b=1;

        for (int k = 0; k <= i; k++)
        {
            
            
                for(i=0;i<k;i++)
                    a=a*p;  //in place of pow function 
                    
                for(i=0;i<(n-k);i++)
                    b=b*(1-p);  //in place of pow function
                    
            result += combination(n, k) * a * b;
                
        }

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
