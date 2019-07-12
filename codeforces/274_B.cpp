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

LL arr[100009];

LL a, b, x, y;
LL l;
bool valid(LL n)
{
    if(n < 0 || n > l) return false;
    return true;
}

int main()
{
    int i, j, k;
    int n;
    cin>>n>>l>>x>>y;
    for(i = 0; i < n; i++)
        cin>>arr[i];
    map<LL, bool>M;
    bool f = false, s = false;
    for(i = 0; i < n; i++)
    {
        LL dis = arr[i] - x;
        if(M[dis])
        {
            f = true;
        }
        dis = arr[i] - y;
        if(M[dis])
        {
            s = true;
        }
        M[arr[i]] = true;
    }
    if(f && s)
    {
        cout<<0<<endl;
        return 0;
    }
    if(f == 0 && s == 0)
    {
        for(i = 0; i < n; i++)
        {
            LL sum = arr[i] + x;
            if(sum >= 0 && sum <= l)
            {
                LL les = sum - y;
                if(valid(les) && M[les])
                {
                    cout<<1<<endl;
                    cout<<sum<<endl;
                    return 0;
                }
                LL big = sum + y;
                if(valid(big) && M[big])
                {
                    cout<<1<<endl;
                    cout<<sum<<endl;
                    return 0;
                }

            }
            sum = arr[i] + y;
            if(sum >= 0 && sum <= l)
            {
                LL les = sum - x;
                if(valid(les) && M[les])
                {
                    cout<<1<<endl;
                    cout<<sum<<endl;
                    return 0;
                }
                LL big = sum + x;
                if(valid(big) && M[big])
                {
                    cout<<1<<endl;
                    cout<<sum<<endl;
                    return 0;
                }
            }

            LL dif = arr[i] - x;
            if(valid(dif))
            {
                LL add = dif + y;
                if(valid(add) && M[add])
                {
                    cout<<1<<endl;
                    cout<<dif<<endl;
                    return 0;
                }
            }
        }

        cout<<2<<endl;
        cout<<x<<" "<<y<<endl;
        return 0;
    }
    if(f == 0)
    {
        cout<<1<<endl;
        cout<<x<<endl;
        return 0;
    }
    cout<<1<<endl;
    cout<<y<<endl;



    return 0;
}

/*

4 100 3 5
0 4 6 100

3 250 185 230
0 230 250

3 9 3 5
0 1 9


3 10 2 3
0 9 10



3 100 2 4
0 2 8
*/
