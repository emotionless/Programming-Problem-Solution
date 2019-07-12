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


using namespace std;

LL n, K;

LL check(LL v)
{
    LL ret = 0;

    for(int i = 0; i <= 32; i++)
    {
        ret += v/round(pow((double)K, (double)i));
    }
    //cout<<ret<<endl;
return ret;
}


int main()
{

    int i, j;
    //int n;

    cin>>n>>K;
    LL st = 0, ed = n;
    LL mid, ans;

    while(st <= ed)
    {
        mid = (st + ed) / 2;
       // cout<<st<<" "<<ed<<" "<<mid<<endl;
        if(check(mid) >= n)
        {
            ans = mid;
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }
    cout<<ans<<endl;





    return 0;
}

/*

1
1 3
XL S
XL L
XL L



*/
