
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
}               t_info;

/********* beyond.c *********/
void free_all(t_info *dest, t_info *src, t_info *output);
int init_info(t_info *dest, t_info *src, t_info *output);

/********* check_num.c *********/
int     check_num(t_info *dest, t_info *src);
void    set_float(t_info *dest, t_info *src);

/********* print_error.c *********/
void    print_error(char *status);
void    print_output(t_info *info);

/********* util.c *********/
int is_digit_and_dot(char c);

/********* calculate.c *********/
int calculate_num(t_info *dest, t_info *src, t_info *output);
/********* plus.c *********/
int plus_num(t_info *dest, t_info *src, t_info *output);
int plus_float(t_info *dest, t_info *src, t_info *output);
void plus_one(t_info *output, int plus);

/********* minus.c *********/
void       minus_int(t_info *big, t_info *small, t_info *output);
int        minus_num(t_info *dest, t_info *src, t_info *output);
char        *compare_size_int(int *dest_num, int *src_num, int dest_len, int src_len);

/********* multiply.c *********/
int multiply_num(t_info *dest, t_info *src, t_info *output);
int check_sign(int dest_sign, int src_sign);
#endif