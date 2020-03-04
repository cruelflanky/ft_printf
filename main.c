#include "ft_printf.h"
#include <stdio.h>
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
			if (str[i + 1] == 's')
				ft_putstr(va_arg(args, char *));
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
	char	*str2 = "objorka";
	char	*str3 = "kirill";
	ft_printf("argument 1 = %s, argument 2 = %s, argument 3 = %s, end!", str, str2, str3);
	ft_putstr("\n");
	printf("argument 1 = %s, argument 2 = %s, argument 3 = %s, end!", str, str2, str3);
	return (0);
}