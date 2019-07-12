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
#define MAX 2000


using namespace std;


bool is[30];
LL solve(LL a, LL b)
{
    LL ret = 0ll;
    if(a <= 20 && b <= 20)
    {
        for(int i = 0; i <= 20; i++)
        {
            if( a <= i && i <= b)
            {
                if(is[i]) ret++;
            }
        }
    }
    else if(a <= 20 && 20 <= b)
    {
        for(int i = 0; i <= 20; i++)
        {
            if( a <=i && i <= b)
                if(is[i]) ret++;
        }
        ret += (b - 20);
    }
    else
        ret = b - a + 1;
    return ret;
}

int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    string str;

    is[4] = is[8] = is[9] = is[12] = is[13] = is[16] = is[17] = is[18] = is[20] = true;


    s1(tc);
//    cin>>tc;
    LL a, b, c;



    while(tc--)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", solve(a, b));
    }






    return 0;
}

/*

5 3 1103


*/
