#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

int val[30];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b, h, m, n;
    int K;
    string str;
    cin>>str;
    int len = str.length();
    cin>>K;
    int mx = 0;
    for(i = 0; i < 26; i++)
    {
        cin>>val[i];
        mx = max(mx, val[i]);
    }
    LL sum = 0;
    for(i =0; i <len; i++)
    {
        sum += val[str[i] - 'a'] * ( i + 1);
    }
    for(i = len + 1; i <= K+ len; i++)
    {
        sum += (mx * i);
      //  cout<<i<<" "<<mx<<endl;
    }
    cout<<sum<<endl;



    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
