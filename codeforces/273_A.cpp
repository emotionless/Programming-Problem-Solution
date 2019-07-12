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

#define PI 3.14159265358979323846264338328

using namespace std;



int main()
{
    int i, j, k;
    int n, m;
    n = 0;
    m = 0;
    for(i = 0; i < 5; i++)
    {
        cin>>n;
        m+=n;
    }
    if(m%5 || m == 0)
        cout<<-1<<endl;
    else
        cout<<m/5<<endl;











    return 0;
}

/*

4
4 3 3 3



*/
