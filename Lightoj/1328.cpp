#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long
#define MOD  1000007



using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    LL i,j;
    LL n,K,C;
    int t, cases=0;
    scanf("%d", &t);
    while(t--)
    {
        LL arr[100005];
        LL sum[100005];
        scanf("%lld %lld %lld %lld", & K, &C, &n, &arr[0]);

        sum[0]=arr[0];
        for(i=1; i<n; i++)
        {
            arr[i]=((K*arr[i-1])%MOD+C)%MOD;
        }
        sort(arr, arr+n);


        for(i=1; i<n; i++)
        {
            sum[i]=sum[i-1]+arr[i];
        }

        LL res=0;
        for(i=0; i<n; i++)
        {
            LL temp=abs((sum[n-1]-sum[i])-(arr[i]*(n-i-1)));
            res+=temp;
        }
        printf("Case %d: %lld\n", ++cases, res);
    }
    return 0;
}
