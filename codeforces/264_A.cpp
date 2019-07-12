#include <bits/stdc++.h>

#define LL long long
#define MX 70
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


using namespace std;


int main()
{

    int i, j, c, d, n, s;
    cin>>n>>s;
    int cnt = 0;
    int mx = -1;
    for(i = 0; i < n; i++)
    {
        cin>>d>>c;
        int tot = s * 100;
        int have = d * 100 + c;
        if(have > tot)
        {
            cnt++;
            continue;
        }
        int rest = tot - have;
        rest = rest % 100;
        mx = max(mx, rest);
    }
    cout<<mx<<endl;

    return 0;
}

/*

1
1 3
XL S
XL L
XL L



*/
