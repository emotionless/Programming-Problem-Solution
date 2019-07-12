#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

LL digit(LL x)
{
    int sum = 0;
    while(x)
    {
        sum += x%10;
        x = x / 10;
    }
return sum;
}
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int t;
    int x1, x2, y1, y2;

    LL n, m, c, b, a;
    cin>>a>>b>>c;
    vector<LL>V;
    V.clear();
    for(LL i = 1; i <= 81; i++)
    {
        LL x = round(pow((double)i, (double)a )) * b + c;

        LL dig = digit(x);
       // cout<<i<<" "<<x<<" "<<dig<<endl;
        if(dig == i && x > 0 && x < 1000000000)
        {
            V.PB(x);
        }
    }
    sort(V.begin(), V.end());
    cout<<V.size()<<endl;
    for(i = 0; i < V.size(); i++)
        cout<<V[i]<<" ";







    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
