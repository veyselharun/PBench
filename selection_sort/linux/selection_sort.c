/*
 *  PBench Benchmark Suite
 * 
 *  Selection Sort Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root directory for license information.
 */


#include <stdlib.h>
#include <time.h>


void fill_array(int);
void sort(int, int);
int find_mininum_value(int, int); 


#define SIZE 100


int array[SIZE];


int main() 
{
        fill_array(SIZE);
        sort(0, SIZE - 1);
}


void fill_array(int size)
{
        srand(time(NULL));
        for (int i = 0; i < size; i++)
                array[i] = rand() % 1000; fills the array with random values
}


void sort(int start_index, int end_index)
{
        int minimum_index;
        int temp;

        for (int i = start_index; i < end_index; i++) { //scans the beginning of the array to the end value and sorts the array from small to large
                minimum_index = find_mininum_value(i, end_index);
                if (minimum_index != i) {
                        temp = array[i];
                        array[i] = array[minimum_index];
                        array[minimum_index] = temp;
                }
        }
}


int find_mininum_value(int start_index, int end_index) 
{
        int minimum_index;
        int minimum_value;
        
        minimum_index = start_index;
        minimum_value = array[start_index];
        for (int i = start_index + 1; i <= end_index; i++) {
                if (array[i] < minimum_value) {
                        minimum_value = array[i];
                        minimum_index = i;
                }
        }

        return minimum_index;
}
