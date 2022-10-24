/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:00:28 by junoh             #+#    #+#             */
/*   Updated: 2022/10/23 17:14:37 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <limits.h>

int main(void)
{
    int i_num = INT_MAX;
    double d = INT_MAX;
    
    if ((double)i_num == d)
        printf("test is success\n");
    else 
        printf("test is fail\n");
    printf("(double)i_num = %f\n", (double)i_num);
    return (0);
}
