/*
 *  PBench Benchmark Suite
 * 
 *  Prime Numbers Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */



#include <stdio.h>

#define start  10
#define end    30

void prime_control(int num1, int num2);

int main()
{
    prime_control(start, end); //this function finds prime numbers between the start and end values.
    return 0;
}

void prime_control(int num1, int num2) 
{
    int number1 = num1;
    int number2 = num2;
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
           /*
	   printf("%d", number1);
	   printf(" ");
	   */
        }
        number1++;
    }
}




