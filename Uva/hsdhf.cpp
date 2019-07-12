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
#define MX 1000009


using namespace std;

struct Z
{
    LL a, b;
    Z() {}
    Z(LL _, LL __)
    {
        a = _;
        b = __;
    }
    bool operator < (const Z& A) const
    {
        return b < A.b;
    }
};
vector<Z>V;

int main()
{

    int i, j, k;
    LL n, m;
    LL l;
    LL a, b;
    cin>>n>>m>>l;
    LL sum = 0ll;
    for(i = 0; i < n; i++)
    {
        cin>>a>>b;
        V.push_back(Z(a, b));
        sum += a;
    }
    sort(all(V));
    LL need = n * l - sum;
    if(need <= 0)
    {
        cout<<0<<endl;
        return 0;
    }
    LL tot = 0ll;
    sum = 0ll;
    for(LL i = 0; i < n; i++)
    {
        LL h = V[i].a;

        LL g = m - h;
        int mn = min(need - sum, g);
        tot += mn * V[i].b;
        sum += mn;
        if(sum == need)
            break;
//        cout<<i<<" "<<sum<<endl;
    }
    cout<<tot<<endl;



    return 0;
}

/*

5
9 2 3 4 6
5
10 7 3 2 1
*/