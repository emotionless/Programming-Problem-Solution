#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MX 200009


using namespace std;

int arr[MX];

int main()
{
    int tc,cs=1,i,j,k;
    int n, m;

    cin>>n;
    fr(i, n)
    cin>>arr[i];
    int res = INT_MAX;
    for(i = 1; i < n - 1; i++)
    {
        int ans = 0;
        int dif = 0;
        for(j = 1; j < n; j++)
        {
            if(i == j) continue;

            if(j - 1 == i)
                dif = abs(arr[j] - arr[j - 2]);
            else
                dif = abs(arr[j] - arr[j - 1]);
            ans = max(ans, dif);
        }
        res = min(res, ans);
    }
    cout<<res<<endl;

    return 0;
}

/*





*/