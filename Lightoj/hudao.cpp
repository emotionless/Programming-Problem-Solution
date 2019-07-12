#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
struct ASDF
{
    ASDF& operator,(int &a)
    {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a)
    {
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a)
    {
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c)
    {
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d)
    {
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a)
    {
        cin>>a;
        return *this;
    }
} asdf;
struct ASDFG
{
    template<typename T>
    ASDFG& operator,(vector<T> &v)
    {
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v))
        {
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x)
    {
        cout<<x<<" ";
        return *this;
    }


} asdfg;



//Header ends here
#define MAXX 152

ll cnt[MAXX];

int main()
{
    int kases, kaseno = 0;

    take(kases);
    int n, x;

    while(kases--)
    {
        take(n, x);
        mem(cnt, 0);

        cnt[0] = 1;
        int mx;
        loop(tt, n)
        {
            mx = 6*tt;

            for(int i=mx; i>-1; i--)
            {
                FOR(j, 1, 7)
                {
                    cnt[i+j] += cnt[i];
                    cout<<i+j<<" "<<cnt[i+j]<<endl;
                }

                cnt[i] = 0;
            }
        }
        ll upre = 0, nice = 0;
        mx = 6*n;
        for(int i=x; i<=mx; i++) upre += cnt[i];
        for(int i=1; i<x; i++) nice += cnt[i];
        nice += upre;

        ll g = __gcd(upre, nice);
        upre /= g;
        nice /= g;

        pf("Case %d: ", ++kaseno);
        if(nice == 1) pf("%lld\n", upre);
        else pf("%lld/%lld\n", upre, nice);



    }
return 0;
}
