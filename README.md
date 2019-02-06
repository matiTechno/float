# float
```
$ ./test 


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



2^22 - 1
int           = 4194303
float         = 4194303
float + 0.125 = 4194303
float + 0.250 = 4194303.25
float + 0.300 = 4194303.25
float + 0.5   = 4194303.5
float + 0.750 = 4194303.75
float + 0.875 = 4194304
float + 1     = 4194304
float + 2     = 4194305



2^23 - 1
int           = 8388607
float         = 8388607
float + 0.125 = 8388607
float + 0.250 = 8388607
float + 0.300 = 8388607.5
float + 0.5   = 8388607.5
float + 0.750 = 8388608
float + 0.875 = 8388608
float + 1     = 8388608
float + 2     = 8388609



2^24 - 1
int           = 16777215
float         = 16777215
float + 0.125 = 16777215
float + 0.250 = 16777215
float + 0.300 = 16777215
float + 0.5   = 16777216
float + 0.750 = 16777216
float + 0.875 = 16777216
float + 1     = 16777216
float + 2     = 16777216
```
