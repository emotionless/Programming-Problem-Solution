/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


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
#define MAX 10000003


using namespace std;

int has[10000009];
bool vis[10000009];
long long sum[10000009];


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");


    int n;
    int a,b;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        has[a]++;
    }
    for(int i=2; i<=10000003; i++)
    {
        if(!vis[i])
        {
            if(has[i])sum[i]+=has[i];
            for(int j=i+i; j<10000003; j+=i)
            {
                vis[j]=true;
                if(has[j])sum[i]+=has[j];
            }
        }
    }
    //REP(i,50)if(!vis[i])cout << i << endl;
    //cout << "#" << endl;
    for(int i=2; i<=10000003; i++)
    {
        sum[i]=sum[i-1]+sum[i];
    }
//    REP(i,13)
//    {
//        cout << i << " " << has[i] << " " << sum[i] << endl;
//    }
    int Q;
    scanf("%d",&Q);
    for(int q=0;q<Q; q++)
    {
        scanf("%d %d",&a,&b);
        if(a>=10000000)
        {
            puts("0");
            continue;
        }
        if(b>=10000003)b=10000002;
        printf("%d\n",sum[b]-sum[a-1]);
    }
}
