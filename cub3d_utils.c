/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:24:19 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/16 00:34:39 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;
	int		i;

	if (!s1)
		s1 = ft_strdup("");
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s3[i + ft_strlen(s1)] = s2[i];
	s3[i + ft_strlen(s1)] = '\0';
	free (s2);
	free (s1);
	return (s3);
}

int	word_count(char *l, char c)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	if (!l)
		return (0);
	while (l[i])
	{
		while (l[i] && l[i] == c)
			i++;
		check = 0;
		while (l[i] && l[i] != c)
		{
			check = 1;
			i++;
		}
		if (check == 1)
			count++;
	}
	return (count);
}

int	word_length(char *k, int i, char c)
{
	int	j;

	j = 0;
	if (!k)
		return (0);
	while (k[i + j] != c && k[i + j])
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		size;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count((char *)s, c))
	{
		while (s[i] == c)
			i++;
		size = word_length((char *)s, i, c);
		str[j] = (char *)malloc(sizeof(char) * size + 1);
		strlcpy(str[j], s + i, size + 1);
		i += size;
		j++;
	}
	str[j] = NULL;
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2 == NULL)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (0);
	return (1);
}

// int main()
// {
// 	char s1[] = "salm";
// 	char s2[] = "salma";
// 	printf("%d", ft_strcmp(s1, s2));
// }