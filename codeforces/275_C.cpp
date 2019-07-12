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

bool vis[100009];


int main()
{
    int i, j, k;
    int n, m;
    LL a, b;
    cin>>n>>m;
    bool is = 1;
    int cur = 1;

        cout<<cur<<" ";
    while(m)
    {
        vis[cur] = 1;
        if(is){
            is = false;
            cur = cur + m;
        }
        else
        {
            is = true;
            cur = cur - m;
        }
        m--;
        cout<<cur<<" ";
        vis[cur] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            cout<<i<<" ";
    }















    return 0;
}

/*

4
4 3 3 3



*/
