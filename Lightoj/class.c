#include<stdio.h>

int main()
{
    int a,b,c;

    //  for(i = 0; i < 3; i++)
    {
        c = 5;
        b = 5 + (++c) + (c++);
        printf("%d", b);

    }
    return 0;
}
