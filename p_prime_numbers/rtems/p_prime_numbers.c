
#include <rtems.h>
#include <stdio.h>
#include <pthread.h>

#define start_of_array  10
#define end_of_array    30
#define number_of_threads   4


void *prime_calculation(void *thread_id) 
{
    long t_id;
    t_id = (long) thread_id;
    static int count=0; 
    int number1 = start_of_array+(end_of_array-start_of_array)*count/number_of_threads;
    int number2 = start_of_array+(end_of_array-start_of_array)*(count+1)/number_of_threads;
    count+=1;
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
            //printf("%d ", number1);
        }
        number1++;
    }
    //printf("\n");
}
void prime_control(int num1, int num2, int threads_count) 
{
    pthread_t threads[threads_count];
    long t;
    for (t = 0; t < threads_count; t++)
        pthread_create(&threads[t], NULL, prime_calculation, (void *)t);  
    for (t = 0; t < threads_count; t++)
        pthread_join(threads[t],NULL);
}
rtems_task Init(rtems_task_argument arg)
{
    prime_control(start_of_array, end_of_array, number_of_threads);
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

