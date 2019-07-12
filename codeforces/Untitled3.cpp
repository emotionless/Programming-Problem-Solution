#include<stdio.h>

long long A[209],B[22][22][22],count,Cal[209][12];
int cas,cas1,n,q,q1,i,j,k,t,d,m,k1,sak,C[22];

int main()
{

    for(i=1; i<=200; i++)
    {
        Cal[i][1]=i;
        for(j=2; j<=10; j++)
        {
            if(i<j)
                break;
            Cal[i][j]=(Cal[i][j-1]*(i-j+1))/j;
        }
    }

    scanf("%d",&cas);

    for(cas1=1; cas1<=cas; cas1++)
    {
        scanf("%d %d",&n,&q);

        for(i=0; i<n; i++)
            scanf("%lld",&A[i]);

        printf("Case %d:\n",cas1);

        for(q1=1; q1<=q; q1++)
        {
            scanf("%d %d",&d,&m);

            for(i=0; i<d; i++)
                C[i]=0;

            for(i=0; i<n; i++)
            {
                sak = A[i]%d;
                if(sak<0)
                    sak+=d;
                C[sak]++;
            }

            for(i=0; i<d; i++)
                for(j=0; j<m; j++)
                    for(k=0; k<d; k++)
                        B[i][j][k]=0;

            for(i=0; i<d; i++)
            {
                for(j=0; j<C[i]; j++)
                {
                    if(j>=m)
                        break;
                    sak = (i * (j+1))%d;
                    B[i][j][sak]+=Cal[C[i]][j+1];
                }
            }

            for(i=0; i<d-1; i++)
                for(j=0; j<m; j++)
                    for(k=0; k<d; k++)
                        if(B[i][j][k]!=0)
                        {
                            for(k1=0; k1<C[i+1]; k1++)
                            {
                                if(j+k1+1>=m)
                                    break;

                                t = ((i+1) * (k1+1))%d;
                                t = (t + k)%d;

                                B[i+1][j+k1+1][t] += B[i][j][k]*Cal[C[i+1]][k1+1];
                            }

                            B[i+1][j][k]+=B[i][j][k];
                        }

            count = B[d-1][m-1][0];

            printf("%lld\n",count);

        }

    }

    return 0;
}
\
