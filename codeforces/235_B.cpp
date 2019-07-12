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

int vis[4001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,m, curr;

    cin>>curr>>m;
    for(i=1; i<=curr; i++)
    vis[i]=false;
    int op, num1, num2;
    for(i=0; i<m; i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>num2>>num1;
            vis[num2]=true;
            vis[num1]=true;
        }
        else
        {
            cin>>num2;
            vis[num2]=true;
        }
    }
    vector<int>V;
    for(i=1; i<curr; i++)
    {
        if(!vis[i])
        V.PB(i);
    }

    int sz=V.size();
    int cnt=0;
    V.PB(100000);
    for(i=0; i<sz; i++)
    {
        if((V[i]+1)==V[i+1])
        {
            i++;

        }
        cnt++;
    }
    cout<<cnt<<" "<<sz<<endl;





    return 0;
}

/*

4544545454

*/
