#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long

using namespace std;


LL arr[3005];
int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    LL n;
    int m;
    cin>>n>>m;
    for(i=0; i<m; i++)
        cin>>arr[i];

    sort(arr,arr+m);

    if(arr[0]==1 || arr[m-1]==n)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    for(i=0; i<=m-2; i++)
    {
        if(((arr[i]+1)==arr[i+1]) && ((arr[i+1]+1)==arr[i+2]))
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
