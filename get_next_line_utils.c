/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:14:57 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/17 02:14:57 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (s[i++] == 0)
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while(i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (ft_strdup (s2));
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i]!= '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (s[start] && (i < len))
	{
		str[i] = s[start];
		i++;
		start ++;
	}
	str[i] = '\0';
	return (str);
}