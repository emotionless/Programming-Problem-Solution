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
#define clr(aa, bb) memset(aa, bb, sizeof aa)
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
    int a,b, K,h,mn;
    string str;
    cin>>str;
    cin>>K;
    int len = str.length();
    int mx = 0;
    for(i = 0; i < len + K; i++)
    {
        for(j = i + 1; j < len + K; j++)
        {
            int k1=j;
            int cnt = 0;
            for(int k = i; k < j && k1 < len + K; k++, k1++)
            {
                if(k >=len || k1 >=len)
                    cnt+=2;
                else if(str[k] == str[k1])
                    cnt+=2;
                else
                    break;
            }
            mx = max(mx, cnt);
            //cout<<i<<" "<<j<<" "<<cnt<<endl;
        }
    }
    cout<<mx<<endl;





    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
