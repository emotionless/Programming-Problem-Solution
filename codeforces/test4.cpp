#include <bits/stdc++.h>
#define ll long long


using namespace std;


ll arr[100009];

int main()
{
    freopen("inp4.txt", "r", stdin);
    freopen("out4Normal.txt", "w", stdout);
    int n;
    int i, j, k, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum = 0ll;
        for(i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum = sum ^ arr[i];
        }
        ll ans = sum;
        for(i = 0; i < n; i++)
        {
            ll temp = 0ll;
            for(j = i; j < n; j++)
            {
                temp = temp^arr[j];
                ans = max(ans, temp^sum);
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}

