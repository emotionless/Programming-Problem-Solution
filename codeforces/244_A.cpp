#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

bool vis[100001];
int arr[100001];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    int n, m;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(i=0; i<n; i++)
    {
        if(arr[i]>-1)
            sum+=arr[i];
        else
        {
            if(sum>0)
            {
                vis[i]=true;
                sum--;
            }
        }
    }
    int cnt=0;
    for(i=0; i<n; i++)
        if(!vis[i] && arr[i]==-1)
            cnt++;
    cout<<cnt<<endl;



    return 0;
}

/*

4544545454

*/
