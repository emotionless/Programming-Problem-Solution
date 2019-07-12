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
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

struct Z
{
    int num;
    int bit;
    Z() {}
    Z(int _, int __)
    {
        num = _;
        bit = __;
    }
    bool operator<(const Z& A) const
    {
        return bit < A.bit;
    }

};

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n;

    cin>>b>>n;

    vector<Z>V;
    V.clear();
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 32; j++)
        {
            if(i&(1<<j))
            {
                V.PB(Z(i,1<<j));
                break;
            }
        }
    }

    int sz = V.size();
    vector<int>res;
    res.clear();
    sort(V.begin(), V.end());

    for(i = sz - 1; i >= 0; i--)
    {
        if(V[i].bit <= b)
        {
            b = b - V[i].bit;
            res.PB(V[i].num);
        }
    }
    if(b)
        cout<<-1<<endl;
    else
    {
        cout<<res.size()<<endl;
        for(i = 0; i < res.size(); i++)
            cout<<res[i]<<" ";
    }

    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
