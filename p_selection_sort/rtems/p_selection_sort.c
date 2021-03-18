#include <rtems.h>
#include <pthread.h> 

struct thread_arguments {
        int current;
        int min_index;
        int start_index;
        int end_index;
} thread_args[2];

int array[] = {
        1, 5, 3, 7, 2, 6, 4, 8, 11, 10, 9, 12, 19, 14, 15, 16, 17, 18, 13, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 
        39, 43, 41, 42, 40, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 
        57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 86, 73, 74, 
        75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 72, 87, 88, 89, 90, 91, 92, 
        93, 94, 95, 96, 97, 98, 99, 100
        };

void *find_mininum_value(void *arguments) 
{
        int minimum_value;
        int minimum_index;
        struct thread_arguments *args;

        args = (struct thread_arguments *) arguments;
        int current = args->current;
        int min_index = args->min_index;
        int start_index = args->start_index;
        int end_index = args->end_index;


        minimum_value = current;
        minimum_index = min_index;
        for (int i = start_index; i <= end_index; i++) {
                if (array[i] < minimum_value) {
                        minimum_value = array[i];
                        minimum_index = i;
                }
        }

        return (void *) minimum_index;
}



void sort(int start_index, int end_index)
{
        pthread_t threads[4];
        void *return_value_1, *return_value_2;
        int minimum_index, minimum_index_1, minimum_index_2;
        int temp;
        int count;
        int median;

        for (int i = start_index; i < end_index; i++) {
                count = end_index - i + 1;
                median = count / 2;
                if (count > 2) {
                        thread_args[0].current = array[i];
                        thread_args[0].min_index = i;
                        thread_args[0].start_index = i + 1;
                        thread_args[0].end_index = i + 1 + median;

                        thread_args[1].current = array[i];
                        thread_args[1].min_index = i;
                        thread_args[1].start_index = i + 1 + median + 1;
                        thread_args[1].end_index = end_index;

                        pthread_create(&threads[0], NULL, find_mininum_value, (void *) &thread_args[0]);
                        pthread_create(&threads[1], NULL, find_mininum_value, (void *) &thread_args[1]);            
                        pthread_join(threads[0], &return_value_1);
                        pthread_join(threads[1], &return_value_2);
                        minimum_index_1 = (int) return_value_1;
                        minimum_index_2 = (int) return_value_2;

                        if (array[minimum_index_1] < array[minimum_index_2])
                                minimum_index = minimum_index_1;
                        else
                                minimum_index = minimum_index_2;

                        if (minimum_index != i) {
                                temp = array[i];
                                array[i] = array[minimum_index];
                                array[minimum_index] = temp;
                        }
                } else {
                        if (array[i] > array[i + 1]) {
                                temp = array[i];
                                array[i] = array[i + 1];
                                array[i + 1] = temp;
                        }                        
                }
        }
}

rtems_task Init(rtems_task_argument ignored)
{
  
        sort(0,99);
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
