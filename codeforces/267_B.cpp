#include <bits/stdc++.h>

#define LL long long
#define MX 100009
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
#define MOD 1000000007ll
#define M 100000
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;

LL arr[1009];

int main()
{
    int N,i;

    int n;
    int m, K;
    LL me;
    cin>>n>>m>>K;
    for(i = 0; i < m;  i++)
        cin>>arr[i];
    cin>>me;

    int cnt = 0;
    int res = 0;
    for(i = 0; i < m; i++)
    {
        cnt = 0;
        for(int j= 0; j <=20 && j < n; j++)
        {
            if(check(arr[i], j) != check(me, j))
                cnt++;
        }
        if(cnt <= K)
            res++;
    }
    cout<<res<<endl;

    return 0;
}

/*





*/
