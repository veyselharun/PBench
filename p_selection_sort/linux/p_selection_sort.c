/*
 *  PBench Benchmark Suite
 * 
 *  Selection Sort Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */


#include <stdlib.h>
#include <time.h>
#include <pthread.h> 


void fill_array(int);
void sort(int, int);
void *find_mininum_value(void *); 


#define SIZE 100


struct thread_arguments {
        int current;
        int min_index;
        int start_index;
        int end_index;
} thread_args[2];

int array[SIZE];


int main() 
{
        fill_array(SIZE);
        sort(0, SIZE - 1);

        return 0;
}


void fill_array(int size)
{
        srand(time(NULL));
        for (int i = 0; i < size; i++)
                array[i] = rand() % 1000; 
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

                        pthread_create(&threads[0], NULL, find_mininum_value, (void *) &thread_args[0]); //each thread finds the smallest value
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
