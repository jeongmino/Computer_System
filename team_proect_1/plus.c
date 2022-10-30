/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:26:42 by junoh             #+#    #+#             */
/*   Updated: 2022/10/30 14:49:33 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beyond.h"

static int  _pre_plus(t_info *dest, t_info *src, t_info *output)
{
    int i;
    
    if (dest->float_len && src->float_len)
        return (FALSE);
    else if (dest->float_len && !src->float_len) // dest만 소숫점이 있음
    {
        i = -1;
        while (++i < dest->float_len)
            output->float_num[i] = dest->float_num[i];
        output->float_len = dest->float_len;
        return (TRUE);    
    }
    else if (src->float_len && !dest->float_len) // src만 소숫점이 있음
    {
        i = -1;
        while (++i < src->float_len)
            output->float_num[i] = src->float_num[i]; 
        return (TRUE);
        output->float_len = src->float_len; 
    }
    return (FALSE);
}

static  void _plus_int(t_info *dest, t_info *src, t_info *output)
{
    int i;    
    int ten_plus;
    
    if (dest->int_len > src->int_len)
        output->int_len = dest->int_len;
    else
        output->int_len = src->int_len;
    i = 0;
    ten_plus = 0;
    while (i < output->int_len)
    {
        output->int_num[i] += ten_plus;
        ten_plus = 0;
        output->int_num[i] += src->int_num[i] + dest->int_num[i];
        if (output->int_num[i] >= 10)
        {
            output->int_num[i] -= 10;
            ten_plus = 1;    
        }
        i++;
    }
    output->int_num[i] += ten_plus;
    if (output->int_num[i] != 0)
        output->int_len++;
    return ;
}

static int _plus_float(t_info *dest, t_info *src, t_info *output)
{
    int i = 0;    
    int ten_plus = 0;
    
    if (_pre_plus(dest, src, output) == TRUE)
        return (ten_plus);
    if (dest->float_len > src->float_len)
        output->float_len = dest->float_len;
    else
        output->float_len = src->float_len;
    while (i < output->float_len)
    {
        output->float_num[i] += ten_plus;
        ten_plus = 0;
        output->float_num[i] += src->float_num[i] + dest->float_num[i];
        if (output->float_num[i] >= 10)
        {
            output->float_num[i] -= 10;
            ten_plus = 1;
        }
        i++;
    }
    return (ten_plus);   
}   

static void _sign_check(t_info *dest, t_info *src, t_info *output)
{
    output->sign = -1;
    if ((dest->sign == 1 && src->sign == 1) || \
        (dest->sign == 1 && src->sign == -1))
        output->sign = 1;
    return ;       
}

static void _plus_one(t_info *output, int plus)
{
    int ten_plus = plus;
    int i = 0;

    while (i < output->int_len)
    {
        if (ten_plus == 0)
            return ;
        output->int_num[i] += ten_plus;
        if (output->int_num[i] >= 10)
        {
            output->int_num[i] -= 10;
            ten_plus = 1;
        }
        else
            ten_plus = 0;
        i++;
    }
    return ;
}

int plus_num(t_info *dest, t_info *src, t_info *output)
{
    int float_sign = 0;
    _sign_check(dest, src, output);
    _plus_int(dest, src, output);
    if (dest->float_len || src->float_len)
    {
        output->float_sign = 1;
       float_sign = _plus_float(dest, src, output);
    }
    if (float_sign)
        _plus_one(output, 1);
    return (TRUE);    
}