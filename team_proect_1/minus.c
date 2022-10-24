/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:31:06 by junoh             #+#    #+#             */
/*   Updated: 2022/10/21 12:46:45 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beyond.h"
#include <string.h>

static char  *_compare_size(t_info *dest, t_info *src)
{
    char *bigger;
    int i;
    
    // if (dest->int_len > src->int_len)
    // {
    //     big_len = dest->int_len;
    //     (void)i; // 컴파일 플래그 오류 우회용
    //     return (big_len);
    // }       
    // else if (dest->int_len < src->int_len)
    // {
    //     big_len = src->int_len;
    //     (void)i;
    //     return (big_len);
    // }
    if (dest->int_len != src->int_len)
    {
        bigger = (dest->int_len > src->int_len) ?  strdup("dest") : strdup("src"); // dest > src 가 참이면 big_len = dest->int_len
        (void)i; // 컴파일 플래그 우회용
        return (bigger);
    }
    i = dest->int_len - 1;
    while (i >= 0)
    {
        if (dest->int_num[i] != src->int_num[i])
        {
            bigger = (dest->int_num[i] > src->int_num[i]) ?  strdup("dest") : strdup("src"); 
            return (bigger);
        }
        i--;
    }
    return (strdup("same"));
}

static void _change_sign(t_info *dest, t_info *src, t_info *output, char *str)
{
    char bigger;

    bigger = (!strcmp("dest", str)) ? 'd' : 's';
    if (bigger == 'd')
    {
        output->sign = 1;
        if (dest->sign == -1)
            output->sign = -1;
        return ; 
    }
    else
    {
        if (src->sign == 1 && dest->sign == 1 && arith_op == '-') // 14(dest) - 21(src)
            output->sign = -1;
        else if (src->sign == 1 && dest->sign == -1 && arith_op == '+') // -14 + 21
            output->sign = 1;
        else if (src->sign == -1 && dest->sign == 1 && arith_op == '+') // 14 + -21
            output->sign = -1;
        else                                                           // -14 - -21
            output->sign = 1;
    }
}

void minus_int(t_info *big, t_info *small, t_info *output)
{
    int i = 0;
    int round_minus = 0;
    
    while (i < big->int_len)
    {
        output->int_num[i] -= round_minus;
        round_minus = 0;
        output->int_num[i] = big->int_num[i] - small->int_num[i];
        if (output->int_num[i] < 0)
        {
            output->int_num[i] += 10;
            round_minus = 1;
        }
        i++;
    }
    output->int_len = big->int_len - 1;
    if (output->int_num[big->int_len - 1] == 0)
        output->int_len = big->int_len - 2;
    return ;    
}

// void minus_float(t_info *big, t_info *small, t_info *output)
// {
    
// }

int        minus_num(t_info *dest, t_info *src, t_info *output)
{
    char *bigger;
    
    bigger = _compare_size(dest, src); // 나중에 free
    if (strcmp(bigger, "same"))
    {
        _change_sign(dest, src, output, bigger);
         if (!strcmp(bigger, "dest"))
            minus_int(dest, src, output);
        else
            minus_int(src, dest, output);
    }
    else
    {
        output->sign = 0;
        output->int_len = 0;
    }
    return (TRUE);   
}