#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{   double m,h,a;
    while(scanf("%lf:%lf",&h,&m)==2)
    {   if((m==0) && (h==0))
        break;

            a=abs(((30*h)+(m/2))-(6*m));
            if(a>180)
                a=360-a;
            printf("%.3lf\n",a);



    }

    return 0;
}
