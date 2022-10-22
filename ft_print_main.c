/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:08 by satushi           #+#    #+#             */
/*   Updated: 2022/10/18 09:17:26 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static void ft_switch_input(char fmt, va_list args)
{
	if(fmt == 'c')
		ft_putchar(va_arg(args, int));
	if(fmt == 's')
		ft_putchar_string(va_arg(args, char*));
	if(fmt == 'd' || fmt == 'i')
		ft_putnbr_string(va_arg(args, int), "0123456789");
}

void ft_print(const char *fmt_or_nch, ...)
{
	va_list args;

	va_start(args, fmt_or_nch);
	while(*fmt_or_nch != '\0')
	{
		if(*fmt_or_nch == '%')
		{
			fmt_or_nch = fmt_or_nch + 1;
			ft_switch_input(*(fmt_or_nch), args);
			fmt_or_nch = fmt_or_nch + 1;
		}
		else
		{
			ft_putchar((char)(*fmt_or_nch));
			if(*fmt_or_nch == '\0')
				break ;
			fmt_or_nch = fmt_or_nch + 1;
		}
	}
	va_end(args);
}

int main()
{
	ft_print("this is %s %c %d\n", "your like word", 'd', 1234);
}