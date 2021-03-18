/*
 *  PBench Benchmark Suite
 * 
 *  Matrix Multiplication Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */


#include <stdlib.h> 


void multiply();


int A[4][4];
int B[4][4];
int C[4][4];


int main()
{
        for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                        A[i][j] = rand() % 10; //random value assignment to matrices
                        B[i][j] = rand() % 10; //random value assignment to matrices
                        C[i][j] = 0;
                }
        }

        multiply();
    
        return 0;
}


void multiply()
{

        for (int i = 0; i < 4 ; i++)
                for (int j = 0; j < 4; j++)
                        for (int k = 0; k < 4; k++)
                                C[i][j] += A[i][k] * B[k][j];

}
