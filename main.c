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

void	ft_printf(char *str, void *var, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, var);
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
}

int		main(void)
{
	char	*str = "string";
	char	*str2 = "objorka";
	ft_printf("ne_moy %s blabla %s", str, str2);
	ft_putstr("\n");
	printf("ne_moy %s blabla %s", str, str2);
	return (0);
}