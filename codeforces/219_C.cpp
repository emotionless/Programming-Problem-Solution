/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 100009
#define PB push_back


using namespace std;

int arr[5*N];
bool vis[5*N];
int cnt[5*N];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    int t;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);

    memset(vis, false, sizeof vis);
    int last=0;

    last=0;
    for(i=0; i<n/2; i++)
    {
        // cout<<i<<" "<<cnt[i]<<endl;
        last=max(last,n/2);
        for(j=last; j<n; j++)
        {
            if(arr[j]*2<=arr[i])
            {
                cnt[j]++;
                last=j;
                break;
            }
        }
        if(j==n)
            last=n;
    }
    int lst=0;
    for(i=n/2; i<n; i++)
    {
        if(cnt[i])
        {
            t=cnt[i];
            lst=max(lst, i);
            while(t>0 && lst<n)
            {
                vis[lst]=true;
                lst++;
                t--;
            }
        }
    }
    int res=0;
    for(i=0; i<n; i++)
        if(vis[i])
            res++;
    cout<<n-res<<endl;


    return 0;
}

/*



*/
