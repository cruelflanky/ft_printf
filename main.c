#include "ft_printf.h"
#include <stdio.h>

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
	char	*old_str;
	void	*pointer;

	old_str = str;
	i = 0;
	pointer = var;
	count = ft_percents(str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				ft_putstr((char *)pointer);
				pointer++;
			}
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
	printf("ne_moy %s", str);
	return (0);
}