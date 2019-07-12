#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;

int arr[55];

int solve(int st, int ed)
{
    int mn=10000000;
    for(int i=st; i<=ed; i++)
    {
        mn=min(mn, arr[i]);
    }
    return mn;
}

int main()
{
    //   FILE * fin, * fout, *fp;
    //     fp=fopen("out.txt", "w");

    int i,j,k;
    int a,b, u, v,n, num;

    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &num);
        arr[i]=num;
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &num);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(j=i; j<n; j++)
            {
                int mn=solve(i,j);
                if(mn==num)
                    cnt++;
            }
         //   cout<<i<<" "<<cnt<<endl;
        }
        cout<<cnt<<endl;
    }

    return 0;
}

/*
8 7
1 0 0 0 1 0 1 0
1 2
2 3
3 4
4 5
3 6
6 7
4 8


*/
