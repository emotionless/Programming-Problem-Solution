#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;


int arr[1000+5], A[1000+5][1000+5], B[1000+5][1000+5];
struct Z
{
    int pos, val;
    Z() {}
    Z(int a, int b)
    {
        pos=a;
        val=b;
    }
    bool operator<(const Z& AA) const
    {
        if(AA.val==val)
        {
            return A[AA.pos][arr[AA.pos]-1]<A[pos][arr[pos]-1];
        }
        return AA.val>val;
    }
};

int main()
{
    //   FILE * fin, * fout, *fp;
    //     fp=fopen("out.txt", "w");

    int i,j,k;
    int a,b, u, v, K,n,m;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m>>K;


        for(i=0; i<n; i++)
            cin>>arr[i];

        for(int i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>A[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>B[i][j];
            }
        }
        vector<Z>V;
        for(int i=0; i<n; i++)
        {
            int mx=0;
            for(j=0; j<m; j++)
            {
                mx=max(mx,A[i][j]-B[i][j]);
            }
            V.PB(Z(i,mx));
        }

        sort(V.begin(), V.end());

        reverse(V.begin(), V.end());

        for(int i=0; i<n; i++)
        cout<<i<<" "<<V[i].pos<<" "<<V[i].val<<endl;

        int sum=0;
        bool vis[1009];
        memset(vis, false, sizeof vis);

        for(int i=0; i<n; i++)
        {
            if(K)
            {
                sum+=V[i].val;
                K--;
                vis[V[i].pos]=true;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) sum+=A[i][arr[i]-1];
        }
        cout<<sum<<endl;
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        memset(arr, 0, sizeof arr);
        V.clear();
    }






    return 0;
}

/*

2 2 1
1 1
2 6
5 6
0 1
0 1

4 2 1
1 1 2 2
1 1
1 1
1 1
3 1
0 1
0 1
1 0
1 0


10 4 4
1 2 3 4 1 1 1 2 3 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
0 1 1 1
0 1 1 1
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

4 4 0
1 1 3 4
1 1 2 2
1 3 1 1
1 4 1 1
1 1 1 1
0 1 1 1
0 1 1 1
1 1 0 1
1 1 1 0


*/
