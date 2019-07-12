#include<bits/stdc++.h>

#define LL long long

using namespace std;


int main()
{
    LL t, cases = 1, i;
    LL n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        LL res = 0ll;
        for(i = 0; i < 32; i++)
        {
            if(!(n&(1ll<<i)))
            {
//                cout<<(1<<i)<<endl;
                res = res|(1ll<<i);
//                cout<<res<<endl;
            }
        }
        cout<<res<<endl;
    }





    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
