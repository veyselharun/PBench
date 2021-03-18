/*
 *  PBench Benchmark Suite
 * 
 *  Parallel Binomial Distiribution Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root directory for license information.
 */


#include <stdio.h>
#include <math.h>
#include <pthread.h>


void *factorial(void *);
double combination(int, int);


int main()
{
        int n;
        int i;
        double p;
        double result;


        n = 14;
        p = 0.3;
        i = 5;
        result = 0;

        for (int k = 0; k <= i; k++)
                result += combination(n, k) * pow(p, k) * pow((1 - p), (n - k)); //mathematical calculation


        return 0;
}


double combination(int n, int k)
{
        pthread_t threads[4];
        void *return_value;
        double result = 0;
        double factorial_n;
        double factorial_n_k;
        double factorial_k;


        pthread_create(&threads[0], NULL, factorial, (void *) n); 
        pthread_create(&threads[1], NULL, factorial, (void *) (n - k)); //each thread performs a different mathematical operation of binomial distribution.
        pthread_create(&threads[2], NULL, factorial, (void *) k);

        pthread_join(threads[0], &return_value);
        factorial_n = (long) return_value;
        pthread_join(threads[1], &return_value);
        factorial_n_k = (long) return_value;
        pthread_join(threads[2], &return_value);
        factorial_k = (long) return_value;

        result = factorial_n / (factorial_n_k * factorial_k);

        return result;
}


void *factorial(void *argument)
{
        int number;
        long result;        

        number = (int) argument;


        result = 1;

        for(int i = 1; i <= number; i++)
                result = result * i;
        
        return (void *) result;
}
