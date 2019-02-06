#include <stdio.h>

const char* const info = R"(

After reading http://www.egr.unlv.edu/~ed/assembly64.pdf I finally understand how
floating-point numbers really work.

What is this experiment about?

float consits of:
    * 1  bit for a sign
    * 8  bits of exponent
    * 23 bits of mantissa

If we fill all mantissa bits with the integer part of a number there will be no room left
for the fractional part.
Leading one is implicit and not stored in the mantissa.

(2^24 - 1) >= number will cover all manitissa bits with the integer part, fractional part
will be cut off.

2^24 number has the least significant bit cut off.
That's why if we add 1 to it (2^24 - 1 + 2) the value will not change.

(2^23 - 1)    number has one bit left for the fractional part. The fractional part
can only be equal to 0.5 because this is as far as we can go with only one bit.

If there is not enough bits for the required precision rounding will happen.

This experiment is about proving these properties of a floating-point number
on the x64 machine.

)";

const char* const format = R"(

2^%d - 1
int           = %d
float         = %.9g
float + 0.125 = %.9g
float + 0.250 = %.9g
float + 0.300 = %.9g
float + 0.5   = %.9g
float + 0.750 = %.9g
float + 0.875 = %.9g
float + 1     = %.9g
float + 2     = %.9g

)";

int main()
{
    printf("%s", info);

    for(int i = 22; i < 25; ++i)
    {
        int   ivar = (1 << i) - 1;
        float fvar = ivar;

        printf(format, i, ivar, fvar, fvar + 0.125f, fvar + 0.250f, fvar + 0.300f,
               fvar + 0.5f, fvar + 0.750f, fvar + 0.875f, fvar + 1.f, fvar + 2.f);
    }

    return 0;
}
