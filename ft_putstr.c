/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:52 by satushi           #+#    #+#             */
/*   Updated: 2022/10/18 07:45:08 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void ft_putchar(char inputchar_num)
{
	write(1, &inputchar_num, 1);
}

void ft_putchar_string(char *sub_string)
{
	while(*sub_string != '\0')
	{
		ft_putchar(*sub_string);
		sub_string = sub_string + 1;
	}
}