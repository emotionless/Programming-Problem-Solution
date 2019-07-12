#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second
#define pi pair<int, int>
#define mp make_pair
#define fr(i, a) for(i = 0; i < a; i++)
#define sc(a) scanf("%d", &a)

///***** Constant ******//
#define MX 10007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7
#define ll long long

using namespace std;

ll store[1<<20];
ll arr[50];
int main()
{
    int i,j,k;
    int cases=1;
    int t;
    ll A, B;
    int n, m;
    scanf("%d %lld %lld", &n, &A, &B);
    fr(i, n)
    scanf("%lld", &arr[i]);
    int n1 = n/2;
    int n2 = n - n1;
    k = 0;
    bool is = true;
    for(i = 0; i < (1<<n2); i++)
    {
        ll sum = 0ll;
        for(j = 0; j < n2; j++)
        {
            if(i&(1<<j))
                sum += arr[j + n1];
        }
        store[k++] = sum;
    }
    sort(store, store + k);
    ll res = 0ll;
    for(i = 0; i < (1<<n1); i++)
    {
        ll sum = 0ll;
        for(j = 0; j < n1; j++)
        {
            if(i&(1<<j))
                sum += arr[j];
        }
        res += upper_bound(store, store + k, B-sum) - lower_bound(store, store + k, A-sum);
//        cout<<sum<<" "<<have<<endl;
    }
    printf("%lld\n", res);














    return 0;
}
/*

1 1 5 1
3 7 3 1



*/
