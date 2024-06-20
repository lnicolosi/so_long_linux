/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubachma <lubachma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:44:43 by lubachma          #+#    #+#             */
/*   Updated: 2023/12/21 10:19:15 by lubachma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
	{
		j = write(1, "(null)", 6);
		return (j);
	}
	while (str[i])
	{
		j = write(1, &str[i], 1);
		i++;
	}
	return (i);
}
