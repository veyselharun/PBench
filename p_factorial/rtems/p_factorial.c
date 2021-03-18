#include <rtems.h>
#include <pthread.h>
#include <stdio.h>

struct thread_arguments {
        int start;
        int end;
} thread_args[2];

void *factorial(void *arguments)
{
        struct thread_arguments *args;
        int result = 1;

        args = (struct thread_arguments *) arguments;
        int start = args->start;
        int end = args->end;

        for (int i = start; i <= end; i++)
                result = result * i;

        return (void *) result;
}

rtems_task Init(rtems_task_argument ignored)
{
  pthread_t threads[2];
        void *return_value;
        int number;
        int result = 1;

        number = 10;

        if (number == 0 || number == 1) {
                result = 1;
                return 0;
        } 
        
        if (number == 2) {
                result = 2;
                return 0;
        }

        thread_args[0].start = 1; //Starting value for first thread
        thread_args[0].end = number / 2; // Ending value for first thread 
        thread_args[1].start = (number / 2) + 1; // Starting value for second thread 
        thread_args[1].end = number; // Ending value for second thread 

        for (int i = 0; i < 2; i++)
                pthread_create(&threads[i], NULL, factorial, (void *) &thread_args[i]);  //2 thread are created

        for(int i = 0; i < 2; i++) {
                pthread_join(threads[i], &return_value);
                result = result * (int) return_value;
               
        }
        //return 0;

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



