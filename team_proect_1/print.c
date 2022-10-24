/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:40:38 by junoh             #+#    #+#             */
/*   Updated: 2022/10/22 16:58:10 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./beyond.h"

void print_error(char *status)
{
    if (!strncmp(status, MALLOC, strlen(status)))
        printf("%s%s", PINK, MALLOC);
    if (!strncmp(status, INPUT_ERR, strlen(status)))
        printf("%s%s", G_BLUE, INPUT_ERR);
    if (!strncmp(status, CAL_ERR, strlen(status)))
        printf("%s%s", G_BLUE, CAL_ERR);
    exit(1);
}

void    print_output(t_info *info)
{
    int *f_num = info->float_num;
    int *i_num = info->int_num;
    int i;

    i = info->int_len - 1;
    printf("output : ");
    if (info->sign == -1)
        putchar('-');
    while (i >= 0)
        printf("%d", i_num[i--]);
    if (info->float_sign)
    {
        printf(".");
        i = info->float_len - 1;
        while (i >= 0)
            printf("%d", f_num[i--]);
    }
    putchar('\n');
    return ;
}