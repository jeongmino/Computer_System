/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:15:13 by junoh             #+#    #+#             */
/*   Updated: 2022/10/31 03:45:16 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "beyond.h"

int int_divide_int(t_info *dest, t_info *src, t_info *output)
{
    int q = 0;
    int r = 0;
    int i;
    int dest_len;
    int 
    int *dest_tmp = (int *)calloc(500, sizeof(int));
    char *diff;
    
    if (dest_tmp == NULL)
        return (FALSE);
    i = -1;
    while (++i < dest->int_len)
        dest_tmp[i] = dest->int_len[i];
    dest_len = dest->int_len;
    diff = compare_size_int(dest->int_num, src->int_num, dest->int_len, src->int_len);
    while (!strcmp(diff, "src"))
    {
        i = 0;
        while (i < src->int_len)
        {
            dest_tmp[i + ] 
        }
    }
}

int divide_num(t_info *dest, t_info *src, t_info *output)
{
    char *str;
    
    output->sign = check_sign(dest->sign, src->sign);
    str = compare_size_int(dest->int_num, src->int_num, dest->int_len, src->int_len);
    if (!strcmp(str, "same"))
    {
        output->int_len = 1;
        output->int_num[0] = 1;
        return (TRUE);
    }
    else if (!strcmp(str, "src"))
    {
        output->int_len = 1;
        return (TRUE);
    }
    else if (!strcmp(str, "dest"))
    {
        int_divide_int(dest, src, output);
}