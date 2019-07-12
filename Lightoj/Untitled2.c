#include <stdio.h>
int main()
{
    int t,a,i,j,num[100000],sum=0;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&a);
        sum=0;
        for(j=1; j<=a; j++)
        {
            scanf("%d",&num[j]);
            if(num[j] > 0)
            sum=sum+num[j];
        }
        printf("Case %d: %d",i,sum);
        printf("\n");
    }
    return 0;
}
