#include "beyond.h"

int check_sign(int dest_sign, int src_sign)
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

static int _float_round_up(int *arr, int output_len)
{
    int i = 0;

    while (i < output_len)
    {
        if (arr[i] >= 10)
        {
            arr[i] -= 10;
            arr[i + 1] += 1;
        }
        i++;
    }
    if (arr[i] != 0)
    {
        arr[i] -= 1;
        return (1);
    }
    return (0);
}

static int _int_mul_float(t_info *int_n, t_info *float_n, t_info *output)
{
    int tmp = 0;
    int int_i;
    int float_i = 0;
    int float_exp = 0;
    int exp = 0;
    
    int flag = 0;
    while (float_i < float_n->float_len)
    {
        int_i = 0;
        while (int_i < int_n->int_len)
        {
            float_exp = -(float_n->float_len - float_i);
            exp = float_exp + int_i;
            tmp = int_n->int_num[int_i] * float_n->float_num[float_i];
            if ((exp < 0 && exp != -1) || (exp == -1 && tmp < 10))
            {
                output->float_num[float_i] += tmp % 10;
                flag = _float_round_up(output->float_num, float_n->float_len);
                output->int_num[0] += flag;
                output->float_num[float_i + 1] += tmp / 10;
                output->int_num[0] += _float_round_up(output->float_num, float_n->float_len);
            }
            else if (exp == -1 && tmp >= 10)
            {
                output->float_num[float_n->float_len - 1] += tmp % 10;
                output->int_num[0] += _float_round_up(output->float_num, float_n->float_len);
                output->int_num[0] += tmp / 10;
                _round_up(output->int_num, int_n->int_len + 1); 
            }
            else if (exp >= 0)
            {
                output->int_num[exp] += tmp % 10;
                _round_up(output->int_num, int_n->int_len + 1); 
                output->int_num[exp + 1] += tmp / 10;
                _round_up(output->int_num, int_n->int_len + 1); 
            }
            int_i++;   
        }
        float_i++; 
    }
    return (float_n->float_len);
}

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

static int _float_mul_float(t_info *dest, t_info *src, int *float_num)
{
    int tmp = 0;
    int d_i;
    int s_i = 0;
        
    while (s_i < src->float_len)
    {
        d_i = 0;
        while (d_i < dest->float_len)
        {
            tmp = dest->float_num[d_i] * src->float_num[s_i];
            float_num[s_i + d_i] += tmp % 10;
            _round_up(float_num, dest->float_len + src->float_len); 
            float_num[s_i + d_i + 1] += tmp / 10;
            _round_up(float_num, dest->float_len + src->float_len); 
            d_i++;   
        }
        s_i++; 
    }
    return (s_i + d_i);
}

static int _float_plus_float(t_info *output, t_info *tmp)
{
    int diff = output->float_len - tmp->float_len;
    int *num = (int *)calloc(500, sizeof(int));
    int i = 0;

    if (num == NULL)
        return (0);
    if (diff == 0)
    {
        while (i < output->float_len)
        {
            num[i] = output->float_num[i] + tmp->float_num[i];
            if (num[i] >= 10)
            {
                num[i] -= 10;
                num[i + 1] += 1;
            }
            i++;
        }
        i = -1;
        while (++i < output->float_len)
            output->float_num[i] = num[i];
    }
    else if (diff < 0)
    {
        diff *= -1;
        while (i < diff)
        {
            num[i] = tmp->float_num[i];
            i++;
        }
        while (i < tmp->float_len)
        {
            num[i] = tmp->float_num[i] + output->float_num[i - diff];
            if (num[i] >= 10)
            {
                num[i] -= 10;
                num[i + 1] += 1;
            }
            i++;
        }
        i = -1;
        while (++i < tmp->float_len)
            output->float_num[i] = num[i];
        output->float_len = tmp->float_len;
    }
    else
    {
        while (i < diff)
            num[i] = output->float_num[i];
        while (i < output->float_len)
        {
            num[i] = tmp->float_num[i - diff] + output->float_num[i];
            if (num[i] >= 10)
            {
                num[i] -= 10;
                num[i + 1] += 1;
            }
            i++;
        }
         i = -1;
        while (++i < output->float_len)
        {
            printf("[%d] = %d\n", i, num[i]);
            output->float_num[i] = num[i];
        }
    }
    if (num[i] != 0)
    {
        free(num);
        return (1);
    }
    free(num);
    return (0);   
}

int multiply_num(t_info *dest, t_info *src, t_info *output)
{   
    int output_len = 0;
    int flag;
    t_info *tmp = (t_info *)calloc(1, sizeof(t_info));
    
    output->sign = check_sign(dest->sign, src->sign);
    _int_mul_int(dest, src, output);
    //  print_output(output);
    if (!src->float_sign && !dest->float_sign)
        output->float_sign = 0;
    else if (dest->int_len == 1 && dest->int_num[0] == 0 && \
            (src->int_len == 1 && src->int_num[0] == 0))
    {
         printf("???\n");
        output->float_sign = 1;
        output->float_len = _float_mul_float(dest, src, output->float_num);
    }
    else
    {
        output->float_sign = 1;
        output->float_len = _int_mul_float(dest, src, output);
        output_len = _int_mul_float(src, dest, output);
        if (output_len > output->float_len)
            output->float_len = output_len;
        if (src->float_sign && dest->float_sign)
        {
            tmp->float_num = (int *)calloc(500, sizeof(int));
            if (tmp->float_num == NULL)
                return (FALSE);
            tmp->float_len = _float_mul_float(dest, src, tmp->float_num);
            flag = _float_plus_float(output, tmp);
            output->int_num[0] += flag;
        }
        if (output_len > output->float_len)
            output->float_len = output_len;
    }
    free(tmp->float_num);
    free(tmp);
    return (TRUE);
} 