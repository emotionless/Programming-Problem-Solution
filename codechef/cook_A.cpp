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
#define MAX 1562501
#define MOD 1000000007
#define N 1000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))


using namespace std;

LL C[100][50];

void init()
{
    int i,j;
    C[0][0]=1;
    for(i=1; i<=99; i++)
    {
        for(j=1; j<=i && j<=49; j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}

vector<int>res;

LL tar, a, b;
void solve(int c, LL curr, vector<int>vec)
{
    int i,j,k;
    int sz=vec.size();
    LL sum=0;
    for(i=0; i<sz; i++)
    {
        sum+=vec[i];
    }
    if(sum==tar)
    {
        res=vec;

    }
    if(c==0 || res.size()) return;
    vector<int>tmp;
    for(i=100; i>0; i--)
    {
        if(C[i][c]>curr || sum+C[i][c]>tar) continue;

        tmp=vec;
        tmp.PB(C[i][c]);
        solve(c-1, C[i][c], tmp);
        break;
    }
}





int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n,p;
    init();
    cin>>t;
    while(t--)
    {
        res.clear();
        int a,b;
        cin>>a>>b>>tar;
        vector<int>tmp;
        solve(b, 10000000000000, tmp);
        cout<<res.size()<<endl;
        for(i=0; i<res.size(); i++)
        {
            if(i) cout<<" ";
            cout<<res[i];
        }
        cout<<endl;

    }


    return 0;
}

/*

1
10 4 2
7 8
9 10
1 3
4 6
9 3
4 8


*/
