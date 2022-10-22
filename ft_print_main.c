/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:08 by satushi           #+#    #+#             */
/*   Updated: 2022/10/22 16:37:14 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void ft_switch_input(char fmt, va_list args)
{
	if(fmt == 'c')
		ft_putchar(va_arg(args, int));
	if( fmt == '%')
		ft_putchar('%');
	if(fmt == 's')
		ft_putchar_string(va_arg(args, char*));
	if(fmt == 'd' || fmt == 'i')
		ft_putnbr_string(va_arg(args, int), "0123456789");
	if (fmt == 'u')
		ft_putlong_string(va_arg(args, long), "0123456789");
	if(fmt == 'x')
		ft_putlong_string(va_arg(args, long), "0123456789abcdef");
	if(fmt == 'X')
		ft_putlong_string(va_arg(args, long), "0123456789ABCDEF");
	if(fmt == 'p')
		ft_put_adr(va_arg(args, long long), "0123456789abcdef");
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
			if(*(fmt_or_nch + 1) == '%')
				fmt_or_nch = fmt_or_nch + 1;
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
	char *nanka = "address";
	ft_print("this is %s %c %X %% %p ok end", "your like word", '>', 1234567, nanka);
}