#include <stdio.h>
#include <math.h>
#define PI 3.1416


main()
{
    float x, x1, x2, y, p, q, r;
    x1 = -2.0;
    x2 = -1.0;
    p = x1*x1 - 4 * x1 - 10;
    q = x2*x2 - 4 * x2 - 10;
    while(p*q < 0.0 && fabs(x1-x2) > 1e-6)
    {
        x = (x1 + x2)/2.0;
        r = x*x - 4 * x - 10;
        if(p*r < 0.0)
            x2 = x;
        else
            x1 = x;
    }
    printf("%f\n", x1);
}

