#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

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


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n, k;
    string str;
    cin>>str>>k;

    int len = str.length();
    int baki = k;
    for(int i = 0; i<len; i++)
    {

        if(baki == 0) break;
        int mn = min(baki, len - i - 1);
        char mx = str[i];
        for(int j = i; j<=i+mn; j++)
            mx = max(mx, str[j]);
        if(mx == str[i]) continue;

        for(j = i; j<=i + mn; j++)
            if(mx==str[j])
            {
                break;
            }

       // cout<<mx<<endl;
        for(int pos = j-1; pos>=i; pos--)
            swap(str[pos+1], str[pos]);
        baki -=(j-i);
        if(baki == 0) break;
    }

    cout<<str<<endl;

    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/