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
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
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

LL cost[MAX];
LL arr[MAX];

map<pii, int>M;
int n;
LL solve(int ind, LL sum)
{
//    cout<<ind<<" "<<sum<<endl;
    if(ind >= n)
    {
        if(sum == 1ll) return 0ll;
        return 1000000;
    }
    pii p = mp(ind, sum);
    if(M.find(p) != M.end()) return M[p];

    LL ret = solve(ind + 1, sum);
    ret = min(ret, cost[ind] + solve(ind + 1, __gcd(sum, arr[ind])));
return M[p] = ret;
}



int main()
{
    int tc,cs=1,i,j,k;
    string str;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>arr[i];
    for(i = 0; i < n; i++)
        cin>>cost[i];

    LL res = solve(0, 0ll);
    if(res >= 1000000)
        cout<<-1<<endl;
    else
    cout<<res<<endl;







    return 0;
}

/*

2
100 99
1 1

*/
