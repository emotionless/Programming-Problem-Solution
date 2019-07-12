#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 50009
#define mp make_pair

using namespace std;




int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    vector<int>V;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
    {
        cin>>t;
        V.PB(t);
    }
    int ans = 0;
    for(j = 1; j <= 110; j++)
        for(i = 0; i < n; i++)
        {
            if(V[i] > 0)
            {
                V[i] = V[i] - m;
                ans = i + 1;
            }

        }
    cout<<ans<<endl;



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
