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
    int tc,cs=1,i,j,k;
    int n,m;
    string str;
    cin>>str;
    int len = str.length();
    char last = str[len - 1];
    int take = -1;
    for(i = 0; i < len; i++)
    {
        if(str[i] < last && (str[i] - '0')%2==0)
        {
            swap(str[len - 1], str[i]);
            cout<<str<<endl;
            return 0;
        }
        if(str[i] > last && (str[i] - '0')%2==0)
        {
            take = i;
        }
    }
    if(take == -1)
    {
        cout<<-1<<endl;
        return 0;
    }
    swap(str[take], str[len - 1]);
    cout<<str<<endl;










    return 0;
}

/*

24687
14682
14689


*/
