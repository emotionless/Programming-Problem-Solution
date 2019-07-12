/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b, cases=1;

    int t,n,m,u,v;
    cin>>t;

    vector<int>V[512];

    while(t--)
    {
        cin>>n>>m;


        int cnt[n+10];


        memset(cnt, 0, sizeof cnt);
        for(i=0; i<n+10; i++)
            V[i].clear();

        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
            V[v].PB(u);
        }
        int mx=0;
        for(i=0; i<=n; i++)
        {
            int sz=V[i].size();
            cnt[sz]++;
            mx=max(mx, sz);
        }
        printf("Case %d: ", cases++);
        if(mx>4)
            printf("NotValid\n");
        else if(mx==4)
        {
            if(cnt[4]==1 && cnt[3]==0 && cnt[1]==4)
                printf("X\n");
            else
                printf("NotValid\n");
        }
        else if(mx==3)
        {
            if(cnt[3]==1 && cnt[1]==3)
                printf("Y\n");
            else
                printf("NotValid\n");
        }
        else if(mx==2)
        {
            if(cnt[1]==2)
                printf("I\n");
            else
                printf("NotValid\n");
        }
        else
            printf("NotValid\n");
    }
    return 0;
}

/*

4 4

1 2

2 3

3 4

4 1

4 3

1 2

2 3

2 4


10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

10 9
4 1
4 2
4 3
4 5
1 6
6 7
7 8
8 9
2 1


*/
