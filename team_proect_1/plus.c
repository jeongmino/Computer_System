/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:26:42 by junoh             #+#    #+#             */
/*   Updated: 2022/10/17 11:39:54 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beyond.h"

static  int _plus_int(t_info *dest, t_info *src, t_info *output)
{
    int i = 0;    
    int ten_plus = 0;
    int big_len;
    
    if (dest->int_len > src->int_len)
        big_len = dest->int_len;
    else
        big_len = src->int_len;
    while (i < big_len)
    {
        output->int_num[i] += ten_plus;
        ten_plus = 0;
        output->int_num[i] = src->int_num[i] + dest->int_num[i];
        if (output->int_num[i] >= 10)
        {
            output->int_num[i] -= 10;
            ten_plus = 1;    
        }
        i++;
    }   
}

int plus_num(t_info *dest, t_info *src, t_info *output)
{
    
}