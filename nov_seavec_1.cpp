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
        for(i=0; i<n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%lld", &num);
                V[i].push_back(num);
            }
        }
        for(i=0; i<m; i++)
            scanf("%lld", &final[i]);

        bool c=1;
        for(i=n-1; i>=0; i--)
        {
            for(j=0; j<m; j++)
            {
                if(V[i][j]>final[j])
                    break;
            }
            if(j==m)
            {
                c=0;
                cout<<1<<endl<<i+1<<endl;
                break;
            }
        }
        if(c)
            cout<<0<<endl;
    }

    return 0;
}
