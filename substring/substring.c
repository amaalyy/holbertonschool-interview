#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 * is_valid_substring - checks if valid substring
 *
 * @s: string to be scanned
 * @words: words array
 * @nb_words: number of words
 * @word_len: length of each word
 * @start: starting index in the string
 * Return: 1 if substring, otherwise 0
 */
int is_valid_substring(char const *s, char const **words, int nb_words, int word_len, int start)
{
    int *word_count = (int *)calloc(nb_words, sizeof(int));
    int i, j, found;
    char word[word_len + 1];

    if (!word_count)
        return 0;

    for (i = 0; i < nb_words; i++)
    {
        int index = start + i * word_len;

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
 * @n: address at which to store the result count
 * Return: an allocated array storing indices, otherwise NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    if (!s || !words || nb_words == 0 || !n)
    {
        *n = 0;
        return NULL;
    }

    int word_len = strlen(words[0]);
    int str_len = strlen(s);
    int substr_len = word_len * nb_words;
    int *result = NULL;
    int result_count = 0;
    int i;

    if (str_len < substr_len)
    {
        *n = 0;
        return NULL;
    }

    result = (int *)malloc((str_len - substr_len + 1) * sizeof(int));
    if (!result)
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
    return realloc(result, result_count * sizeof(int));
}
