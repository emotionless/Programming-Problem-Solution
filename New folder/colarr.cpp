#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;

struct Z
{
    int pos, val;
    Z() {}
    Z(int a, int b)
    {
        pos=a;
        val=b;
    }
    bool operator<(const Z& A) const
    {
        return A.val>val;
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

        int arr[n+5], A[n+5][m+5], B[n+5][m+5];

        for(i=1; i<=n; i++)
            cin>>arr[i];
        cout<<"Now\n";

        for(int i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                cin>>A[i][j];
            }
        }
        cout<<"Now\n";
        for(int i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                cin>>B[i][j];
            }
        }
        vector<Z>V;
        for(int i=1; i<=n; i++)
        {
            int mx=A[i][arr[i]];
            for(j=1; j<=m; j++)
            {
                mx=max(mx,A[i][j]-B[i][j]);
            }
            V.PB(Z(i,mx));
        }

        sort(V.begin(), V.end());

        reverse(V.begin(), V.end());

        int sum=0;

        for(int i=1; i<=n; i++)
        {
            if(K)
            {
                sum+=V[i].val;
                K--;
            }
            else
            {
                int pos=V[i].pos;
                sum+=A[pos][arr[pos]];
            }
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

10 4 10
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
*/
