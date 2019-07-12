#include<stdio.h>

#define LL long long



int main()
{
    int i,j,l,k;
    int t;
    int n,m;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        LL num;

        LL final[n+2];
        LL V[n+2][m+2];
        LL sum[n+2];
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%lld", &num);
                V[i][j]=num;
                sum[i]+=num;
            }
        }
        for(i=1; i<=m; i++)
            scanf("%lld", &final[i]);

        int ind=-1;
        LL mx=-1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(V[i][j]>final[j])
                    break;
            }
            if(j==m+1)
            {
                if(sum[i]>mx)
                {
                    mx=sum[i];
                    ind=i;
                }
            }
        }
        if(ind==-1)
            printf("0\n");
        else
        {
            printf("1\n%d\n", ind);
        }
    }

    return 0;
}
