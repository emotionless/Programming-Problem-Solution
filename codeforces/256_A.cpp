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


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b,  m, n;
    int p;
    int tot,c;
    cin>>a>>b>>c;
    cin>>n>>m>>p;
    cin>>tot;

    int sum = a + b + c;
    int sum1 = p + n + m;
    int h = ceil((double)sum/5.0);
    int hh = ceil((double)sum1/10.0);
    if(h+hh>tot)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;





    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/