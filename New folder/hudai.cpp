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
    Z() {}
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

int arr[100009];

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
        arr[u]=1;
        arr[v]=1;
    }
    int cnt=0;
    for(i=1; i<=n; i++)
        if(arr[i])
            cnt++;
    LL res=bigmod(2LL, (LL)cnt, 1000000007LL)%1000000007;
    cout<<res<<endl;

    return 0;
}
