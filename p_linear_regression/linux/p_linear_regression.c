/*
 *  PBench Benchmark Suite
 * 
 * Parallel Linear Regression Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */

#include <stdio.h>
#include <pthread.h>

float xx[100];
float yy[100];
    
 float x[100]= {
        
        1.2, 5.9, 3.7, 7.1, 2.5, 6.4, 4.7, 8.9, 11.9, 10.2, 9.4, 12.4, 19.3, 14.3, 15.4, 16.5, 17.7, 18.9, 13.4, 20.1,
        21.4, 22.4, 23.9, 24.7, 25.1, 26.4, 27.3, 28.4, 29.9, 30.9, 31.4, 32.1, 33.2, 34.3, 35.7, 36.7, 37.8, 38.9, 
        39.9, 43.3, 41.1, 42.2, 40.7, 44.8, 45.3, 46.1, 47.2, 48.5, 49.6, 50.9, 51.7, 52.1, 53.9, 54.2, 55.7, 56.9, 
        57.4, 58.6, 59.3, 60.1, 61.7, 62.3, 63.7, 64.6, 65.4, 66.4, 67.2, 68.3, 69.7, 70.9, 71.9, 86.4, 73.1, 74.9, 
        75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 72, 87, 88, 89, 90, 91, 92, 
        93.4, 94.8, 95.9, 96.7, 97.6, 98.1, 99.5, 100.7
    };
    
    float y[100]= { 
        
        1.7, 5.9, 3.6, 7.7, 2.4, 6.9, 4.9, 8.1, 11.7, 10.4, 9.6, 12.9, 19.4, 14.2, 15.8, 16.1, 17.2, 18.3, 13.4, 20.7,
        75.7, 76.9, 77.4, 78.4, 79.1, 80.2, 81.3, 82.4, 83.4, 84.9, 85.4, 72.9, 87.7, 88.9, 89.4, 90.1, 91.6, 92.4,
        57.4, 58.4, 59.1, 60.1, 61.1, 62.7, 63.8, 64.8, 65.6, 66.9, 67.9, 68.4, 69.4, 70.4, 71.6, 86.6, 73.6, 74.3, 
        39.3, 43.3, 41.3, 42.3, 40.3, 44.3, 45.3, 46.3, 47.5, 48.2, 49.2, 50.2, 51.2, 52.1, 53.1, 54.4, 55.7, 56.9,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        93.1, 94.2, 95.4, 96.7, 97.8, 98.8, 99.9, 100.1
    };
    
    double sum_x=0; // sum of x values
    double sum_y=0; // sum of y values
    double sum_xx=0; // sum of square of x values
    double sum_xy=0; // sum of x*y values
    double m=0; // m value of y = mx + n
    double n=0; // n value of y = mx + n 
    
int i,k=100;

void calc_sum_x();
void calc_sum_y();
void calc_sum_xx();
void calc_sum_xy();
void calc_m();
void calc_n();

int main()
{
    for(i=0;i<k;i++)
    {
        xx[i]=x[i]*x[i];
    }
    
    pthread_t threads[6];
    
    //first 4 threads are created. 
    pthread_create(&threads[0], NULL, calc_sum_x, (void *)0); 
    pthread_create(&threads[1], NULL, calc_sum_y, (void *)1);
    pthread_create(&threads[2], NULL, calc_sum_xx, (void *)2);
    pthread_create(&threads[3], NULL, calc_sum_xy, (void *)3);
    
    for (int i = 0; i < 4; i++) 
        pthread_join(threads[i], NULL);   //first 4 threads terminated
    

    //last 2 threads are created. 
    pthread_create(&threads[4], NULL, calc_m, (void *)4); 
    pthread_create(&threads[5], NULL, calc_n, (void *)5);
    
    for (int i = 4; i < 6; i++) 
        pthread_join(threads[i], NULL);   //last 2 threads terminated
    
 
    //printf("Linear Regressiopn Equation y= %.2f x + %.2f ",m,n);
    return 0;
}

void calc_sum_x()
{
    for(i=0;i<k;i++)
        sum_x+=x[i];
}

void calc_sum_y()
{
    for(i=0;i<k;i++)
        sum_y+=y[i];
}

void calc_sum_xx()
{
    for(i=0;i<k;i++)
        sum_xx+= xx[i];
}

void calc_sum_xy()
{
    for(i=0;i<k;i++)
        sum_xy+= x[i]*y[i];
}

void calc_m()
{
    m=((k*sum_xy)-(sum_x*sum_y))/((k*sum_xx)-sum_x*sum_x);
}

void calc_n()
{
    n=(sum_xx*sum_y-sum_xy*sum_x)/((k*sum_xx)-sum_x*sum_x);
}
