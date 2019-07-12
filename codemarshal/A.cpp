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


int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    string str;
    while(cin>>str)
    {
        int len = str.length();
        vector<string>V;
        V.clear();
        map<string, int>M;
        M.clear();
        string tmp = "";
        for(i = 0; i < len; i++)
        {
            tmp += str[i];
            V.pb(tmp);
        }

        tmp = "";
        vector<string>V2;
        V2.clear();
        for(i = len - 1; i >=0 ; i--)
        {
            tmp = str[i] + tmp;
            V2.pb(tmp);
        }
        LL res = 0ll;
        for(i = 0; i < len; i++)
        {
            for(j = 0; j < len; j++)
            {
                string here = V[i] + V2[j];
                if(M[here]) continue;
                res++;
                M[here] = 1;
            }
        }
        cout<<res<<endl;



    }







    return 0;
}

/*

5 3 1103


*/
