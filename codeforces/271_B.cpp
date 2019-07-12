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
#define MOD 1000000007ll
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;

LL sum[100001];
int n;
int BS(LL num)
{
    LL st = 0, ed = n - 1, mid;
    int t = 0;
    int ans = 0;
    while(st <= ed)
    {
        mid = (st + ed) / 2;
        if(sum[mid] > num)
            ed = mid - 1;
        else{
            st = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    int i, j, k;
    int  m, w;
    string str;
    cin>>n;
    LL val[100001];
    LL tmp = 0;
    for(i = 0; i < n; i++)
    {
        cin>>val[i];
        sum[i] = tmp + 1;
        tmp += val[i];
        //cout<<sum[i]<<endl;
    }
    cin>>m;
    LL q;
    while(m--)
    {
        cin>>q;
        cout<<BS(q) + 1<<endl;
    }




    return 0;
}

/*

4
4 3 3 3



*/
