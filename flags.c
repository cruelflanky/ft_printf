/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:41:38 by gaudry            #+#    #+#             */
/*   Updated: 2020/03/11 18:03:09 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_flags(t_flags *flags)
{
    flags->plus = 0;
    flags->minus = 0;
    flags->spaces = 0;
    flags->hashtag = 0;
    flags->zero = 0;
}