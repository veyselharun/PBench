#include <rtems.h>
#include <stdio.h>
#include <pthread.h>

void *factorial(void *argument)
{
        int number;
        long result;        

        number = (int) argument;


        result = 1;

        for(int i = 1; i <= number; i++)
                result = result * i;
        
        return (void *) result;
}
double combination(int n, int k)
{
        pthread_t threads[4];
        void *return_value;
        double result = 0;
        double factorial_n;
        double factorial_n_k;
        double factorial_k;


        pthread_create(&threads[0], NULL, factorial, (void *) n);
        pthread_create(&threads[1], NULL, factorial, (void *) (n - k));
        pthread_create(&threads[2], NULL, factorial, (void *) k);

        pthread_join(threads[0], &return_value);
        factorial_n = (long) return_value;
        pthread_join(threads[1], &return_value);
        factorial_n_k = (long) return_value;
        pthread_join(threads[2], &return_value);
        factorial_k = (long) return_value;

        result = factorial_n / (factorial_n_k * factorial_k);

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




