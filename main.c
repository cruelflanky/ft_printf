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

void	ft_printf(char *str, void *var, ...)
{
	int i;

	i = 0;
	while (str[i] != '%')
		i++;
	if (str[i + 1] == 's')
		ft_putstr(ft_strjoin(ft_strncpy_mod(str, i), (char *)var));
}

int		main(void)
{
	char	*str = "string";
	ft_printf("ne_moy %s", str);
	ft_putstr("\n");
	printf("ne_moy %s", str);
	return (0);
}