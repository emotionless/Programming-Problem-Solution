#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long

using namespace std;

int r[]= {-2, -2, 2, 2};
int c[]= {-2, 2, 2, -2};

struct Z
{
    int x,y;
    Z() {}
    Z(int a, int b)
    {
        x=a;
        y=b;
    }
};


string mat[10];

bool vis1[10][10];
bool vis2[10][10];

void solve1(int x, int y)
{
    queue<Z>Q;
    Q.push(Z(x,y));

    while(!Q.empty())
    {
        Z top=Q.front();
        Q.pop();
        int cx=top.x;
        int cy=top.y;

        if(vis1[cx][cy]) continue;

        vis1[cx][cy]=true;

        for(int i=0; i<4; i++)
        {
            int adjx=r[i]+cx;
            int adjy=c[i]+cy;

            if(adjx>=0 && adjx<8 && adjy>=0 && adjy<8)
            {
                Q.push(Z(adjx, adjy));

            }
        }
    }
}

void solve2(int x, int y)
{
    queue<Z>Q2;
    Q2.push(Z(x,y));

    while(!Q2.empty())
    {
        Z top=Q2.front();
        Q2.pop();
        int cx=top.x;
        int cy=top.y;

        if(vis2[cx][cy]) continue;

        vis2[cx][cy]=true;

        for(int i=0; i<4; i++)
        {
            int adjx=r[i]+cx;
            int adjy=c[i]+cy;

            if(adjx>=0 && adjx<8 && adjy>=0 && adjy<8)
            {
                Q2.push(Z(adjx, adjy));
            }

        }
    }

}




int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,c1,c2,d1,d2;

    cin>>n;
    while(n--)
    {
        for(i=0; i<8; i++)
            cin>>mat[i];

        bool f=true;
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(mat[i][j]=='K')
                {
                    if(f)
                    {
                        solve1(i,j);
                        f=false;
                        c1=i;
                        c2=j;
                    }
                    else
                    {
                        solve2(i,j);
                        d1=i;
                        d2=j;
                    }
                }

            }
        }

        bool c=false;

        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(vis1[i][j]==true && vis2[i][j]==true && mat[i][j]!='#' && abs(c1-d1)%4==0 && abs(c2-d2)%4==0)
                {
                    c=true;
                }
            }
        }
        if(c==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                vis1[i][j]=false;
                vis2[i][j]=false;
            }
        }
    }
    return 0;
}

/*

########
########
###K####
########
#####K##
########
########
########

1
...#...#
........
.#...K..
........
...#...#
........
.K...#..
........


........
.K......
..#.....
...#....
....#...
.....#..
......#.
.......K



*/
