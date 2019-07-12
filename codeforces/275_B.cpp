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
LL x, y, cnt1, cnt2;
LL lcm;
LL BS()
{
    LL st = 0ll, ed = 10000000000ll, mid;
    LL ans = 10000000000ll;
    //cout<<cnt2<<endl;
    while(st <= ed)
    {
        mid = (st + ed)/2;
        LL a = mid / x;
        LL b = mid / y;
        LL c = mid / lcm;
        LL tmp = mid - a - b + c + (a - c) + (b - c);
      //  cout<<mid<<" "<<a<<" "<<b<<" "<<c<<" "<<tmp<<endl;
        if(tmp >= (cnt1 + cnt2) && (mid - a - b + c + (b - c)) >= cnt1 && (mid - a - b + c + (a - c)) >= cnt2)
        {
            ans = min(ans, mid);
            //cout<<ans<<endl;
            ed = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
return ans;
}


int main()
{
    cin>>cnt1>>cnt2;
    cin>>x>>y;
    lcm = (x * y)/__gcd(x, y);
    LL ans = BS();
    cout<<ans<<endl;














    return 0;
}

/*

4
4 3 3 3



*/
