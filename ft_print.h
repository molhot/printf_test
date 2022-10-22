#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_print(const char *fmt_or_nch, ...);
void	ft_putnbr_string(int subject_num, const char *base_char);
void	ft_putchar(char inputchar_num);
void	ft_putchar_string(char *sub_string);
char	*ft_strdup(const char *s);

#endif
