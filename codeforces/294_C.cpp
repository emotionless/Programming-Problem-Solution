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


int main()
{
    LL tc,t,n, cs=1,i,j,k;
    string str;
    LL m;
    cin>>n;
    LL sum = 0;
    LL num;
    for(i = 0; i < n; i++){
        cin>>num;
        sum += num;
    }
    LL sum1 = 0;


    for(i = 0; i < n - 1; i++){
        cin>>num;
        sum1 += num;
    }
    LL fst = sum - sum1;

    sum = 0;
    for(i = 0; i < n - 2; i++){
        cin>>num;
        sum += num;
    }
    cout<<fst<<endl;
    cout<<sum1 - sum<<endl;













    return 0;
}

/*


1 1


*/
