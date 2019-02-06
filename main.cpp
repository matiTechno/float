#include <stdio.h>

int main()
{
    int ivar = 0b1111111111111111111111;   // 22 ones
    float var1 = ivar;

    ivar     = 0b11111111111111111111111;  // 23 ones
    float var2 = ivar;
    
    ivar     = 0b111111111111111111111111; // 24 ones
    float var3 = ivar;


    // what this experiment is about?
    // float number on x64 consists of:
    // * 1 sign bit (set if a value is negative)
    // * 8 bits of exponent
    // * 23 bits of mantissa

    // if we feel all the mantissa bits with a whole part of a number
    // there is no room for a reminder part

    // in the mantissa we don't store leading one so to cover all the bits with a
    // whole part of a number it needs to be >= 2^24

    // the experiment will show that with 2^23 number there is still room for one
    // bit of a reminder but when the number is >= 2^24 only whole part fits

    // and with 23 bits of a whole part only 0.5 can be stored as a reminder - there
    // is no room for more precision

    // if there is no room for precision some rounding will happen

    // I included float + 0.3f test to see how rounding of the reminder part
    // works

    const char* format = R"(

    float (2^22): = %f
    float + 0.3   = %f
    float + 0.5   = %f
    float + 0.750 = %f
    float + 0.875 = %f

    float (2^23): = %f
    float + 0.3   = %f
    float + 0.5   = %f
    float + 0.750 = %f
    float + 0.875 = %f

    float (2^24): = %f
    float + 0.3   = %f
    float + 0.5   = %f
    float + 0.750 = %f
    float + 0.875 = %f

    )";

    printf(format,
           var1, var1 + 0.3f, var1 + 0.5f, var1 + 0.750f, var1 + 0.875f,
           var2, var2 + 0.3f, var2 + 0.5f, var2 + 0.750f, var2 + 0.875f,
           var3, var3 + 0.3f, var3 + 0.5f, var3 + 0.750f, var3 + 0.875f);

    return 0;
}
