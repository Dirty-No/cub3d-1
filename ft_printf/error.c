/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:15:47 by gbabeau           #+#    #+#             */
/*   Updated: 2020/01/21 13:26:30 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	error(char **variable)
{
	int	i;

	i = 0;
	while ((variable[i]))
		free(variable[i++]);
	free(variable);
	return (-1);
}
