#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H
# include "libft/libft.h"

typedef struct  s_flags
{
    _Bool         plus;
    _Bool         minus;
    _Bool         spaces;
    _Bool         hashtag;
    _Bool         zero;
}               t_flags;

typedef struct  s_length
{
    _Bool         hh;
    _Bool         h;
    _Bool         l;
    _Bool         ll;
    _Bool         j;
    _Bool         z;
    _Bool         t;
    _Bool         L;
}               t_length;

typedef struct  s_printf
{
    t_flags     flags;
    int         width;
    _Bool       dot;
    int         precision;
    t_length    length; 
}               t_printf;

#endif
