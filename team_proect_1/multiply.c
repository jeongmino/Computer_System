/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:30:17 by junoh             #+#    #+#             */
/*   Updated: 2022/10/30 17:50:46 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "beyond.h"

static int _check_sign(int dest_sign, int src_sign)
{
    if (dest_sign + src_sign == 0)
        return (-1);
    else
        return 1;
}

static void _round_up(int *arr, int output_len)
{
    int i = 0;

    while (i < output_len + 1)
    {
        if (arr[i] >= 10)
        {
            arr[i] -= 10;
            arr[i + 1] += 1;
        }
        i++;
    }
    return ;
}

static int _float_round_up(int *arr, int output_len)
{
    int i = 0;

    while (i < output_len + 1)
    {
        if (arr[i] >= 10)
        {
            arr[i] -= 10;
            arr[i + 1] += 1;
        }
        i++;
    }
    if (arr[i + 1] != 0)
        return (1);
    return (0);
}

static int _int_mul_float(t_info *int_n, t_info *float_n, t_info *output)
{
    int tmp = 0;
    int int_i;
    int float_i = 0;
    int float_exp = 0;
    int exp = 0;
    
    while (float_i < float_n->int_len)
    {
        int_i = 0;
        while (int_i < int_n->int_len)
        {
            float_exp = -(float_n->float_len);
            exp = float_exp + int_i;
            tmp = int_n->int_num[int_i] * float_n->int_num[float_i];
            if ((exp < 0 && exp != -1) || (exp == -1 && tmp < 10))
            {
                output->float_num[float_i] += tmp % 10;
                output->int_num[0] += _float_round_up(output->float_num, float_n->float_len);
                output->float_num[float_i + 1] += tmp / 10;
                output->int_num[0] += _float_round_up(output->float_num, float_n->float_len);
            }
            else if (exp == -1 && tmp >= 10)
            {
                output->float_num[0] += tmp % 10;
                output->int_num[0] += _float_round_up(output->float_num, float_n->float_len);
                output->int_num[0] += tmp / 10;
                _round_up(output->int_num, int_n->int_len + 1); 
            }
            else if (exp >= 0)
            {
                output->int_num[exp] += tmp % 10;
                _round_up(output->int_num, int_n->int_len + 1); 
                output->int_num[exp + 1] += tmp / 10;
                _round_up(output->int_num, int_n->int_len + 1); 
            }
            int_i++;   
        }
        float_i++; 
    }
    return (float_n->float_len);
}

static void _int_mul_int(t_info *dest, t_info *src, t_info *output)
{
    int tmp = 0;
    int d_i;
    int s_i = 0;
        
    while (s_i < src->int_len)
    {
        d_i = 0;
        while (d_i < dest->int_len)
        {
            tmp = dest->int_num[d_i] * src->int_num[s_i];
            output->int_num[s_i + d_i] += tmp % 10;
            _round_up(output->int_num, dest->int_len + src->int_len); 
            output->int_num[s_i + d_i + 1] += tmp / 10;
            _round_up(output->int_num, dest->int_len + src->int_len); 
            d_i++;   
        }
        s_i++; 
    }
    output->int_len = s_i + d_i - 1;
    if (output->int_num[s_i + d_i - 1] != 0)
        output->int_len++;
    return ;
}

static int _float_mul_float(t_info *dest, t_info *src, t_info *output)
{
    int tmp = 0;
    int d_i;
    int s_i = 0;
        
    while (s_i < src->float_len)
    {
        d_i = 0;
        while (d_i < float->int_len)
        {
            tmp = dest->int_num[d_i] * src->int_num[s_i];
            output->int_num[s_i + d_i] += tmp % 10;
            _round_up(output->int_num, dest->int_len + src->int_len); 
            output->int_num[s_i + d_i + 1] += tmp / 10;
            _round_up(output->int_num, dest->int_len + src->int_len); 
            d_i++;   
        }
        s_i++; 
    }
    output->float_len = s_i + d_i;
    return ;
}

int multiply_num(t_info *dest, t_info *src, t_info *output)
{   
    int output_len = 0;
    
    output->sign = _check_sign(dest->sign, src->sign);
    _int_mul_int(dest, src, output);
    if ((src->int_len == 1 && src->int_num[0] == 0) || \
        (dest->int_len == 1 && dest->int_num[0] == 0))
        output->int_len = 1;
    if (src->float_sign)
        output->float_len = _int_mul_float(dest, src, output);
    if (dest->float_sign)
        output_len = _int_mul_float(src, dest, output);
    if (output_len > output->float_len)
        output->float_len = output;
    if 
    _float_mul_float(dest, src, output);
    return (TRUE);
} */