#include<bits/stdc++.h>

#define LL long long

using namespace std;

struct Z
{
    LL num;
    int val;

    bool operator<(const Z& a) const
    {
        return a.num==num?a.val<val:a.num>num;
    }
};


vector<Z>V;

int main()
{
    int i, j,k;
    int n;
    LL a,b;
    Z tmp;
    int cases=1,t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld", &a, &b);
            tmp.num=a;
            tmp.val=1;
            V.push_back(tmp);

            tmp.num=b;
            tmp.val=-1;
            V.push_back(tmp);
        }
        sort(V.begin(), V.end());

        int cnt=0, mx=0;
        int sz=V.size();


        for(i=0; i<sz; i++)
        {
            cnt+=V[i].val;
            mx=max(mx, cnt);
        }
        printf("Case %d: %d\n", cases++, mx);
        V.clear();
    }
    return 0;
}
