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

vector<int>V[100001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,m;
    map< pair<int, int> , bool>M;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        V[a].PB(b);
        V[b].PB(a);
    }

    if(m%2)
    {
        printf("No solution");
        return 0;
    }

    vector<int>res;
    int save=m/2;
    pair<int, int>p;
    st=1;
    while(save--)
    {
        for(; st<=n; st++){
        for(i=0; i<V[i].size(); i++)
        {
            p=make_pair(i,V[i]);
            if(!M[p])
            {
                M[p]=true;
            }
        }
        }
    }







    return 0;
}

/*

4544545454

*/