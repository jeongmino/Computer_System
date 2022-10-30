/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:24:10 by junoh             #+#    #+#             */
/*   Updated: 2022/10/30 15:33:25 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./beyond.h"


int calculate_num(t_info *dest, t_info *src, t_info *output)
{
    // printf("operand == %d\n", operand);
    if (operand == PLUS)
        plus_num(dest, src, output);
    else if (operand == MINUS)
        minus_num(dest, src, output);
    else if (operand == MULTIPLY)
        multiply_num(dest, src, output);
    // else
    //     divide_num();
    return (TRUE);
}