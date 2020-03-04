#include "ft_printf.h"
#include <stdio.h>

char	*ft_strncpy_mod(char *src, int i)
{
	int x;
	char *dest;
	x = 0;

	dest = (char *)ft_memalloc(sizeof(char) * i);
	while (x < i)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

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
	int i;
	int count;
	char *old_str;

	old_str = str;
	i = 0;
	count = ft_percents(str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				ft_putstr((char *)var);
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
	ft_printf("ne_moy %s", str);
	ft_putstr("\n");
	printf("ne_moy %s", str);
	return (0);
}