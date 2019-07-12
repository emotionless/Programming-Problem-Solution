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
#define MX 200009


using namespace std;


int n, m;


LL arr1[MX];
LL arr2[MX];

int p, q;

LL first(LL num)
{
    for(; p < n; p++)
    {
        if(arr1[p] > num) break;

    }
    return p;
}

LL second(LL num)
{
    for(; q < m; q++)
    {
        if(arr2[q] > num) break;

    }
    return q;
}



int main()
{
    int tc,cs=1,i,j,k;
    cin>>n;
    if(n % 2)
    {
        cout<<"black"<<endl;
    }
    else
    {
        cout<<"white"<<endl;
        cout<<1<<" "<<2<<endl;
    }
    return 0;
}

/*


MC
CSKA
11
28 a 3 y
62 h 25 y
66 h 42 y
70 h 25 y
77 a 4 y
79 a 25 y
82 h 42 r
89 h 16 y
90 a 13 r
91 a 13 r
92 h 25 y


*/
