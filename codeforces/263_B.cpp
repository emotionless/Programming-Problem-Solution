#include <bits/stdc++.h>

#define LL long long
#define MX 70
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

LL val[26];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    LL n, K;
    string str;
    cin>>n>>K;
    cin>>str;
    int len= str.length();
    for(i = 0; i < len; i++)
    {
        val[str[i]-'A']++;
    }

    sort(val, val + 26);
    LL res = 0;
    for(i = 25; i >= 0; i--)
    {
        LL have = 0;
        if(K >= val[i])
        {
            K = K - val[i];
            have = val[i];
        }
        else
        {
            have = K;
            K = 0;
        }
        res = res + (have*have);
    }
    cout<<res<<endl;




    return 0;
}

/*

1
1 3
XL S
XL L
XL L

AAAAAAAAAAAAAAAAAAA
*/
