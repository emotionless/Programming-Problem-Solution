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
string str[100001];
int main()
{

    int i, j, k;
    int n, m, x, y;
    cin>>n>>m;
    for(i = 0; i < n; i++)
        cin>>str[i];
    LL ans = 1;
    for(i = 0; i < m; i++)
    {
        set<char>S;
        for(j = 0; j < n; j++)
        {
            S.insert(str[j][i]);
        }
        ans = (ans * S.size()) % MD;
    }
    cout<<ans<<endl;




    return 0;
}

/*


4 4
4 4 4 4



*/
