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
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;

struct Z
{
    int u, v, w;
    Z() {}
    Z(int _, int __, int ___)
    {
        u = _;
        v = __;
        w = ___;
    }

    bool operator <(const Z& A) const
    {
        return w < A.w;
    }

} ;

int arr[6];


bool vis[10];

int main()
{
    int i, j, k;
    int n, m, w;
    int t, u, v;
    for(i = 0; i < 6; i++)
        cin>>arr[i];
    sort(arr,arr + 6);

    for(i = 0; i < 6; i++)
    {
        int cn = arr[i];
        int cnt = 0;
        for(j = 0; j < 6; j++)
        {
            if(arr[i] == arr[j])
                cnt++;
        }
        if(cnt >= 4)
        {
            cnt = 4;
            int tot = 0;
            for(j = 0; j < 6 && tot < cnt; j++)
            {
                if(arr[j] == cn)
                {
                    vis[j] = true;
                    tot++;
                }
            }

            for(j = 0; j < 6; j++)
            {
                if(vis[j]) continue;
                else
                {
                    for(k = j + 1; k < 6; k++)
                    {
                        if(vis[k]) continue;
                        if(arr[j] < arr[k])
                            cout<<"Bear"<<endl;
                        else if(arr[j] == arr[k])
                            cout<<"Elephant"<<endl;
                        else
                            cout<<"Alien"<<endl;
                        return 0;
                    }
                }
            }

        }
    }
    cout<<"Alien"<<endl;

    return 0;
}

/*





*/
