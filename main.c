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

void	spec_i_d(va_list *args, t_printf *printf)
{
	if (printf->length.h)
		ft_putnbr_mod(va_arg(*args, short int));
	else if (printf->length.hh)
		ft_putnbr_mod(va_arg(*args, signed char));
	else if (printf->length.l)
		ft_putnbr_mod(va_arg(*args, long int));
	else if (printf->length.ll)
		ft_putnbr_mod(va_arg(*args, long long int));
	else if (printf->length.j)
		ft_putnbr_mod(va_arg(*args, intmax_t));
	else if (printf->length.z)
		ft_putnbr_mod(va_arg(*args, size_t));
	else
		ft_putnbr_mod(va_arg(*args, int));
}

void	spec_x_X_u_o(va_list *args, t_printf *printf)
{
	if (printf->length.h)
		ft_putnbr_mod(va_arg(*args, unsigned short int));
	else if (printf->length.hh)
		ft_putnbr_mod(va_arg(*args, unsigned int));
	else if (printf->length.l)
		ft_putnbr_mod(va_arg(*args, unsigned long int));
	else if (printf->length.ll)
		ft_putnbr_mod(va_arg(*args, unsigned long long int));
	else if (printf->length.j)
		ft_putnbr_mod(va_arg(*args, uintmax_t));
	else if (printf->length.z)
		ft_putnbr_mod(va_arg(*args, size_t));
	else
		ft_putnbr_mod(va_arg(*args, unsigned int));
}

void	choose_specifier(va_list *args, char *str, int i, t_printf *printf)
{
	if (str[i] == 's')
	{
		if (printf->length.l)
			ft_putstr(va_arg(*args, wchar_t *));
		else
			ft_putstr(va_arg(*args, char *));
	}
	else if (str[i] == 'c')
		ft_putchar(va_arg(*args, int *));
	else if (str[i] == 'p')
		ft_print_pointer(va_arg(*args, void *));
	else if (str[i] == 'd' || str[i + 1] == 'i')
		spec_i_d(args, printf);
	else if (str[i] == 'x' || str[i + 1] == 'X' ||
		str[i] == 'u' || str[i + 1] == 'o')
		spec_x_X_u_o(args, printf);
	else if (str[i] == 'f' || str[i + 1] == 'F' ||
		str[i] == 'e' || str[i + 1] == 'E' ||
		str[i] == 'g' || str[i + 1] == 'G' ||
		str[i] == 'a' || str[i + 1] == 'A')
		spec_fFeEgGaA(args, printf);
	else if (str[i] == '%')
		ft_putchar('%');
}

void	init_printf(t_printf *printf)
{
	init_length(printf->length);
	init_flags(printf->flags);
	printf->width = 0;
	printf->dot = 0;
	printf->precision = 0;
}

void	ft_printf(char *str, ...)
{
	int		i;
	va_list	args;
	t_printf *printf;

	init_printf(printf);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check_flags(str, i, printf);
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