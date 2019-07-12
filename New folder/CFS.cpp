#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

using namespace std;

struct Z
{
    int num, val;
    Z(){}
    Z(int a, int b)
    {
        num=a;
        val=b;
    }
    bool operator<(const Z& A) const
    {
        if(A.num==num) return A.val<val;
        return A.num>num;
    }
};


int main()
{
    //   FILE * fin, * fout, *fp;
    //     fp=fopen("out.txt", "w");

    int i,j,k;
    int a,b, u, v, n, m;
    vector<Z>V;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &u, &v);
        V.PB(Z(u,1));
        V.PB(Z(v,-1));
    }
    sort(V.begin(), V.end());
    int sz=V.size();
    int res=0, cnt=0;
    for(i=0; i<sz; i++)
    {
        cnt+=V[i].val;
        if(cnt==0 && i+1!=sz)
        res+=(V[i+1].num-V[i].num-1);
    }
    LL have=n-res;

    LL ans=bigmod(2ll, have, 1000000007ll);
    cout<<ans<<endl;
    return 0;
}

/*
8 7
1 0 0 0 1 0 1 0
1 2
2 3
3 4
4 5
3 6
6 7
4 8


*/
