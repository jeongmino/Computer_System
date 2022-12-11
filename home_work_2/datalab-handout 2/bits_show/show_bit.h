#ifndef SHOW_BIT_H
# define SHOW_BIT_H

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

enum {
    PLUS,
    LEFT,
    RIGHT,
    OR,
    AND,
    XOR,
    NOT,
    NO
};

/********* show_bits.c *********/
void    change_into2(int *arr, int bit);
void    print_bit(int *arr);

/********* plus.c *********/
void    plus(int *arr);

/********* operation.c *********/
void    operation(int *arr, char *operator);

/********* and_or_operation.c *********/
void    or_operation(int *arr);
void    and_operation(int *arr);
void    sym_diff(int *arr);

/********* shift.c *********/
void    right_shift(int *arr);
void    left_shift(int *arr);

/********* not_operation.c *********/
void    not_operation(int *arr);
#endif