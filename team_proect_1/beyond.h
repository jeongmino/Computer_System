
#ifndef BEYOND_H
# define BEYOND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

# define TRUE   0
# define FALSE  1
# define POSITIVE 1
# define NEGATIVE -1
# define UNKNOWN 0
# define MALLOC "Malloc error!\n"
# define INPUT_ERR "Wrong input!\n"
# define CAL_ERR "There is an error on calculating\n"
int operand;
char arith_op;           //arithmetic_operator
int result;

typedef enum operand
{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVISION
}           OPERAND;

typedef struct s_info
{
    int sign; // 부호
    int one_last_minus; // ?
    int float_sign;
    int int_len; // 정수 숫자 길이
    int float_len; // 실수 숫자 길이
    int *int_num; // 정수 부분
    int *float_num;  // 소수 부분
    int round; // 올림 수 유무 (3 + 8 -> round = 1, 3 + 6 -> round = 0)
}               t_info;

/********* check_num.c *********/
int     check_num(t_info *dest, t_info *src);

/********* print_error.c *********/
void    print_error(char *status);
void    print_output(t_info *info);

/********* util.c *********/
int is_digit_and_dot(char c);

/********* calculate.c *********/
int calculate_num(t_info *dest, t_info *src, t_info *output);
/********* plus.c *********/
int plus_num(t_info *dest, t_info *src, t_info *output);

/********* minus.c *********/
void       minus_int(t_info *big, t_info *small, t_info *output);
int        minus_num(t_info *dest, t_info *src, t_info *output);

/********* multiply.c *********/
int multiply_num(t_info *dest, t_info *src, t_info *output);
#endif