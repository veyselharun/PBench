/*
 *  PBench Benchmark Suite
 * 
 *  Parallel Matrix Multiplication Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */


#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


void *multiply(void *);


int A[4][4]; 
int B[4][4]; 
int C[4][4];


int main()
{ 
        pthread_t threads[4];
        
        for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                        A[i][j] = rand() % 10; //random value assignment to matrices
                        B[i][j] = rand() % 10; //random value assignment to matrices
                        C[i][j] = 0;
                }
        }

        for (int i = 0; i < 4; i++)
                pthread_create(&threads[i], NULL, multiply, (void *)i); //4 threads are created. 
                                                                       //Each thread works for a particular row and column of the matrix.
        
        for (int i = 0; i < 4; i++) 
                pthread_join(threads[i], NULL);   //4 thread terminated
        
        return 0;
}


void *multiply(void *argument)
{
        int i;
        

        i = (int) argument;
        
        for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                        C[i][j] += A[i][k] * B[k][j];


        return NULL;
}
