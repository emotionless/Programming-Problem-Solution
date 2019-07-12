#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define all(a) (a.begin(), a.end())
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 1009
#define mp make_pair


using namespace std;



int main()
{

    int i, j, k;
    int t, cases = 1;
    int n, m;
    int p, q, r,  s;
    int a, b, c, d, e, ff, f, ss, tt, g, h;
    cin>>a>>b>>c;
    cin>>d>>e>>f;
    cin>>p>>q>>r;
    int ans = 100000000;
    for(i = 0; i <= 300; i++)
    {
        for(j = 0; j <= 300; j++)
        {
            for(k = 0; k <= 100; k++)
            {
                ff = a + i, ss = b + j;
                int ttt = c + k;
                int tt = ss - f;
                if(tt > 0)
                {
                    int step = d / tt + (d % tt?1:0);
                    int habe = ff - step * (e - ttt);
//                    if(i == 1 && j == 2 && k == 0)
//                        cout<<habe<<" "<<<<endl;
                    if(habe > 0)
                    {
                        ans = min(ans, i * p + j * q + k * r);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;





    return 0;
}

/*

1 1 100
100 1 100
1 1 1

*/
