#include <bits/stdc++.h>

#define LL long long
#define MX 2009
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
#define ll long long
#define MOD  1000000007ll
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;
int len;
int tar, cnt, tot;

string str1, str2;
void DFS(int ind, int sum)
{
    if(ind == len)
    {
        if(sum == tar) cnt++;
        tot++;
        return;
    }

    if(str2[ind] == '?')
    {
        DFS(ind + 1, sum + 1);
        DFS(ind + 1, sum - 1);
    }
    else if(str2[ind] == '-')
        DFS(ind + 1, sum - 1);
    else
        DFS(ind + 1, sum + 1);

}


int main()
{
    int i, j, k;
    int n;
    cin>>str1;
    cin>>str2;
    tar = 0;
    tot = 0;
    len = str1.length();
    for(i = 0; i < len; i++)
    {
        tar = tar + (str1[i] == '+'?1:-1);
    }
    DFS(0, 0);

    double ans = (double)cnt / (double) tot;
    printf("%.12lf\n", ans);









    return 0;
}

/*

4
4 3 3 3



*/
