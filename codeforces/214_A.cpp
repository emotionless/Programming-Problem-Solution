#include<bits/stdc++.h>
#define LL long long
#define PB push_back


using namespace std;
int a,b,c,d;
int main()
{
    int i,j,k;
    int n;
    cin>>n;
    bool p=false;
    for(i=0; i<4; i++)
    {
        cin>>a>>b>>c>>d;

        if(!p)
        {
            int s=min(a,b)+min(c,d);
            if(s<=n)
            {
                cout<<i+1<<" "<<min(a,b)<<" "<<(n-min(a,b))<<endl;;
                p=true;
            }
        }

    }

    if(!p)
    cout<<-1<<endl;

    return 0;
}
