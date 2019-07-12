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
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
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


int val1[300];
int val2[300];

int main()
{
    int tc,cs=1,i,j,k;
    string str;
    int t, n;
    string inp;
    cin>>str>>inp;
    int len1 = str.length();
    int len2 = inp.length();
    for(i = 0; i < len1; i++)
    {
        val1[str[i]]++;
    }
    for(i = 0; i < len2; i++)
    {
        val2[inp[i]]++;
    }
    int res1 = 0, res2 = 0;

    for(i = 0; i < 150; i++)
    {
        if(val1[i])
        {
            if(val2[i])
            {
                int mn = min(val1[i], val2[i]);
                res1 += mn;
                val1[i] -= mn;
                val2[i] -= mn;
            }
        }
    }

    for(char i = 'A'; i <= 'Z'; i++)
    {
        if(val1[i])
        {
            int mn = min(val1[i], val2[i + 32]);
            res2 += mn;
            val1[i] -= mn;
            val2[i + 32] -= mn;
        }
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        if(val1[i])
        {
            int mn = min(val1[i], val2[i - 32]);
            res2 += mn;
            val1[i] -= mn;
            val2[i - 32] -= mn;
        }
    }
    cout<<res1<<" "<<res2<<endl;













    return 0;
}

/*

aaaaAAAA
AAAAaaaa


*/
