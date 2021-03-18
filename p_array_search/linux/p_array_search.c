/*
 *  PBench Benchmark Suite
 * 
 *  Parallel Array Search Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */

#include <pthread.h> 


void *search(void *);


struct thread_arguments {
        int start;
        int end;
} thread_args[4];


int array[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 
        57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 
        75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 
        93, 94, 95, 96, 97, 98, 99, 100
        };
int search_key = 70; //wanted value
int array_length; //length of array


int main()
{
        pthread_t threads[4]; //4 threads are created
        int piece_length; // length of each part of a splitted array
        void *return_value;
        int result = -1;
        
        array_length = sizeof(array) / sizeof(*array);
        piece_length = array_length / 4;

        thread_args[0].start = 0;
        thread_args[0].end = piece_length;
        thread_args[1].start = piece_length + 1;
        thread_args[1].end = piece_length * 2;
        thread_args[2].start = (piece_length * 2) + 1;
        thread_args[2].end = piece_length * 3;
        thread_args[3].start = (piece_length * 3)+ 1;
        thread_args[3].end = array_length - 1;

        for(int i = 0; i < 4; i++)
                pthread_create(&threads[i], NULL, search, (void *) &thread_args[i]);
     
        for(int i = 0; i < 4; i++) {
                pthread_join(threads[i], &return_value);
                if ((int) return_value != -1)
                        result = (int) return_value;
        }

        return 0;
}


void *search(void *arguments)
{
        struct thread_arguments *args;
        int result = -1;

        args = (struct thread_arguments *) arguments;
        int start = args->start;
        int end = args->end;

        while (start <= end) {
                if (array[start] == search_key) {
                        result = start;
                        break;
                }

                start = start + 1;
        }

        return (void *) result;
}
