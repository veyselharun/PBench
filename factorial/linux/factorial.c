/*
 *  PBench Benchmark Suite
 * 
 *  Factorial Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */


#include <stdlib.h>


int factorial(int);


int main(int argc, char *argv[])
{
        char *pointer;
        int number;
        int result;

        number = strtol(argv[1], &pointer, 10);
        result = factorial(number);
        
        return 0;
}


int factorial(int number)
{
        int result;

        if(number <= 1)
                return 1;

        result = number * factorial(number - 1);

        return result;
}
