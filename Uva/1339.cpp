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

using namespace std;


int main()
{
    string x,y;
    int i,j,k,len1,len2,arr1[26],arr2[26];
    while(cin>>x>>y)
    {
        len1=x.length();
        len2=y.length();
        if(len1!=len2)
        {
            printf("NO\n");
            continue;
        }
        for(i=0;i<26;i++)
        {
            arr1[i]=arr2[i]=0;
        }
        for(i=0; i<len1; i++)
        {
            arr1[x[i]-'A']++;
            arr2[y[i]-'A']++;
        }
        sort(arr1,arr1+26);
        sort(arr2,arr2+26);

        int flag=0;

        for(i=0; i<26; i++)
        {
            if(arr1[i]!=arr2[i])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
