#include <rtems.h>

int A[4][4];
int B[4][4];
int C[4][4];
void multiply()
{

        for (int i = 0; i < 4 ; i++)
                for (int j = 0; j < 4; j++)
                        for (int k = 0; k < 4; k++)
                                C[i][j] += A[i][k] * B[k][j];

}
rtems_task Init(rtems_task_argument arg)
{
        for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                        A[i][j] = 3;
                        B[i][j] = 5;
                        C[i][j] = 0;
                }
        }

        multiply();
    
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

