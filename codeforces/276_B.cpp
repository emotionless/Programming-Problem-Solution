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
int arr[MX];


bool possible(int val)
{

}



int BS()
{
    int st = 0, ed = 10000009, mid;
    int ans = 0;

    while(st <= ed)
    {
        mid = (st + ed)/2;
        if(possible(mid))
        {
            ans = max(ans, mid);
            st = mid + 1;
        }
        else
            ed = mid - 1;
    }

return ans;

}


int main()
{
    int i, j, k;
    int n, m;
    LL a, b;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr, arr + n);

    int res = BS();














    return 0;
}

/*

4
4 3 3 3



*/
