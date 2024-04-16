/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:49:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/01/15 13:59:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//Count the number of words split
static int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	inside_word = 0;
	while (*s != '\0')
	{
		inside_word = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			if (inside_word == 0)
			{
				count++;
				inside_word = 1;
			}
		s++;
		}
	}
	return (count);
}

//Go to the next word
static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)(len + 1));
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split_ps(char *s, char c)
{
	int		i;
	int		words;
	char	**result;

	i = 0;
	words = count_words(s, c);
	if (!words)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(words + 1));
	if (!result)
		return (NULL);
	while (words > 0)
	{
		result[i] = get_next_word(s, c);
		i++;
		words--;
	}
	result[i] = 0;
	return (result);
}

/*
char	**ft_split_ps(char *s, char c)
{
	int		i;
	int		words;
	char	**result;

	i = 0;
	words = count_words(s, c);
	if (!words)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(words + 1));
	if (!result)
		return (NULL);
	while (words > 0)
	{
		result[i] = get_next_word(s, c);
		i++;
		words--;
	}
	result[i] = 0;
	free_split_result(result);
	return (result);
}*/
