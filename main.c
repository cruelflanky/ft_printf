#include "ft_printf.h"


// void	ft_putnbr_double(double n)
// {
// 	if (n == -2147483648)
// 		ft_putstr("-2147483648");
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			ft_putchar('-');
// 			n *= -1;
// 		}
// 		if (n >= 10)
// 			ft_putnbr(n / 10);
// 		ft_putchar((n % 10) + 48);
// 	}
// }

int		check_width(t_printf *printf, char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		printf->width = ft_atoi(&str[i]);
	else
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		printf->dot = 0;
		i++;
	}
	return (i);
}

int		check_precisions(t_printf *printf, char *str, int i)
{
    if (printf->dot)
        printf->precision = ft_atoi(&str[i]);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    return (i);
}

void	choose_flag(va_list *args, char *str, int i)
{
	if (str[i] == 's')
		ft_putstr(va_arg(*args, char *));
	else if (str[i] == 'c')
		ft_putchar((char)va_arg(*args, int));
	else if (str[i] == 'd' || str[i + 1] == 'i')
		ft_putnbr(va_arg(*args, int));
	else if (str[i] == '%')
		ft_putchar('%');
}

void	ft_printf(char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			choose_flag(&args, str, i);
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
	short	str3 = 12345;
	//ft_printf("string 1 = %s, symbol 2 = %c, integer 3 = %d, symbol'%%' = %% end!", str, str2, str3);
	//ft_putstr("\n");
	printf("string 1 = %s, symbol 2 = %c, integer 3 = %hhi, symbol'%%' = %% end!", str, str2, str3);
	return (0);
}