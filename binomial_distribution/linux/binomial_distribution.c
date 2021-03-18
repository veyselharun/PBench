/*
 *  PBench Benchmark Suite
 * 
 *  Binomial Distribution Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */


#include <stdio.h>
#include <math.h>


long factorial(int); //perform factorial calculation
double combination(int, int); //perform combination calculation


int main()
{
        int n;
        int i;
        double p;
        double result;


        n = 14; //number of bernoulli experiments
        p = 0.3; 
        i = 5;
        result = 0;


        for (int k = 0; k <= i; k++)
                result += combination(n, k) * pow(p, k) * pow((1 - p), (n - k));


        return 0;
}


double combination(int n, int k)
{
        double result = 0;


        result = factorial(n) / (factorial(n - k) * factorial(k));

        return result;
}


long factorial(int number)
{
        int i;
        long result;


        result = 1;

        for(int i = 1; i <= number; i++)
                result = result * i;
        
        return result; 
}
