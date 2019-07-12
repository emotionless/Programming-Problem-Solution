#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 200009


using namespace std;

int val[100009][327];
int need[330];

int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    string str, tar;
    cin>>str;
    cin>>tar;
    int len = str.length();
    int len2 = tar.length();
    for(i = 0; i < tar.length(); i++)
        need[tar[i] - '?']++;



    val[0][str[0] - '?']++;

    for(i = 1; i < len; i++)
    {
        for(j = 30; j < 60; j++)
            val[i][j] = val[i - 1][j];
        val[i][str[i] - '?']++;
    }
    int res = 0;
    for(i = 0; i < len; i++)
    {
        if(i - len2 + 1 >= 0)
        {
            for(j = 30; j < 60; j++)
            {
                if(val[i][j] - val[i - len2][j] > need[j])
                {
                    break;
                }
            }
            if(j == 60){
                res++;
//                cout<<i<<endl;
            }

        }
    }
    cout<<res<<endl;

    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
