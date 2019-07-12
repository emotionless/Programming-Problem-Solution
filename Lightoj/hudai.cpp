#include <stdio.h>
#include <stdlib.h>
int main()
{
    long a[100000],d,b,c,i,j,m;
    int n;
    while(scanf("%d",&n)==1)

    {
        d=2000000;
        for(i=1; i<=n; i++)
            scanf("%ld",&a[i]);
        scanf("%ld",&m);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)

                if((a[i]+a[j])==m && j!=i )
                {
                    if(a[i]>a[j])
                    {

                        if((a[i]-a[j])<d)
                        {
                            b=a[i];
                            c=a[j];
                            d=a[i]-a[j];
                        }

                    }
                    else
                    {
                        if((a[j]-a[i])<d)
                        {
                            b=a[j];
                            c=a[i];
                            d=a[j]-a[i];

                        }

                    }
                }

        printf("Peter should buy books whose prices are %ld and %ld.\n\n",b,c);
    }

    return 0;
}


/*


4
45 45 45 35
80


*/
