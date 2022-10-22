/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:44:34 by satushi           #+#    #+#             */
/*   Updated: 2022/10/22 15:40:41 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <stdio.h>

static int counter_digit(const char *base_num)
{
	int digit;

	digit = 0;
	while(*base_num != '\0')
	{
		digit = digit + 1;
		base_num = base_num + 1;
	}
	return digit;
}

static int num_base(long subject_num, long base_num)
{
	int malloc_size;

	malloc_size = 1;
	while(subject_num != 0)
	{
		malloc_size = malloc_size + 1;
		subject_num = subject_num / base_num;
	}
	return malloc_size;
}

static char *inputnbr(long subject, long base, int size, const char *base_chr)
{
	char *char_malloc;

	char_malloc = (char *)malloc(sizeof(char) * size);
	if(char_malloc == NULL)
		return (NULL);
	*(char_malloc + size) = '\0';
    size = size - 1;
	while(size-- != 0)
	{
		*(char_malloc + size) = base_chr[subject % base];
		subject = subject / base;
	}
	return char_malloc;
}

void	ft_putlong_string(long subject_num, const char *base_char)
{
	int malloc_size;
	long subjectnum_copy;
	char *char_malloc;
	const char *base_char_const;
	int base_num;

	base_num = counter_digit(base_char);
	subjectnum_copy = subject_num;
	malloc_size = num_base(subject_num, base_num);
	char_malloc = inputnbr(subject_num, base_num, malloc_size, base_char);
	if(char_malloc == NULL)
		return ;
	ft_putchar_string(char_malloc);
	free(char_malloc);
}