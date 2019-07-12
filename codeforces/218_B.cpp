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
#define PB push_back


using namespace std;

struct Z
{
    LL num;
    int cost;

    Z() {}
    Z(LL a, int b)
    {
        num=a;
        cost=b;
    }
};

map<LL, int>M;
int cost[100001];
int vis[100001];
int vis1[100001];
int k;
void BFS(LL n)
{
    queue<Z>Q;
    Q.push(Z(n,0));

    M[n]=1;
    cost[M[n]]=0;

    k=2;

    while(!Q.empty())
    {
        Z tmp=Q.front();
        Q.pop();
        LL cn=tmp.num;
        int cc=tmp.cost;

        if(!M[cn]) M[cn]=k++;

        if(vis[M[cn]]) continue;

        cost[M[cn]]=cc;

        vis[M[cn]]=true;

        if(cn%2==0)
            Q.push(Z(cn/2, cc+1));

        if(cn%3==0)
            Q.push(Z(cn-(cn*2)/3, cc+1));

        if(cn%5==0)
            Q.push(Z(cn-(cn*4)/5, cc+1));
    }
}

int BFS1(LL n)
{
    queue<Z>Q;
    Q.push(Z(n,0));

    map<LL,int>MP;

    while(!Q.empty())
    {
        Z tmp=Q.front();
        Q.pop();
        LL cn=tmp.num;
        LL cc=tmp.cost;

        if(M[cn])
        {
            return cc+cost[M[cn]];
        }

        MP[cn]=k++;

        if(vis1[MP[cn]]) continue;

        vis1[MP[cn]]=true;

        if(cn%2==0)
            Q.push(Z(cn/2, cc+1));

        if(cn%3==0)
            Q.push(Z(cn-(cn*2)/3, cc+1));

        if(cn%5==0)
            Q.push(Z(cn-(cn*4)/5, cc+1));

    }
    return -1;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    LL a,b;
    cin>>a>>b;
    LL mx=max(a,b);
    LL mn=min(a,b);
    if(mx==mn)
    {
        cout<<0<<endl;
        return 0;
    }

    BFS(mx);

    int res=BFS1(mn);

    cout<<res<<endl;

        return 0;
}

/*

5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2

*/
