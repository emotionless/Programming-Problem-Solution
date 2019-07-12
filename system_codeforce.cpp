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


string reverse(string s, int l);
int main()
{
    int i,j,k;
    int l;
    string str;
    cin>>str;
    int p=0,n=0;
    l=str.length();
    int s=0;
    for(i=1;i<l;i++)
    {
        if(str[i]==str[i-1]=='+')
            s++;
        else if(str[i]==str[i-1]=='-')
            n--;

    }
return 0;
}
