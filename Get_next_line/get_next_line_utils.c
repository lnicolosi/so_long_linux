/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubachma <lubachma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:31:06 by lubachma          #+#    #+#             */
/*   Updated: 2024/02/05 10:09:24 by lubachma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tab)
		return (free_memory(&tab));
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	if (!s || !c)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (free_memory(&tab));
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	*ft_calloc(size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
