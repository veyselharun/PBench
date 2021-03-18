/*
 *  PBench Benchmark Suite
 * 
 *  Parallel Prime Numbers Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */

#include <stdio.h>
#include <pthread.h>
#define start_of_array  10 //first value of array
#define end_of_array    30 //last value  of array
#define number_of_threads   4 //number of threads

void *prime_calculation(void *thread_id);
void prime_control(int num1, int num2, int threads_count);

int main()
{
    prime_control(start_of_array, end_of_array, number_of_threads);
    return 0;
}

void prime_control(int num1, int num2, int threads_count) 
{
    pthread_t threads[threads_count];
    long t;
    for (t = 0; t < threads_count; t++)
        pthread_create(&threads[t], NULL, prime_calculation, (void *)t); //threads are created 
    for (t = 0; t < threads_count; t++)
        pthread_join(threads[t],NULL); //threads are terminated
}
void *prime_calculation(void *thread_id) 
{
    long t_id;
    t_id = (long) thread_id;
    static int count=0; 
    int number1 = start_of_array+(end_of_array-start_of_array)*count/number_of_threads; //divides the parts of the array by the number of threads.
    int number2 = start_of_array+(end_of_array-start_of_array)*(count+1)/number_of_threads; // divides the parts of the array by the number of threads.
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

