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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)

using namespace std;


int main()
{
    int i,j,k;
    int n;
    string str1,str2;
    scanf("%d",&n);
    getchar();
    map<string,string>M;
    loop(n)
    {
        getline(cin,str1);
        getline(cin,str2);
        M[str1]=str2;
    }
    int q;
    scanf("%d",&q);
    getchar();
    loop(q)
    {
        getline(cin,str1);
        cout<<M[str1]<<endl;
    }
    return 0;
}
