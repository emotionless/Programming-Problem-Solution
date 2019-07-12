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

struct Z
{
    int q, c;
    bool operator < (const Z& A) const
    {
        if(c == A.c) return q > A.q;
        return c < A.c;
    }
};

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    LL a, b, h, m, n, d1, d2;
    int t;
    cin>>t;
    vector<Z>V;
    Z tmp;
    for(i = 0; i < t; i++)
    {
        cin>>a>>b;
        tmp.c = a;
        tmp.q = b;
        V.PB(tmp);
    }
    sort(V.begin(), V.end());
    for(i = 0; i < t; i++)
    {
      //  cout<<i<<" "<<V[i].c<<" "<<V[i].q<<endl;
        if(V[i].c < V[t - 1].c && V[i].q > V[t - 1].q)
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<<"Poor Alex"<<endl;



return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
