#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 * is_valid_substring - checks if valid substring
 *
 * @s: string to be scanned
 * @words: words
 * @nb_words: nomber words
 * @word_len: length word
 * @start: start
 * Return: 1 if substring, otherwise 0
 */

int is_valid_substring(char const *s, char const **words, int nb_words, int word_len, int start)
{
    int *word_count = (int *)calloc(nb_words, sizeof(int));
    int i, j, index, found;
    char *word;

    for (i = 0; i < nb_words; i++)
    {
        index = start + i * word_len;
        word = (char *)malloc((word_len + 1) * sizeof(char));
        strncpy(word, s + index, word_len);
        word[word_len] = '\0';

        found = 0;
        for (j = 0; j < nb_words; j++)
        {
            if (word_count[j] == 0 && strcmp(word, words[j]) == 0)
            {
                word_count[j] = 1;
                found = 1;
                break;
            }
        }

        free(word);

        if (!found)
        {
            free(word_count);
            return 0;
        }
    }

    free(word_count);
    return 1;
}

/**
 * find_substring - find substring
 *
 * @s: string to be scanned
 * @words: array of words
 * @nb_words: number of elements in the array
 * @n: address at which to store
 * Return: an allocated array, storing each index in otherwise NULL
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int word_len = strlen(words[0]);
    int str_len = strlen(s);
    int substr_len = word_len * nb_words;
    int *result = (int *)malloc(str_len * sizeof(int));
    int result_count = 0;
    int i;

    if (str_len < substr_len)
    {
        *n = 0;
        return NULL;
    }

    for (i = 0; i <= str_len - substr_len; i++)
    {
        if (is_valid_substring(s, words, nb_words, word_len, i))
        {
            result[result_count++] = i;
        }
    }

    if (result_count == 0)
    {
        free(result);
        *n = 0;
        return NULL;
    }

    *n = result_count;
    result = realloc(result, result_count * sizeof(int));
    return result;
}
