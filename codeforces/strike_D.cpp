#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

vector<int>V;
int res[3*100001];
int cnt[3*100001];
int sz;

int BS(int need)
{
    int low=0, high=sz-1, mid;

    while(low<high)
    {
        mid=(low + high)/2;
        if(V[mid]>=need)
            high=mid-1;
        else
            low=mid+1;
    }
    if(V[high]<need) return high+1;
    return high;
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    int n, m, p, u, v;

    cin>>n>>p;
    for(i=0; i<n; i++)
    {
        cin>>u>>v;
        cnt[u]++;
        cnt[v]++;
    }
    V.clear();
    for(i=1; i<=n; i++)
    {
        V.PB(cnt[i]);
    }

    sort(V.begin(), V.end());

    sz=V.size();
    memset(res, 0, sizeof res);
    int ans=0;
    V.PB(0);
    for(i=sz-1; i>=0; i--)
    {
        int curr=V[i];
        if(V[i]==V[i+1])
        {
            if(res[i+1])
                res[i]=res[i+1]-1;
            else
                res[i]=res[i-1];
            ans+=res[i];
            continue;
        }
        int need=p-curr;
        if(need<=0)
        {
            need=0;
        }
        int q;
        int tmp = BS(need);
        if(tmp<i)
            q=tmp;
        else
            q=i;
        res[i] = i - q;
        ans+=res[i];
      //  cout<<i<<" "<<tmp<<" "<<res[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

/*

5 3

4 5
4 5
4 5
3 2
2 3

*/
