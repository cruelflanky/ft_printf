#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_percents(char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[x++])
		if (str[x] == '%')
			i++;
	return (i);
}

void	choose_flag(va_list *args, char *str, int i)
{
	if (str[i + 1] == 's')
		ft_putstr(va_arg(*args, char *));
	else if (str[i + 1] == 'c')
		ft_putchar((char)va_arg(*args, int));
	else if (str[i + 1] == 'd')
		ft_putnbr(va_arg(*args, int));
}

void	ft_printf(char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = ft_percents(str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			choose_flag(&args, str, i);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}

int		main(void)
{
	char	*str = "string";
	char	str2 = 'A';
	int		str3 = 322;
	ft_printf("string 1 = %s, symbol 2 = %c, integer 3 = %d, end!", str, str2, str3);
	ft_putstr("\n");
	printf("string 1 = %s, symbol 2 = %c, integer 3 = %d, end!", str, str2, str3);
	return (0);
}