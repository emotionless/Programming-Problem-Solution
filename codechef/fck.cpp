#include<bits/stdc++.h>

#define LL long long

using namespace std;



int main()
{
    int i,j,l,k;
    int t;
    int n,m;
    vector<LL>V[100001];
    LL final[100001];
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        LL num;
        LL sum[n+2];
        memset(sum,0, sizeof sum);
        for(i=0; i<n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%lld", &num);
                V[i].push_back(num);
                sum[i]+=num;
            }
        }
        for(i=0; i<m; i++)
            scanf("%lld", &final[i]);

        int ind=-1;
        LL mx=-1;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(V[i][j]>final[j])
                    break;
            }
            if(j==m)
            {
                if(sum[i]>mx)
                {
                    mx=sum[i];
                    ind=i;
                }
            }
        }
        if(ind==-1)
            cout<<0<<endl;
        else
        {
            cout<<1<<endl;
            cout<<ind+1<<endl;
        }
    }

    return 0;
}
