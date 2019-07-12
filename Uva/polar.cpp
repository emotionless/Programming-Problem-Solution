#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

/**********TYPE CASTING**********/
#define LL long long
#define L long
#define D double
#define LD long double
#define S string
#define I int
#define ULL unsigned long long
#define q queue<int>
#define vi vector<int>
#define vl vector<long>

/**********INPUT**********/
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define s1(a) scanf("%d",&a)
#define s2(a,b) scanf("%d%d",&a,&b)
#define s3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sll(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",&a)
#define gc() getchar()

/**********OUTPUT**********/
#define p1(a) printf("%d\n",a)
#define p2(a,b) printf("%d %d\n",a,b)
#define pll(a) printf("%lld\n",a)
#define pd(a) printf("%.10lf\n",a)
#define pcs(a,n) printf("Case %d: %d\n",a,n)
#define nl() printf("\n")

/**********LOOP**********/
#define REV(i,e,s) for(i=e;i>=s;i--)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define loop(n) for(int o=1;o<=n;o++)

/********** min/max *******/
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))

/**********SHORTCUT**********/
#define len(a) a.length()
#define SET(a,x) memset(a,x,sizeof a)
#define VI vector<int>
#define PB push_back
#define SZ size()
#define CLR clear()
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))


/**********CONSTANT**********/
#define MIN INT_MIN
#define PI 2acos(-1.0)
#define INF 2<<15
#define MOD 1000000007
#define MAX 1000001



using namespace std;

int dr[]= {-1,-1,-1,0,1,1,1,0};
int dc[]= {-1,0,1,1,1,0,-1,-1};

int row, column;
bool mat[101][101];
bool temp[101][101];

void go(int x, int y)
{
    int cnt=0;
    for(int i=0; i<8; i++)
    {
        int ax=x+dr[i];
        int ay=y+dc[i];

        if(ax<0 || ax>=row)
        {
            ax=x;
            ay=(ay+column/2)%column;

        }
        if(ay<0)
        {
            ay=column-1;
        }
        if(ay>=column)
        {
            ay=ay%column;
        }
        if(mat[ax][ay]) cnt++;
        cout<<ax<<" "<<ay<<endl;
    }
    if(mat[x][y]==1)
    {
        if((8-cnt)<2 || (8-cnt)>3)
            temp[x][y]=0;
    }
    else if(cnt==3)
        temp[x][y]=1;
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k,K;
    int n,a,b;
    cin>>row>>column;
    cin>>K;
    for(i=0; i<K; i++)
    {
        cin>>a>>b;
        mat[a][b]=1;
    }
    I gen;
    cin>>gen;

    for(k=0; k<gen; k++)
    {
        clr(temp, 0);

        for(i=0; i<row; i++)
        {
            for(j=0; j<column; j++)
            {
                go(i,j);
                return 0;
            }
        }
        for(i=0; i<row; i++)
        {
            for(j=0; j<column; j++)
            {
                mat[i][j]=temp[i][j];
            }
        }
    }
    int fx=-1, fy=-1;
    int lx=-1, ly=-1;
    bool f=true;
    int res=0;

    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(mat[i][j])
            {
                if(f)
                {
                    fx=i;
                    fy=j;
                    f=false;
                }
                else
                {
                    lx=i;
                    ly=j;
                }
                res++;
            }
        }
    }
    cout<<res<<" "<<fx<<" "<<fy<<" "<<lx<<" "<<ly<<endl;

    return 0;
}
