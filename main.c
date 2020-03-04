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
		if (str[i] == '%')
			i++;
	return (i);
}

void	ft_printf(char *str, void *var, ...)
{
	int i;
	int count;

	i = 0;
	count = ft_percents(str);
	while (count--)
	{
		while (str[i] != '%' && str[i])
			i++;
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				str = ft_strjoin(ft_strncpy_mod(str, i), (char *)var);
				i = 0;
			}
		}
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