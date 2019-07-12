#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    int i,j,k;
    int n,m;
    cin>>n>>k;

    if(n-k<=0)
        cout<<-1<<endl;
    else if((n-k)==1)
    {
        cout<<1;
        for(i=2; i<=n; i++)
            cout<<" "<<i;
    }
    else
    {
        for(i=1; i<n-k; i++)
        {
            if(i==1)
                cout<<i+1;
            else
                cout<<" "<<i+1;
        }
        cout<<" "<<1;
        for(i=n-k+1; i<=n; i++)
            cout<<" "<<i;
    }

    return 0;
}
