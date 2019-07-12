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

vector< pair<LL, LL> >V;


int main()
{
    int i, j, k;
    int n, m;
    LL a, b, d;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>a>>d;
        pair<LL,LL> P = make_pair(a, d);
        V.PB(P);

    }
    sort(V.begin(), V.end());
    d = 0;
    for(i = 0; i < n; i++)
    {
        if(V[i].second >= d) d = V[i].second;
        else d = V[i].first;
    }
    cout<<d<<endl;
    return 0;
}

/*

5
5 1
3 1
5 1
5 1
5 1


*/
