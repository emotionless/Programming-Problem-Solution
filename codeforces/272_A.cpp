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
#define MOD  1000000007
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;



int main()
{
    int i, j, k;
    int n;
    int a, b;
    cin>>a>>b;
    LL sum = 0;
    for(i = 1; i <= 20000000; i++)
    {
        if(i % b == 0) continue;
        int div = i / b;
        int md = i % b;
        if(div % md == 0 && div / md <= a && div / md > 0){
            sum = (sum + i) % MOD;
            //cout<<i<<endl;
        }
    }
    cout<<sum<<endl;







    return 0;
}

/*

4
4 3 3 3



*/
