/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/10/22 13:18:58 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void ft_putchar_string(char *sub_string)
{
	while(*sub_string != '\0')
	{
		ft_putchar(*sub_string);
		sub_string = sub_string + 1;
	}
}