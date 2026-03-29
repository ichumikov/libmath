#include "libmath.h"

#include <climits>


//errors:
//0 -success
//-1 - division by zero
//-2 - factorial by negative number
//-3 - overflow
//-4 - negative power


namespace math
{

int addition(int a, int b, int& out)
{
    if (__builtin_add_overflow(a, b, &out))
    {
        return -3;
    }
    return 0;
}
int subtraction(int a, int b, int& out)
{
    if (__builtin_sub_overflow(a, b, &out))
    {
        return -3;
    }
    return 0;
}
int multiplication(int a, int b, int& out)
{
    if (__builtin_mul_overflow(a, b, &out))
    {
        return -3;
    }
    return 0;
}
int division(int a, int b, int& out)
{
    if (b == 0)
    {
        return -1;
    }
    // The only overflowing signed int division case.
    if (a == INT_MIN && b == -1)
    {
        return -3;
    }
    out = a / b;
    return 0;
}
int power(int a, int b, int& out)
{
    if (b < 0)
    {
        return -4;
    }
    out = 1;
    for (int i = 0; i < b; ++i)
    {
        if (__builtin_mul_overflow(out, a, &out))
        {
            return -3;
        }
    }
    return 0;
}
int factorial(int n, int& out)
{
    if (n < 0)
    {
        return -2;
    }

    if (n <= 1)
    {
        out = 1;
        return 0;
    }

    int prev = 0;
    int rc = factorial(n - 1, prev);
    if (rc != 0)
    {
        return rc;
    }

    if (__builtin_mul_overflow(prev, n, &out))
    {
        return -3;
    }

    return 0;
}
} 
