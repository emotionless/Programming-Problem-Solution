#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

LL num[MX];
LL low[MX];
LL high[MX];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b, h, m, n;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>num[i];
    }
    low[1] = 1;
    for(i = 2; i <= n; i++)
    {
        if(num[i] > num[ i - 1])
            low[i] = low[i - 1] + 1;
        else
            low[i] = 1;
    }

    high[n] = 1;
    for(i = n-1; i >= 1; i--)
    {
        if(num[i] < num[ i + 1])
            high[i] = high[i + 1] + 1;
        else
            high[i] = 1;
    }
    num[0] = -1;
    num[n + 1] = 1000000009;
    LL mx = 0;
    for(i = 1; i <= n; i++)
    {
            int tmp = num[i - 1] + 1;
            LL sum = low[i - 1] + 1;
            if(tmp < num[i + 1])
                sum = sum + high[i + 1];
            mx = max(mx, sum);
          //  mx = max(mx, high[i + 1] + 1);
           // cout<<i<<" "<<low[i]<<" "<<high[i + 1]<<endl;

    }
    cout<<mx<<endl;






    return 0;
}

/*


6
1 5 4 3 4 5



*/
