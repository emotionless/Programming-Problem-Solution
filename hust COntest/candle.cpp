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

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100009
#define mp make_pair
#define check_bit(aa, bb) (aa & (1<<bb))

using namespace std;

bool is[10];

bool check(int n)
{
    bool used[10];
    for(int i = n; i > n/2; i--)
    {
        clr(used, false);
        int a = i;
        int b = n - i;

        while(a)
        {
            int dig = a % 10;
            if(!is[dig] || used[dig]) break;
            used[dig] = true;
            a = a / 10;
        }
        if(a) continue;

        while(b)
        {
            int dig = b % 10;
            if(!is[dig] || used[dig]) break;
            used[dig] = true;
            b = b / 10;
        }
        if(a == 0 && b == 0)
            return true;
    }
    return false;
}
int num[12];
int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    while(scanf("%d", &n)==1 && n)
    {
        for(i = 0; i < n; i++)
            scanf("%d", &num[i]);
        int cnt = 0;
        string res = "9876543210";

        for(i = 0; i < (1<<10); i++)
        {
            memset(is, false, sizeof is);
            string str = "";
            for(j = 9; j >= 0; j--)
            {
                if(check_bit(i, j))
                {
                    is[j] = true;
                    str = str + (char)(j+'0');
                }
            }

            cnt = 0;

            if(str.length() > res.length()) continue;
            for(k = 0; k < n; k++)
            {
                int cn = num[k];
                if(check(cn))
                    cnt++;
            }
            if(cnt == n)
            {
                if(str.length() < res.length())
                    res = str;
                else if(str.length() == res.length())
                    res = min(str, res);
            }
        }
        printf("Case %d: ", cases++);
        cout<<res<<endl;
    }
    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
