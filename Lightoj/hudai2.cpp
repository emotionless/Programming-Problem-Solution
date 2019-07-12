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
***** Sorry for bad written code **********
*/


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<cfloat>
#include<ctime>
#include<cassert>
#include<map>
#include<utility>
#include<set>
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<sstream>
#include<complex>
#include<stack>
#include<queue>
#include<numeric>
#include<list>
#include<iomanip>
#include<fstream>

#define LL long long
#define MX 20009
#define MOD 1000000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))
#define FOR(i, b) for(i = 0; i < b; i++)

using namespace std;



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n, P, K;
    string str;
    cin>>t;
    LL x, y;
    while(t--)
    {
        cin>>x>>y;
        x = llabs(x);
        y = llabs(y);
        if(y == 0 && llabs(x)%2==1)
        {
            cout<<2*llabs(x) + 1<<endl;
            continue;
        }

        LL dis;
        if(x < y)
        {
            LL pre = 2*x;
            dis = llabs(y - x);
            if(dis % 2 == 0)
                printf("%lld\n", 2*dis + pre);
            else
                printf("%lld\n", 2*dis - 1 + pre);
        }
        else
        {
            LL pre = 2*y;
            dis = llabs(x - y);
            if(dis % 2 == 0)
                printf("%lld\n",2*dis + pre);
            else
                printf("%lld\n",2 * dis + 1 + pre);
        }
    }
    return 0;
}

/*


1
7
1 2 3 4 5 6 7
30


*/
