#include "libmath.h"
#include <stdexcept>
#include <climits>

namespace math
{

int addition(int a, int b)
{
    int out{};
    if (__builtin_add_overflow(a, b, &out))
    {
        throw std::overflow_error("integer overflow");
    }
    return out;
}

int subtraction(int a, int b)
{
    int out{};
    if (__builtin_sub_overflow(a, b, &out))
    {
        throw std::overflow_error("integer overflow");
    }
    return out;
}

int multiplication(int a, int b)
{
    int out{};
    if (__builtin_mul_overflow(a, b, &out))
    {
        throw std::overflow_error("integer overflow");
    }
    return out;
}

int division(int a, int b)
{
    if (b == 0)
    {
        throw std::domain_error("division by zero");
    }
    if (a == INT_MIN && b == -1)
    {
        throw std::overflow_error("integer overflow");
    }
    return a / b;
}
int power(int a, int b)
{
    int out{};
    if (b < 0)
    {
        throw std::domain_error("negative power");
    }
    out = 1;
    for (int i = 0; i < b; ++i)
    {
        if (__builtin_mul_overflow(out, a, &out))
        {
            throw std::overflow_error("integer overflow");
        }
    }
    return out;
}
int factorial(int n)
{
    if (n < 0)
        throw std::domain_error("negative factorial");
    if (n <= 1)
        return 1;

    int prev = factorial(n - 1);
    int out{};
    if (__builtin_mul_overflow(prev, n, &out))
        throw std::overflow_error("integer overflow");
    return out;
}
} 
