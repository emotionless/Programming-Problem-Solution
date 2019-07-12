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

///***** Constant ******//
#define MX 10007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7
#define sc(a) scanf("%d", &a)
#define fr(i, a) for(i = 0; i < a; i++)


using namespace std;

int arr[MX];

int store[1000009];

int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int n, m;
    scanf("%d", &n);
    fr(i, n)
    sc(arr[i]);
    int ind = 0;
    fr(i, n)
    {
        fr(j, n)
        {
            fr(k, n)
            {
                store[ind++] = arr[i]*arr[j]+arr[k];
            }
        }
    }
    sort(store, store + ind);
    int cnt = 0;
    fr(i, n)
    {
        if(arr[i] == 0) continue;
        fr(j, n)
        {
            fr(k, n)
            {
                int mul = arr[i]*arr[j]+arr[i]*arr[k];
                cnt += upper_bound(store, store + ind, mul) - lower_bound(store, store + ind, mul);
            }
        }
    }
    printf("%d\n", cnt);






    return 0;
}
/*

1 1 5 1
3 7 3 1



*/
