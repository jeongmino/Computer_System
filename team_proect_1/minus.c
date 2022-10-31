#include "beyond.h"
#include <string.h>

char  *compare_size_int(int *dest_num, int *src_num, int dest_len, int src_len)
{
    char *bigger;
    int i;
    
    if (dest_len != src_len)
    {
        bigger = (dest_len > src_len) ?  strdup("dest") : strdup("src"); // dest > src 가 참이면 big_len = dest->int_len
        (void)i;
        return (bigger);
    }
    i = dest_len - 1;
    while (i >= 0)
    {
        if (dest_num[i] != src_num[i])
        {
            bigger = (dest_num[i] > src_num[i]) ?  strdup("dest") : strdup("src"); 
            return (bigger);
        }
        i--;
    }
    return (strdup("same"));
}

static char  *_compare_size_float(t_info *dest, t_info *src)
{
    char *bigger;
    int i;
    
    i = dest->float_len - 1;
    while (i >= 0)
    {
        if (dest->float_num[i] != src->float_num[i])
        {
            bigger = (dest->float_num[i] > src->float_num[i]) ?  strdup("dest") : strdup("src"); 
            return (bigger);
        }
        i--;
    }
    return (strdup("same"));
}

static void _change_sign(t_info *dest, t_info *src, t_info *output, char *str)
{
    char bigger;

    bigger = (!strcmp("dest", str)) ? 'd' : 's';
    if (bigger == 'd')
    {
        output->sign = 1;
        if (dest->sign == -1)
            output->sign = -1;
        return ; 
    }
    else
    {
        if (src->sign == 1 && dest->sign == 1 && arith_op == '-') // 14(dest) - 21(src)
            output->sign = -1;
        else if (src->sign == 1 && dest->sign == -1 && arith_op == '+') // -14 + 21
            output->sign = 1;
        else if (src->sign == -1 && dest->sign == 1 && arith_op == '+') // 14 + -21
            output->sign = -1;
        else                                                           // -14 - -21
            output->sign = 1;
    }
}

void minus_int(t_info *big, t_info *small, t_info *output)
{
    int i = 0;
    int round_minus = 0;
    
    while (i < big->int_len)
    {
        output->int_num[i] -= round_minus;
        round_minus = 0;
        output->int_num[i] += big->int_num[i] - small->int_num[i];
        if (output->int_num[i] < 0)
        {
            output->int_num[i] += 10;
            round_minus = 1;
        }
        i++;
    }
    output->int_len = big->int_len;
    if (output->int_num[big->int_len - 1] == 0)
        output->int_len = big->int_len;
    return ;    
}

int minus_float(t_info *big, t_info *small, t_info *output)
{
    int i = 0;
    int round_minus = 0;
    
    while (i < big->float_len)
    {
        output->float_num[i] -= round_minus;
        round_minus = 0;
        output->float_num[i] += big->float_num[i] - small->float_num[i];
        if (output->float_num[i] < 0)
        {
            output->float_num[i] += 10;
            round_minus = 1;
        }
        i++;
    }
    output->float_len = big->float_len;
    if (output->float_num[big->float_len - 1] == 0)
        output->float_len = big->float_len;
    return (round_minus);
}

int        minus_num(t_info *dest, t_info *src, t_info *output)
{
    char    *int_bigger;
    char    *float_bigger;
    int flag = 0;
    
    
    if (dest->float_sign || src->float_sign)
        output->float_sign = 1;
    int_bigger = compare_size_int(dest->int_num, src->int_num, dest->int_len, src->float_len); // 나중에 free
    if (strcmp(int_bigger, "same"))
    {                                           // bigger is not same
        _change_sign(dest, src, output, int_bigger);
        if (!strcmp(int_bigger, "dest"))
        {
            flag = minus_float(dest, src, output);
            // dest->int_num[0] -= minus_float(dest, src, output);
            dest->int_num[0] -= flag;
            minus_int(dest, src, output);
        }
        else
        {
            src->int_num[0] -= minus_float(src, dest, output);
            minus_int(src, dest, output);
        }
    }
    else
    {
        output->sign = 0;
        output->int_len = 1;
        float_bigger = _compare_size_float(dest, src);
        if (!strcmp(float_bigger, "dest"))
        {
            flag = minus_float(dest, src, output);
            if (flag == 1)
                output->sign = -1;
            else if (dest->sign == -1 && src->sign == 1)
                output->sign = -1;
        }
        else if (!strcmp(float_bigger, "src"))
        {
            flag = minus_float(src, dest, output);
            output->sign = -1;
            if (dest->sign == -1 && src->sign == 1)
                output->sign = 1;
        }
        else
        {
            output->float_sign = 1;
            output->float_len = 1;
        }
    }
    free(int_bigger);
    return (TRUE);   
}