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

struct Z
{
    int a,b,c;
    Z() {}
    Z(int p, int q, int r)
    {
        a=p;
        b=q;
        c=r;
    }
};


struct ret
{
    int a,b,c;
};

string mat[501];
int n,m;

int dr[]= {0,-1, 0, 1};
int dc[]= {-1, 0, 1,0};

bool vis[501][501];
int costt[501][501];

ret grid(int x, int y)
{
    queue<Z>Q;

    Z tmp;
    tmp.a=x;
    tmp.b=y;
    tmp.c=0;

    memset(vis, false, sizeof vis);

    Q.push(tmp);
    int mx=0;
    ret retu;

    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();

        int cx=tmp.a;
        int cy=tmp.b;
        int cz=tmp.c;

        if(vis[cx][cy]) continue;
        if(cz>mx)
        {
            mx=cz;
            retu.a=cx;
            retu.b=cy;
            retu.c=cz;
            //cout<<cx<<" "<<cy<<" "<<cz<<endl;
        }

        vis[cx][cy]=true;

        costt[cx][cy]=cz;

        //  cout<<cx<<" "<<cy<<" "endl;

        for(int i=0; i<4; i++)
        {
            int adjx=cx+dr[i];
            int adjy=cy+dc[i];
            if(adjx<0 || adjx>=n || adjy<0 || adjy>=m) continue;
            if(mat[adjx][adjy]=='.' && vis[adjx][adjy]==false)
            {
                Z tm;
                tm.a=adjx;
                tm.b=adjy;
                tm.c=cz+1;
                Q.push(tm);
            }
        }
    }


    return retu;
}

bool visited[501][501];

struct node
{
    int x,y;
    int c;
    node(){}
    bool operator<(const node &A) const
    {
        return A.c<c;
    }
};

vector<node>V;

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j, K;
    cin>>n>>m>>K;

    for(i=0; i<n; i++)
        cin>>mat[i];
    ret last;
    bool ck=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]=='.')
            {
                last=grid(i,j);
                ck=1;
                break;
            }
        }
        if(ck) break;
    }

    int cx=last.a;
    int cy=last.b;
    int cz=last.c;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]=='.')
            {
                node A;
                A.x=i;
                A.y=j;
                A.c=costt[i][j];
                V.push_back(A);
            }
        }
    }
    sort(V.begin(), V.end());

    for(int i=0; i<V.size(); i++)
    {
        node A=V[i];
        int cx=A.x;
        int cy=A.y;
        int cc=A.c;
        if(K==0) break;
        mat[cx][cy]='X';
        K--;
    }

    for(i=0; i<n; i++)
    cout<<mat[i]<<endl;


    return 0;
}

/*

3 4 2
#..#
..#.
#...

*/
