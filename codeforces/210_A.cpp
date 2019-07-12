#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    int i,j,k;
    int n,m;
    cin>>n>>k;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                cout<<k;
                if(j!=n-1)
                    cout<<" ";
            }
            else
            {
                cout<<0;
                if(j!=n-1)
                    cout<<" ";
            }
        }

            cout<<endl;
    }


    return 0;
}
