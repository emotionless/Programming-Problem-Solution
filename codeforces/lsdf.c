#include<stdio.h>
int main()
{
    int a, b, c,i,N;

    int arr[5];
    while(scanf("%d", &arr[0]) == 1)
    {
        b = 0;
        for(i = 1; i < 5; i++)
        {
            scanf("%d", &arr[i]);
        }
        for(i = 0; i < 5; i++)
        {
            scanf("%d", &a);
            if(a + arr[i] == 2 || a + arr[i] == 0)
                b = 1;
        }
        if(b == 0)
            printf("Y\n");
        else
            printf("N\n");
    }
return 0;
}
