/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:36:08 by gaudry            #+#    #+#             */
/*   Updated: 2020/03/11 16:55:24 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void    init_length(t_length *length)
{
    length->hh = 0;
    length->h = 0;
    length->l = 0;
    length->ll = 0;
    length->j = 0;
    length->z = 0;
    length->t = 0;
    length->L = 0;
}

void    check_length(va_list *args, char *str, int i, t_length *length)
{
    if (str[i + 1] == 'h')
    {
        if (str[i + 2] != '\0' && str[i + 2] == 'h')
            length->hh = 1;
        else
            length->h = 1;
    }
    else if (str[i + 1] == 'l')
    {
        if (str[i + 2] != '\0' && str[i + 2] == 'l')
            length->ll = 1;
        else
            length->l = 1;
    }
    else if (str[i + 1] == 'j')
        length->j = 1;
    else if (str[i + 1] == 'z')
        length->z = 1;
    else if (str[i + 1] == 't')
        length->t = 1;
    else if (str[i + 1] == 'L')
        length->L = 1;
}

