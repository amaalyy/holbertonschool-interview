#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - get max in array
 * @array: The array to be printed
 * @size: size of the array
 * Return: the max number in the array
 */

int getMax(int *array, int size)
{
    int max = array[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
/**
 * countSort - counting sort
 * @array: The array to be printed
 * @size: size of the array
 * @exp: the  digit's place value
 */

void countSort(int *array, int size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    int i;

    for (i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
    print_array(array, size);
}

/**
 * radix_sort - radix sort
 * @array: The array to be printed
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
    }
}
