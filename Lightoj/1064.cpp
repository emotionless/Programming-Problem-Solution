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

LL cnt[26*6];



int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, x;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>x;
        memset(cnt, 0, sizeof cnt);
        cnt[0] = 1;
        for(i = 0; i < n; i++)
        {
            int mx = i * 6;
          //  cout<<"when: "<<i<<endl;
            for(j = mx; j >= 0; j--)
            {
                for(k = 1; k <= 6; k++)
                {
                    cnt[j + k] += cnt[j];
                }
                cnt[j] = 0;
            }
        }
        LL up = 0, down = 0;
        printf("Case %d: ", cases++);
        if(x > n*6)
        {
            printf("0\n");
            continue;
        }
        for(i = x; i <= 6*n; i++)
            up += cnt[i];
        for(j = 1; j < x; j++)
            down += cnt[j];
        down += up;
        LL comm = __gcd(up, down);
       // cout<<up<<" "<<down<<" "<<comm<<endl;
        if(comm == down)
            printf("%lld\n", up / comm);
        else
            printf("%lld/%lld\n", up/comm, down/comm);
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
