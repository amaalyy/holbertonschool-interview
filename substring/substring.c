#include "substring.h"
/**
 * initialize_find_substring - initialization step
 * @str_len: length of string to be searched
 * @nb_words:the number of words to be matched in the string
 * @n:the address at which to store the number of
 * elements in the returned array.
 * Return: a pointer to storing indices of matched substrings otherwise NULL
 */
int *initialize_find_substring(int str_len, int nb_words, int *n)
{
	int *res_ind = malloc(str_len * sizeof(int));

	if (!res_ind)
	{
		*n = 0;
		return (NULL);
	}
	int *used_words = malloc(nb_words * sizeof(int));

	if (!used_words)
	{
		free(res_ind);
		*n = 0;
		return (NULL);
	}
	free(used_words);
	return (res_ind);
}


/**
 * find_substring - finds all the possible substrings
 * containing a list of words, within a given string.
 * @s:the string to scan
 * @words:the array of words
 * @nb_words:the number of elements in the array words
 * @n:the address at which to store the number of
 * elements in the returned array.
 * Return:allocated array,storing each index in s,
 * at which a substring was found,otherwise NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int str_len = strlen(s), word_len = strlen(words[0]);
	int total_len = word_len * nb_words, match_count = 0;
	int *res_ind = initialize_find_substring(str_len, nb_words, n), i, j, k;

	if (!res_ind)
		return (NULL);
	for (i = 0; i <= str_len - total_len; i++)
	{
		int *used_words = malloc(nb_words * sizeof(int));
		int is_valid = 1;

		if (!used_words)
			free(res_ind);
		memset(used_words, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			const char *current_word = s + i + j * word_len;
			int found_match = 0;

			for (k = 0; k < nb_words; k++)
			{
				if (!used_words[k] && strncmp(current_word, words[k], word_len) == 0)
				{
					used_words[k] = 1;
					found_match = 1;
					break;
				}
			}
			if (!found_match)
			{
				is_valid = 0;
				break;
			}
		}
		if (is_valid)
			res_ind[match_count++] = i;
		free(used_words);
	}
	*n = match_count;
	return (match_count == 0 ? (free(res_ind), NULL) : res_ind);
}
