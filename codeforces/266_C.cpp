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

LL arr[1000000];
LL sum[1000000];

int main()
{

    int i, j, k;
    int n, x, y;
    LL tot = 0;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
        tot += arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    if(tot % 3)
    {
        cout<<0<<endl;
        return 0;
    }
    LL s = 0;
    int fst = -1, snd = -1;
    for(i = 0; i < n; i++)
    {
        s += arr[i];

        if(s == (tot / 3))
        {
            fst = i + 1;
            break;
        }
    }
    s = 0;
    for(j = n - 1; j >= 0; j--)
    {
        s += arr[j];
        if(s == (tot / 3))
        {
            snd = j - 1;
            break;
        }
    }
    if(fst == -1 || snd == -1)
    {
        cout<<0<<endl;
        return 0;
    }
    s = 0;
    int mid = -1, ed = -1;
    for(i = fst; i <= snd; i++)
    {
        s += arr[i];
        if(s == tot / 3)
        {
            LL add = 0;
            for(j = i; j >= fst; j--)
            {
                add += arr[j];
                if(add == s)
                {
                    mid = j - 1;
                    ed = i + 1;
                    break;
                }
            }
            break;
        }
    }
    if(mid == -1 || ed == -1)
    {
        cout<<0<<endl;
        return 0;
    }
    s = 0;
    int cnt1 = 1, cnt2 = 1;
    for(i = fst; i <= mid; i++)
    {
        s += arr[i];
        if(s == 0)
            cnt1++;
    }
    s = 0;
    for(i = ed; i <= snd; i++)
    {
        s += arr[i];
        if(s == 0)
            cnt2++;
    }
    cout<<(cnt1 * cnt2)<<endl;

    return 0;
}

/*


4 4
4 4 4 4



*/
