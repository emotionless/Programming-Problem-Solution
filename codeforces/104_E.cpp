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
#define MAX 200009


using namespace std;


LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}

LL fact[100009];

LL ncr(int n, int k)
{
    if(k>n) return 0;
    LL mult=fact[n];
    LL div=(fact[n-k]*fact[k])%MOD;
    LL ret=(mult*bigmod(div,MOD-2,MOD))%MOD;
    return ret;
}


int n, k;
int ind = -1;
map<LL, int>M;


void Build(LL num)
{
    if(num > 1000000000) return;
    if(M[num]) return;
    M[num] = (++ind);
//    cout<<num<<" "<<ind<<endl;
    Build(num*10 + 4);
    Build(num*10 + 7);
}

LL arr[MAX];
LL dp[1050][1050];


vector<int>V;
LL solve(int ind, int rest)
{
    if(rest>ind) return 0;
    if(rest==0) return 1;
    if(ind==1) return V[0];
    LL &ret = dp[ind][rest];
    if(ret != -1ll) return ret;
    ret = 0ll;
    ret = solve(ind - 1, rest);
    ret = (ret + (solve(ind - 1, rest - 1)*V[ind - 1]) % MOD) % MOD;
    return ret;
}

int C[1050];

int main()
{
    int tc,cs=1,i,j;
    fact[0] = 1ll;

    for(i = 1; i <= 100000; i++) fact[i] = (fact[i - 1] * i) % MOD;

    s2(n, k);
    Build(0ll);
    fr(i, n)
    {
        s1(arr[i]);
    }
    fr(i, n)
    {
        C[M[arr[i]]]++;
    }
    for(i = 1; i <= ind; i++)
    {
        if(C[i])
        {
            V.push_back(C[i]);
//        cout<<i<<" "<<C[i]<<endl;
        }
    }
    int sz = V.size();
    LL ans = 0ll;
    memset(dp, -1ll, sizeof dp);
    for(i = 0; i <= min(k, C[0]); i++)
    {
        ans = (ans + (solve(sz, k - i) * (ncr(C[0], i))) % MOD)%MOD;
//        cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;









    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
