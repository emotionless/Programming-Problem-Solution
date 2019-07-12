#include <bits/stdc++.h>

#define LL long long
#define MX 2009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define ll long long
#define MOD  1000000007ll
#define check(aa , bb) (aa & (1<<bb))
#define PB push_back

#define PI 3.14159265358979323846264338328

using namespace std;



int main()
{
    LL a, b;
    cin>>a>>b;

    for(LL i = a; i <= b; i++)
    {
        for(LL j = i + 2; j <= b; j+=2)
        {
            for(LL k = i + 1; k < j; k++)
            {
                if(__gcd(i, k) == 1ll && __gcd(j, k) == 1ll && __gcd(i, j) >= 2ll)
                {
                    vector<LL>V;
                    V.clear();
                    V.PB(i);
                    V.PB(k);
                    V.PB(j);
                    sort(V.begin(), V.end());
                    for(i = 0; i < 3; i++)
                        cout<<V[i]<<" ";
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;













    return 0;
}

/*

4
4 3 3 3



*/
