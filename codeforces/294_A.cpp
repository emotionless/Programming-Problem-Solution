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

int getval(char a)
{
    a = tolower(a);
    if(a == '.' || a == 'k') return 0;
    if(a == 'q') return 9;
    if(a == 'r') return 5;
    if(a == 'b') return 3;
    if(a == 'n') return 3;
    if(a == 'p') return 1;
    return 0;
}

int main()
{
    LL tc,t,n, cs=1,i,j,k;
    string str[10];
    for(i = 0; i < 8; i++)
    {
        cin>>str[i];
    }
    int w = 0, b = 0;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(str[i][j] <= 'Z')
                w+=getval(str[i][j]);
            else
                b+= getval(str[i][j]);
        }
    }
    if(w == b)
        cout<<"Draw"<<endl;
    else if(w > b)
        cout<<"White"<<endl;
    else
        cout<<"Black"<<endl;











    return 0;
}

/*

8 3 3
1 2 3 4 5 6 7 8
7 8 1

5 8 2
3 1 5 2 4
4 4 4 4 4 4 4 4

*/
