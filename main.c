#include "ft_printf.h"
#include <stdlib.h>

void	ft_printf(char *str, void *var, ...)
{

}

int		main(void)
{
	char	*str = "string";
	ft_printf("ne_moy %s", str);
	printf("ne_moy %s", str);
}