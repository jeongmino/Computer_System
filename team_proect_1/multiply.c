/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:30:17 by junoh             #+#    #+#             */
/*   Updated: 2022/10/30 15:43:46 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// static void _int_mul_float(t_info *dest, t_info *src, t_info *output)
// {
    
// }

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

int multiply_num(t_info *dest, t_info *src, t_info *output)
{   
    output->sign = _check_sign(dest->sign, src->sign);
    _int_mul_int(dest, src, output);
    if ((src->int_len == 1 && src->int_num[0]) || )
    // _int_mul_float(dest, src, output);
    return (TRUE);
}