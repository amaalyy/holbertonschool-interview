
#include "sort.h"

/**
 * find_max - find the maximum number in the array
 * @array:pointer to the array of integers
 * @size:size of the array
 * Return: the maximum number in the array
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * sort_by_digit_place - sort array by the digit at a specific place
 * @array:pointer to the array of integers
 * @size:size of the array
 * @place:place value like (1 for units, 10 for tens, 100 for hundreds ..)
 */
void sort_by_digit_place(int *array, size_t size, int place)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	int i;
	size_t j;

	for (j = 0; j < size; j++)
	{
		int digit = (array[j] / place) % 10;

		count[digit]++;
	}
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		int digit = (array[i] / place) % 10;

		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];
	print_array(array, size);
	free(output);
}
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array:pointer to the array of integers
 * @size:size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	int max = find_max(array, size);

	for (int place = 1; max / place > 0; place *= 10)
		sort_by_digit_place(array, size, place);
}
