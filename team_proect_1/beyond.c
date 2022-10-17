/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beyond.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:24:05 by junoh             #+#    #+#             */
/*   Updated: 2022/10/14 16:27:37 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./beyond.h"

static void _free_all(t_info *dest, t_info *src, t_info *output)
{
    free(dest->int_num);
    free(dest->float_num);
    free(src->int_num);
    free(src->float_num);
    free(output->int_num);
    free(output->float_num);
}

static int _init_info(t_info *dest, t_info *src, t_info *output)
{
    dest->int_num = malloc(sizeof(int) * 500);
    src->int_num = malloc(sizeof(int) * 500);
    output->int_num = malloc(sizeof(int) * 500);
    if (!dest->int_num || !src->int_num || !output->int_num)
        return (FALSE);
    dest->float_num = malloc(sizeof(int) * 500);
    src->float_num = malloc(sizeof(int) * 500);
    output->float_num = malloc(sizeof(int) * 500);
    if (!dest->float_num || !src->float_num || !output->float_num)
        return (FALSE);
    return (TRUE);
}

int main(void)
{
    t_info dest;
    t_info src;
    t_info output;
    int continue_flag;
    
    while (1)
    {
        operand = 0;
        result = 0;
        continue_flag = 1;
        memset(&dest, 0, sizeof(t_info));
        memset(&src, 0, sizeof(t_info));
        memset(&output, 0, sizeof(t_info));
        if (_init_info(&dest, &src, &output) == FALSE)
            print_error(MALLOC);
        if (check_num(&dest, &src) == FALSE)
        {
            continue_flag = 0;   
            print_error(INPUT_ERR);
        }
        // if (continue_flag)
        // {
        //     if (calculate_num(&dest, &src, &output) == FALSE)
        //     {
        //         continue_flag = 0;
        //         print_error(CAL_ERR);
        //     }
        // }
        // if (continue_flag)
        //     print_output();
        if (continue_flag)
        {
            print_output(&dest);
            print_output(&src);
        }
        // print_output(&output);
        _free_all(&dest, &src, &output);
    }
    return 1;            
}