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
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i,j,k;
    int n,m;
    char f,s;
    int fi,si;
    scanf("%d %d",&n,&m);
    if(n>m)
    {
        f='B';
        s='G';
        fi=n;
        si=m;
    }
    else
    {
        f='G';
        s='B';
        fi=m;
        si=n;
    }
    while(fi>0)
    {
        printf("%c",f);
        if(si>0)
        {
            printf("%c",s);
            si--;
        }
        fi--;
    }
    return 0;
}
