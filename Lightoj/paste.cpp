#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;

vector<int>V[1000009], back[1000009];
LL num[1000009];

int main()
{
    //   FILE * fin, * fout, *fp;
    //     fp=fopen("out.txt", "w");

    int i,j;
    int a,b, u, v;
    int n,t, K;
    while(scanf("%d %d", &n, &K)==2)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &num[i]);
            V[num[i]].PB(i);
        }
        int res=100000000;

        for(int i=1; i<K; i++)
        {
            int cn=i;
            int baki=K-i;
            if(cn==baki) continue;

            int sz1=V[i].size();
            if(!sz1) continue;
            int pos1=V[i][0];
            int pos2=n-V[i][sz1-1]+1;
            int mn1=min(pos1, pos2);


            int sz2=V[baki].size();
            if(!sz2) continue;

            int pos3=V[baki][0];
            int pos4=n-V[baki][sz2-1]+1;
            int mx=max(min(pos3, pos4), mn1);
            res=min(res, mx);
        }
       // cout<<res<<endl;



        if(res==100000000)
            printf("-1\n");
        else
            printf("%d\n", res);
        for(i=1; i<=1000000; i++)
        {
            V[i].clear();
            back[i].clear();
        }
        memset(num, 0, sizeof num);
    }

    return 0;
}

/*

10 4
4 4 3 3 1 1 1 2 4 4


*/
