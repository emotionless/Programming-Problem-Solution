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

LL arr[5];

int main()
{
    int i, j, k;
    LL n, m, a;
    LL sum = 0;
    for(i = 0; i < 3; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    LL avg = sum / 3;
    sort(arr, arr + 3);
    LL ans = min(avg, arr[0] + arr[1]);
    cout<<ans<<endl;
        cout<<((-5)%3)<<endl;















    return 0;
}

/*

2



*/
