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
    int t;
    int x1, x2, y1, y2;
    LL n;

    //LL a = (100000LL * 100000LL);
    //cout<<a<<endl;
    map<LL, LL>M;
    cin>>n;
    LL val;
    LL mn = 100000000000;
    LL mx = 0;
    for(i = 0; i < n; i++)
    {
        cin>>val;
        M[val] ++;
        mn = min(mn, val);
        mx = max(mx, val);
    }
    LL dif = mx - mn;
    if(dif == 0)
    {
        cout<<0<<" ";
        cout<<(M[mx] * (M[mx] - 1))/2<<endl;
        return 0;
    }

    cout<<dif<<" "<<M[mx] * M[mn]<<endl;





    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
