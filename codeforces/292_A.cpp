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

int val[11];

int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    string str;
    cin>>n;
    cin>>str;
    for(i = 0; i < str.length(); i++)
    {
        int dd = str[i] - '0';
        if(dd <= 1) continue;
        for(j = 2; j <= dd; j++)
        {
            int d = j;
            if(d == 2) val[2]++;
            else if(d == 3) val[3]++;
            else if(d == 9) val[3]+=2;
            else if(d == 4) val[2]+=2;
            else if(d == 8) val[2]+=3;
            else if(d == 5) val[5]++;
            else if(d == 7) val[7]++;
            else if(d == 6) val[2]++, val[3]++;
        }
    }
    vector<int>V;
    V.clear();

//    for(i = 2; i <= 7; i++)
//        cout<<i<<" "<<val[i]<<endl;

    for(i = 7; i >= 2; i--)
    {
        while(val[i])
        {
            for(j = i; j >= 2; j--)
            {
                int d = j;
                if(d == 2) val[2]--;
                else if(d == 3) val[3]--;
                else if(d == 9) val[3]-=2;
                else if(d == 4) val[2]-=2;
                else if(d == 8) val[2]-=3;
                else if(d == 5) val[5]--;
                else if(d == 7) val[7]--;
                else if(d == 6) val[2]--, val[3]--;
            }
            V.pb(i);
        }
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    for(i = 0; i < V.size(); i++)
        cout<<V[i];






    return 0;
}

/*

5 3 1103


*/
