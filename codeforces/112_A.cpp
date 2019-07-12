#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>


using namespace std;

int x[201];
int y[201];

int main()
{

    int i, j;
    int n;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    int cnt = 0;
    for(i = 0; i < n; i++)
    {
        bool l, r, u, d;
        l = r = u = d = false;

        for(j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(y[i] == y[j] && x[i] > x[j]) r = true;
            if(y[i] == y[j] && x[i] < x[j]) l = true;
            if(x[i] == x[j] && y[i] > y[j]) u = true;
            if(x[i] == x[j] && y[i] < y[j]) d = true;
        }
        if(l && r && u && d)
            cnt++;
    }
    cout<<cnt<<endl;




    return 0;
}

/*

1
1 3
XL S
XL L
XL L



*/
