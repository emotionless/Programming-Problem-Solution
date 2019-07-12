#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;
LL arr[6][6];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n, m, u,v;
    for(i=1; i<=5; i++)
        for(j=1; j<=5; j++)
            cin>>arr[i][j];

    string str = "12345";
    LL res=0;
    do
    {
        int a=str[0]-'1'+1;
        int b=str[1]-'1'+1;
        int c=str[2]-'1'+1;
        int d=str[3]-'1'+1;
        int e=str[4]-'1'+1;

        LL tot = arr[a][b] + arr[b][a] + arr[c][d] + arr[d][c] + arr[b][c] + arr[c][b] + arr[d][e]+ arr[e][d] + arr[c][d] + arr[d][c] + arr[d][e]+ arr[e][d];
        res=max(res, tot);

    }
    while ( next_permutation(str.begin(),str.end()) );
    cout<<res<<endl;


    return 0;
}

/*

15
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
11 10
12 11
13 12
14 13
15 14
0 1 0 0 1 1 1 1 1 1 0 0 0 1 1
1 1 1 1 0 0 1 1 0 1 0 0 1 1 0


*/
