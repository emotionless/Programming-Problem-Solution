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
#define MX 100009
#define mp make_pair

using namespace std;

int arr[101];
int val[101];
int par[101];
int s[101];
bool vis[101];

void DFS(int src)
{
    vis[src] = true;

    if(par[src] == -1) return;
    DFS(par[src]);
}

int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n;
        for(i = 0; i < n; i++)
            cin>>arr[i];
        clr(val, 0);
        clr(par, -1);

        // count the longest non-decreasing sub-sequence including 'i'

        for(i = 0; i < n; i++)
        {
            for(j = i - 1; j >= 0; j--)
            {
                if(val[i] <= val[j] && arr[j] <= arr[i])
                {
                    val[i] = val[j] + 1;
                    par[i] = j;
                }
            }
        }
        int mx = 0;

        // count the longest non-decreasing sub-sequence including 'i' from 'i' to 0.
        for(i = 0; i < n; i++)
        {
            int num = arr[i];
            int cv = val[i] + 1;
            memset(vis, false, sizeof vis);
            DFS(i);

            s[0] = i;
            int ind = 0;
            //cout<<"\nFor "<<i<<endl;
            for(j = i - 1; j >= 0; j--)
            {
                if(vis[j]) continue;
                if(arr[j] < arr[i]) continue;
                int cn = arr[j];
                if(cn >= arr[s[ind]])
                {
                    s[++ind] = j;
                 //   cout<<arr[j]<<" ";
                }
                else
                {
                    int pos = 0;
                    int k;
                    for(k = ind; k >= 0; k--)
                    {
                        if(arr[s[k]] > cn)
                            pos = k;
                    }
                    s[pos] = j;
                }

            }
            //cout<<i<<" "<<cv<<" "<<ind<<endl;
            cv += ind;
            mx = max(mx, cv);
        }
        printf("Case %d: %d\n", cases++, mx);
    }

    return 0;
}

/*

1
6
4 23 12 33 1 3

*/
