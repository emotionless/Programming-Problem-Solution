#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

LL arr[10];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n, m, u,v;
    int c,d;
    cin>>a>>b>>c>>d;
    string str;
    cin>>str;
    int l=str.length();
    for(i=0; i<l; i++)
        arr[str[i]-'1'+1]++;
    LL res=arr[1]*a;
    res+=arr[2]*b;
    res+=arr[3]*c;
    res+=arr[4]*d;
    cout<<res<<endl;


    return 0;
}

/*

15
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
11 10
12 11
13 12
14 13
15 14
0 1 0 0 1 1 1 1 1 1 0 0 0 1 1
1 1 1 1 0 0 1 1 0 1 0 0 1 1 0


*/