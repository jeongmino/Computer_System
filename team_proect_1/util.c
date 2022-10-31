#include "beyond.h"

int is_digit_and_dot(char c)
{
    if ((c >= '0' && c <= '9') || c == '.')
        return(TRUE);
    return(FALSE);
}
