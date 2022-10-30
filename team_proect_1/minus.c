/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:31:06 by junoh             #+#    #+#             */
/*   Updated: 2022/10/30 17:54:58 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beyond.h"
#include <string.h>

static char  *_compare_size_int(t_info *dest, t_info *src)
{
    char *bigger;
    int i;
    
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

static char  *_compare_size_float(t_info *dest, t_info *src)
{
    char *bigger;
    int i;
    
    i = dest->float_len - 1;
    while (i >= 0)
    {
        if (dest->float_num[i] != src->float_num[i])
        {
            bigger = (dest->float_num[i] > src->float_num[i]) ?  strdup("dest") : strdup("src"); 
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
        output->int_num[i] += big->int_num[i] - small->int_num[i];
        if (output->int_num[i] < 0)
        {
            output->int_num[i] += 10;
            round_minus = 1;
        }
        i++;
    }
    output->int_len = big->int_len;
    if (output->int_num[big->int_len - 1] == 0)
        output->int_len = big->int_len;
    return ;    
}

int minus_float(t_info *big, t_info *small, t_info *output)
{
    int i = 0;
    int round_minus = 0;
    
    while (i < big->float_len)
    {
        output->float_num[i] -= round_minus;
        round_minus = 0;
        output->float_num[i] += big->float_num[i] - small->float_num[i];
        if (output->float_num[i] < 0)
        {
            output->float_num[i] += 10;
            round_minus = 1;
        }
        i++;
    }
    output->float_len = big->float_len;
    if (output->float_num[big->float_len - 1] == 0)
        output->float_len = big->float_len;
    return (round_minus);
}

// static void _minus_float_first(t_info *dest, t_info *src, t_info *output, char *float_flag, char *int_flag)
// {
//     if (!strcmp(float_flag, "dest"))
//     {
//         minus_float(dest, src, output);
//         if (!strcmp(int_flag, "src"))
//             src->int_num[0] -= 1; 
//     }
//     else if (!strcmp(float_flag, "src"))
//     {
//         minus_float(src, dest, output);
//         if (!strcmp(int_flag, "dest"))
//             dest->int_num[0] -= 1;
//     }
//     else
//         output->float_sign = 0;
//     return ;
// }

int        minus_num(t_info *dest, t_info *src, t_info *output)
{
    char    *int_bigger;
    char    *float_bigger;
    int flag = 0;
    
    
    if (dest->float_sign || src->float_sign)
        output->float_sign = 1;
    int_bigger = _compare_size_int(dest, src); // 나중에 free
    if (strcmp(int_bigger, "same"))
    {                                           // bigger is not same
        _change_sign(dest, src, output, int_bigger);
        if (!strcmp(int_bigger, "dest"))
        {
            flag = minus_float(dest, src, output);
            // dest->int_num[0] -= minus_float(dest, src, output);
            dest->int_num[0] -= flag;
            minus_int(dest, src, output);
        }
        else
        {
            src->int_num[0] -= minus_float(src, dest, output);
            minus_int(src, dest, output);
        }
    }
    else
    {
        output->sign = 0;
        output->int_len = 1;
        float_bigger = _compare_size_float(dest, src);
        if (!strcmp(float_bigger, "dest"))
        {
            flag = minus_float(dest, src, output);
            if (flag == 1)
                output->sign = -1;
        }
        else if (!strcmp(float_bigger, "src"))
        {
            flag = minus_float(src, dest, output);
            output->sign = -1;
            if (dest->sign == -1 && src->sign == 1)
                output->sign = 1;
        }
        else
        {
            output->float_sign = 1;
            output->float_len = 1;
        }
        // output->float_sign = 0;
    }
    free(int_bigger);
    // free(float_bigger);
    return (TRUE);   
}