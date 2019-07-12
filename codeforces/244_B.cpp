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

int arr[2*1000001];


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    LL n, m, t;
    vector<int>V;
    V.clear();

    cin>>n>>t>>m;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(arr[i]>t)
        {
            V.PB(i);
        }
    }
    int res=0;
    j=0;
    for(i=1; i<=n-m+1; i++)
    {
       // cout<<i<<" ";
        if(V.size() && (V[j]-i) <m)
        {
            i=V[j];
            j++;
        }
        else{
            res++;
            //cout<<i<<endl;
        }
    }
    cout<<res<<endl;




    return 0;
}

/*

4544545454

*/
