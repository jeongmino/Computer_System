/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:12:40 by junoh             #+#    #+#             */
/*   Updated: 2022/10/22 17:00:12 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./beyond.h"

static  void    _check_sign(char *str, t_info *info, int *i)
{
    if (str[0] == '-' || str[0] == '+')
    {
        info->sign = 1;
        if (str[0] == '-')
            info->sign = -1;
        *i = 1;
    }
    return ;
}     

static void _set_float(t_info *dest, t_info *src)
{
    int big_len;
    int small_len;
    int i;
    int j;
    
    if (dest->float_len == src->float_len)
    {
        (void)big_len;
        (void)small_len;
        return ;
    }
    else if (dest->float_len > src->float_len)
    {
        j = dest->float_len - 1;
        i = src->float_len - 1;
        while (i >= 0)
            src->float_num[j--] = src->float_num[i--];
        i = src->float_len - 2;
        while (i >= 0)
            src->float_num[i--] = 0;
        src->float_len = dest->float_len;
    }
    else
    {
        j = dest->float_len - 1;
        i = src->float_len - 1;
        while (i >= 0)
            dest->float_num[i--] = dest->float_num[j--];
        j = dest->float_len - 2;
        while (j >= 0)
            dest->float_num[j--] = 0;
        dest->float_len = src->float_len;
    }
    
}

static  int _change_position(char *str, t_info *info)
{
    int i;
    int j;
    int int_i;
      
    i = 0;
    _check_sign(str, info, &i);
    while (str[i] != '\0')
    {
        if (str[i++] == '.')
        {
            info->float_sign = 1;
            int_i = i - 2;
            break;
        }
        info->int_len++;
    }
    // if (info->float_sign)
    // {
    //     j = 0;
    //     while (str[i] != '\0')
    //     {
    //         if (str[i] == '.' || is_digit_and_dot(str[i]) == FALSE)
    //             return (FALSE);
    //          info->float_num[j++] = str[i++] - '0';
    //         info->float_len++;
    //     }
    //     i = int_i;
    // }
    // else
    //     i--;
    if (info->float_sign)
    {
        while (str[i] != '\0')
        {
            if (str[i] == '.' || is_digit_and_dot(str[i]) == FALSE)
                return (FALSE);
            i++;
        }
        j = 0;
        while (str[--i] != '.')
        {
            info->float_num[j++] = str[i] - '0';
            info->float_len++;
        }
        i--;
    }
    else
        i--;
    j = 0;
    while (i > 0)
    {
        if (is_digit_and_dot(str[i]) == FALSE)
                return(FALSE);
        info->int_num[j++] = str[i--] - '0';
    }
    if (info->sign == 0) // '-', '+' 기호가 없는 경우
    {
        info->sign = 1;   
        info->int_num[j] = (str[0] - '0');
    }
    return (TRUE);
}

static  int    _set_operand(char *oper_c, int dst_sign, int src_sign)
{
    if (strncmp(oper_c, "+", strlen(oper_c)) == 0)
    {
        if (!(dst_sign ^ src_sign))
            operand = PLUS;
        else
        {
            arith_op = '+';
            operand = MINUS;
        }
    }
    else if (strncmp(oper_c, "-", strlen(oper_c)) == 0)
    {
        if (dst_sign + src_sign == 0)
            operand = PLUS;
        else
        {
            arith_op = '-';
            operand = MINUS;
        }
    }
    else if (strncmp(oper_c, "*", strlen(oper_c)) == 0) 
        operand = MULTIPLY;
    else if (strncmp(oper_c, "/", strlen(oper_c)) == 0)
        operand = DIVISION;
    else
    {
        printf("Wrong Operand Input!\n");
        return (FALSE);
    }
    return (TRUE);
}

int check_num(t_info *dest, t_info *src)
{
    char dest_s[500];
    char src_s[500];
    char oper_c[2]; // 뒤에 '\0' 고려
    
    printf("Input your first number : ");
    scanf("%s", dest_s);
    printf("Input your second number : ");
    scanf("%s", src_s);
    printf("Input your operand : ");
    scanf("%s", oper_c);
    if (_change_position(dest_s, dest) == FALSE)
        return(FALSE);
    if (_change_position(src_s, src) == FALSE)
        return (FALSE);
    _set_float(dest, src);
    if (_set_operand(oper_c, dest->sign, src->sign) == FALSE)
        return (FALSE);
    return (TRUE);
}