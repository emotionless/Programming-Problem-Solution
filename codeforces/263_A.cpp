#include <bits/stdc++.h>

#define LL long long
#define MX 70
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>


using namespace std;

string str[109];

int main()
{
       FILE * fin, * fout, *fp;
     fp=fopen("out.txt", "w");
     for(int i = 0; i < 100000; i++)
     fprintf(fp, "A");

    int i, j;
    int n, m;
    cin>>n;
    for(i = 1; i <= n; i++)
    {

        cin>>str[i];
        str[i] = " "+str[i];
    }
    int cnt = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            int a = (str[i-1][j] == 'o'?1:0) + (str[i][j + 1] == 'o'?1:0) + (str[i][j - 1] == 'o'?1:0) + (str[i+1][j] == 'o'?1:0);
            if(a%2 == 0)
                cnt++;
        }
    }
    if(cnt == (n * n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;






    return 0;
}

/*

1
1 3
XL S
XL L
XL L



*/
