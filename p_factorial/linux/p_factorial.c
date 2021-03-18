/*
 *  PBench Benchmark Suite
 * 
 *  Parallel Factorial Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */

#include <pthread.h>
#include <stdlib.h>


void *factorial(void *);


struct thread_arguments {
        int start;
        int end;
} thread_args[2];


int main(int argc, char *argv[])
{
        pthread_t threads[2];
        char *pointer;
        void *return_value;
        int number;
        int result = 1;

        number = strtol(argv[1], &pointer, 10);

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

        return 0;
}


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
