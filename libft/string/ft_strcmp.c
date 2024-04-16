/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:32:15 by chrhu             #+#    #+#             */
/*   Updated: 2023/09/13 12:45:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main()
{
	char str1[] = "aBcDeF";
	char str2[] = "AbCdEf";
	char str3[] = "abCdEf";
	char str4[] = "aBcDeF";
	char str5[] = "aBcDeFg";

	printf("Compare s1 = %s and s2 = %s", str1, str2);
	printf("\n%d : ", ft_strcmp(str1, str2));
	printf("%d",strcmp(str1, str2));
	printf("\n\nCompare s1 = %s and s3 = %s", str1, str3);
	printf("\n%d : ", ft_strcmp(str1, str3));
	printf("%d",strcmp(str1, str3));
	printf("\n\nCompare s1 = %s and s4 = %s", str1, str4);
	printf("\n%d : ", ft_strcmp(str1, str4));
	printf("%d",strcmp(str1, str4));
	printf("\n\nCompare s1 = %s and s5 = %s", str1, str5);
	printf("\n%d : ", ft_strcmp(str1, str5));
	printf("%d",strcmp(str1, str5));
	return (0);
}*/
