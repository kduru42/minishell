/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:10:32 by kduru             #+#    #+#             */
/*   Updated: 2023/10/01 01:33:31 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *string)
{
	char	*arr;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (string[size])
		size++;
	arr = (char *)malloc(size + 1);
	if (!arr)
		return (NULL);
	while (string[i])
	{
		arr[i] = string[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	ft_lstadd_back(t_token **token, t_token *to_add, int plus)
{
	t_token	*tmp;

	tmp = *token;
	if (*token == NULL)
		*token = to_add;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
		tmp->next->prev = tmp;		
	}
	return (plus);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	subs = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!subs)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len)
		{
			subs[i] = s[start];
			i++;
			start++;
		}
	}
	subs[i] = 0;
	return (subs);
}


int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

int	ft_count_digit(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*value;
	size_t	count;
	long	number;

	number = n;
	count = ft_count_digit(n);
	value = (char *)malloc(sizeof(char) * (count + 1));
	if (!value)
		return (NULL);
	value[count--] = 0;
	if (number == 0)
		value[0] = '0';
	if (number < 0)
	{
		value[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		value[count--] = (number % 10) + 48;
		number /= 10;
	}
	return (value);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	char			*dest;
	unsigned int	i;

	if (!s1)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(s2)) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest += i;
	i = 0;
	while (s2[i])
	{
		dest[i] = s2[i];
		i++;
	}
	dest[i] = 0;
	return (dest - s1_len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (FALSE);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (FALSE);
		s1++;
		s2++;
	}
	return (TRUE);
}