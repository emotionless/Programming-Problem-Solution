#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

LL arr[1000001];
LL res[1000001];
LL til[1000001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    int n;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>arr[i];
    til[0]=0;
    for(i=1; i<=n; i++)
    {
        til[i]=til[i-1]^i;
    }
    LL ans=0;
    for(i=1; i<=n; i++)
    {
        LL tot=n/i;
        if(tot%2)
        {
            res[i]=til[i-1]^(til[n%i]);
        }
        else
            res[i]=til[n%i];
        ans=ans^res[i]^arr[i];
    }
    cout<<ans<<endl;






    return 0;
}

/*

4544545454

*/
