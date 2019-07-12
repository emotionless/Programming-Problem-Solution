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

int main()
{

    int i, j, k;
    int n, x, y;
    int m, a, b;
    cin>>n>>m>>a>>b;
    int mn = 100000000;

    for(i = 0; i <= n; i++)
    {
        for(j =  0; j <= n; j++)
        {
            if(((i * m) + j) >= n)
            {
                mn = min(mn, i * b + j * a);
            }
        }
    }
    cout<<mn<<endl;




    return 0;
}

/*


4 4
4 4 4 4



*/
