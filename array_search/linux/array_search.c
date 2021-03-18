/*
 *  PBench Benchmark Suite
 * 
 *  Array Search Program
 *
 *  Licensed under the MIT License. See LICENSE file in the PBench root 
 *  directory for license information.
 */


int search(int, int);


int array[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 
        57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 
        75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 
        93, 94, 95, 96, 97, 98, 99, 100
        };
int search_key = 70;
int array_length;


int main() 
{
        int result;

        array_length = sizeof(array) / sizeof(*array);
        result = search(0, array_length - 1); // Review the values from the initial value of the array to the last value with the while loop. 
                                              // When found value, the loop  finish.

        return 0;
}


int search(int start, int end) 
{
        int result = -1;

        while (start <= end) {
                if (array[start] == search_key) {
                        result = start;
                        break;
                }

                start = start + 1;
        }

        return result;
}
