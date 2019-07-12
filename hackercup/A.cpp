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


int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    string str;
    ofstream myfile;
    myfile.open ("out.txt");
    int len;
    tc = 1;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin>>str;
        int len = str.length();
        string tmp;
        string ans1 = str, ans2 = str;
        for(i = len - 1; i >= 0; i--)
        {
            for(j = 0; j < i; j++)
            {
                if(str[i] == '0' && j == 0) continue;
                if(str[i] > str[j]) continue;
                tmp = str;
                swap(tmp[i], tmp[j]);
                ans1 = min(ans1, tmp);
            }
        }
        for(i = len - 1; i >= 0; i--)
        {
            for(j = 0; j < i; j++)
            {
                if(str[i] == '0' && j == 0) continue;
                if(str[i] < str[j]) continue;
                tmp = str;
                swap(tmp[i], tmp[j]);
                ans2 = max(ans2, tmp);
            }
        }
        myfile<<"Case #"<<tc<<": "<<ans1<<" "<<ans2<<"\n";
//        cout<<"Case #"<<tc<<": "<<ans1<<" "<<ans2<<"\n";
        tc++;
    }








    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
