#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define mp make_pair
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007
#define MX 100009
#define M 63
#define pcs(a, b) printf("Case %d: %lld\n", a, b)

using namespace std;

LL arr[110];
int n;

int gauss()
{
    int i = 0, j = 0, k = 0;

    for(i = M; i >= 0; i--)
    {
        for(k = j; k < n; k++)
            if(arr[k] & (1ll<<i))
                break;
        if(k < n)
        {
            swap(arr[k], arr[j]);
            for(k = 0; k < n; k++)
            {
                if(k != j && (arr[k] & (1ll<<i)))
                    arr[k] ^= arr[j];
            }
            j++;
        }
    }
return j;
}


int main()
{

    int i, j, k;
    int t, cases = 1;


    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i = 0; i < n; i++) cin>>arr[i];
        k = gauss();
        LL ans = 0ll;
        for(i = 0; i < k; i++)
            ans ^= arr[i];
        pcs(cases++, ans);
    }

    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
