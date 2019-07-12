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
#define MAX 10000009


using namespace std;

LL prime[MAX];
bool is_prime[MAX];
LL tot[MAX];
int sieve()
{
    int k = 0;
    prime[k++] = 2;
    LL sq = sqrt(MAX);
    for(LL i = 3; i <= sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(LL j = i + i; j < MAX; j += i)
                is_prime[j] = true;
        }
    }
    for(int j = 3; j < MAX; j+=2)
    {
        if(!is_prime[j])
            prime[k++] = j;
    }
    return k;
}



int main()
{
    string str;
    ofstream myfile;
    myfile.open ("output.txt");

    int tc,cs=1,i,j,k;

    int n, m;
    int sz = sieve();

    for(i = 0; i  < sz; i++)
    {
        for(j = prime[i]; j < MAX; j+=prime[i])
        {
            tot[j]++;
        }
    }
    int t;
    scanf("%d", &t);
    LL A, B, K;
    while(t--)
    {
        cin>>A>>B>>K;
        int cnt = 0;
        for(i = A; i <= B; i++)
        {
            if(tot[i]==K)
            {
                cnt++;
            }
        }
//        cout<<"Case #"<<cs<<": "<<cnt<<"\n";
        myfile<<"Case #"<<cs<<": "<<cnt<<"\n";
        cs++;
    }













    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
