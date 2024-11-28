#ifndef RADIX_SORT
#define RADIX_SORT

#include <stdlib.h>
#include <stddef.h>
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int find_max(int *array, size_t size);
void sort_by_digit_place(int *array, size_t size, int place);

#endif
