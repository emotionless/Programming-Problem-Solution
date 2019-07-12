#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

struct Z
{
    int x,y,pop;
    double dis;
    bool operator<(const Z& A) const
    {
        if(dis==A.dis)
            return pop<A.pop;
        return dis<A.dis;
    }
};

vector<Z>V;

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;



    int n, m;

    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        Z tmp;
        cin>>tmp.x>>tmp.y>>tmp.pop;
        tmp.dis=sqrt(tmp.x*tmp.x + tmp.y* tmp.y);
        V.PB(tmp);
    }
    sort(V.begin(), V.end());
    int need=1000000-m;

    if(need<=0)
    {
        printf("%.8lf\n",0.0);
        return 0;
    }

    for(i=0; i<n; i++)
    {
       // cout<<V[i].x<<" "<<V[i].y<<" "<<V[i].pop<<" "<<V[i].dis<<endl;
        need=need-V[i].pop;
        if(need<=0)
        {
            printf("%.8lf\n", V[i].dis);
            return 0;
        }
    }
    cout<<-1<<endl;
    V.clear();



    return 0;
}

/*

4 999998
1 1 1
2 2 2
3 3 1
1 1 2

*/
