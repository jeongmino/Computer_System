/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:30:17 by junoh             #+#    #+#             */
/*   Updated: 2022/10/30 12:44:17 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beyond.h"

int _check_sign(int dest_sign, int src_sign)
{
    if (dest_sign + src_sign == 0)
        return (-1);
    else
        return 1;
}

void _int_mul_int(t_info *dest, t_info *src, t_info *output)
{
    int *tmp_arr = (int *)calloc(1000, sizeof(int));
    int tmp = 0;
    int d_exp = 0;
    int s_exp = 0;
    int d_i = 0;
    int s_i = 0;
    int idx = 0;
        
    if (tmp_arr == NULL)
        return ;
    while (s_i < src->int_len)
    {
        s_exp = s_i;
        while (d_i < dest->int_len)
        {
            d_exp = d_i;
            tmp = dest->int_num[d_i] * src->int_num[s_i];
            tmp_arr[idx] = tmp % 10;
            tmp_arr[idx + 1] =tmp / 10;
            idx++;   
        } 
    }
    
    free(tmp_arr);
}

int multiply_num(t_info *dest, t_info *src, t_info *output)
{
    output->sign = _check_sign(dest->sign, src->sign);
    
}