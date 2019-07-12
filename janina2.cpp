#include <stdio.h>
#include <math.h>
int gcd( int a, int b)
{
    int k;
    do
    {
        k=a;
        a=b%a;
        b=k;
    }
    while(a!=0);
    return k;
}
int main()
{
    int n,c,a[100];
    while((scanf("%d",&n))==1)

    {
        if(n==0)
            break;
        c=(n*(n-1))/2;
        int sum,i,j,k,num;
        double d;
        sum=0,num=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                k=gcd(a[i],a[j]);
                if(k==1)
                    sum++;

            }
        if(sum!=0)

            d=sqrt((6*c)/(sum*1.0));
        if(sum==0)
            printf("No estimate for this data set.\n");
        else
            printf("%.6lf\n",d);
    }
    return 0;
}
