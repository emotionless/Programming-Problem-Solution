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
    string str;
    int t, n;
    string inp;
    cin>>str;
    cin>>inp;
    string ans = "";
    bool ok1 = 0, ok2 = 0;

    for(i = 0; i < str.length(); i++)
    {
        if(ok1 && ok2)
            ans += str[i];
        else if(ok1)
        {
            if((char)(str[i] + 1) <= 'z')
            {
                ans += (char)(str[i] + 1);
                ok2 = 1;
            }
            else
                ans += str[i];
        }
        else if(str[i] + 1 < inp[i])
        {
            ok1 = ok2 = 1;
            ans+= (char)(str[i] + 1);
        }
        else if(str[i] < inp[i])
        {
            ans += str[i];
            ok1 = 1;
        }
        else
            ans += str[i];
    }
    if(!ok1 || !ok2)
        cout<<"No such string"<<endl;
    else
        cout<<ans<<endl;









    return 0;
}

/*


aaaabcd
aaaacde


aaabcd
aaabce

*/
