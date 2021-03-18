#include <stdlib.h>
#include <time.h>
#include <rtems.h>

#define SIZE 100
int array[SIZE];

void fill_array(int size)
{
        srand(time(NULL));
        for (int i = 0; i < size; i++)
                array[i] = rand() % 1000; 
}


void sort(int start_index, int end_index)
{
        int minimum_index;
        int temp;

        for (int i = start_index; i < end_index; i++) {
                minimum_index = find_mininum_value(i, end_index);
                if (minimum_index != i) {
                        temp = array[i];
                        array[i] = array[minimum_index];
                        array[minimum_index] = temp;
                }
        }
}


int find_mininum_value(int start_index, int end_index) 
{
        int minimum_index;
        int minimum_value;
        
        minimum_index = start_index;
        minimum_value = array[start_index];
        for (int i = start_index + 1; i <= end_index; i++) {
                if (array[i] < minimum_value) {
                        minimum_value = array[i];
                        minimum_index = i;
                }
        }

        return minimum_index;
}
rtems_task Init(rtems_task_argument arg)
{
        fill_array(SIZE);
        sort(0, SIZE - 1);
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
