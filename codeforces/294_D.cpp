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
#define MAX 1000009


using namespace std;

LL val[30];
LL s[MAX];


int main()
{
    LL tc,t,n, cs=1,i,j,k;
    string str;
    map< pair<char, LL> , LL>M;
    map< pair<char, LL> , LL> ::iterator it;
    LL m;
    for(i = 0; i < 26; i++)
        cin>>val[i];

    cin>>str;
    LL sum = 0;
    int len = str.length();
    for(i = 0; i < len; i++)
    {
        sum += val[str[i] - 'a'];
        s[i] = sum;
        M[mp(str[i], sum)]++;
//        cout<<str[i]<<" "<<sum<<" "<<M[mp(str[i], sum)]<<endl;
    }
    LL res = 0ll;
    for(i = 0; i < len; i++)
    {
        LL tmp = s[i - 1] + 2ll*val[str[i] - 'a'];
//        if(M[mp(str[i], tmp)] == 0ll) continue;
        LL tk= M[mp(str[i], tmp)];
        if(tk > 0)
        {
            res += tk;
            M[mp(str[i], tmp)]--;
        }
//        cout<<str[i]<<" "<<M[mp(str[i], tmp)] + 1<<endl;
//        cout<<i<<" "<<str[i]<<" "<<s[i-1] <<" "<<2*val[str[i] - 'a']<<" "<<tmp<<endl;

    }
    if(res <= 0)
        cout<<0<<endl;
    else
        cout<<res<<endl;



    return 0;
}

/*

-3 4 -4 -1 3 5 -5 -3 3 2 1 4 5 -3 -1 4 2 -2 1 -1 1 5 -4 0 -5 4
olspxykjqr



*/
