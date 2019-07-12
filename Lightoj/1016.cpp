#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    int i,j,k;
    int n,t,w, cases=1;
    LL x,y;
    vector<LL>V;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &w);
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld", &x, &y);
            V.push_back(y);
        }
        sort(V.begin(), V.end());
        LL range=-1000000009LL;
        int cnt=0;
        for(i=0; i<n;i++)
        {
            if(V[i]>range)
            {
                range=V[i]+w;
                cnt++;
            }
        }
        printf("Case %d: %d\n", cases++, cnt);
        V.clear();
    }
    return 0;
}
