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
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;




int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    string str;
    int i;
    cin>>str;
    if(str[0] == '-')
        cout<<"(";
    cout<<"$";
    int len = str.length();
    int  st = len - 1;
    for(i = 0; i < len; i++)
    {
        if(str[i] == '.')
            st = i - 1;
    }
    string res = "";
    int cnt = 0;
    for(i = st; i >= 0; i--)
    {
        cnt++;
        if(str[i] == '-') continue;
        res = str[i] + res;
        if(cnt == 3)
        {
            if(i == 1 && str[0] == '-') continue;
            if(i == 0) continue;
            res = ',' + res;
            cnt = 0;
        }

    }
    cout<<res;
    cout<<".";
    if(st + 2 < len)
        cout<<str[st + 2];
    else
        cout<<0;
    if(st + 3 < len)
        cout<<str[st + 3];
    else
        cout<<0;
    if(str[0] == '-')
        cout<<")"<<endl;






    return 0;
}

/*

12
1 2 3 4 5 7 8 8 10 10 11 11


*/
