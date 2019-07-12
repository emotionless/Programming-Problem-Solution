
/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD *************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
***** Codejam Username: emotionless*******
***** Hackerrank username: emotionless ***
***** Hackerearth username: emotionless **
***** And the rest username: emotionless *
******************************************
**** Sorry for bad written code **********
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

#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define chk_mask(aa, bb) (aa & (1<<bb))
#define set_mask(aa, bb) (aa | (1<<bb))
#define MX 20000

using namespace std;

int times[10009];


int  main()
{

    int j, k;
    int m, i;
    int cases = 1;
    int tc;
    int n1, n2, n3, t1, t2, t3;
    cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;

    for(i = 1; i <= k; i++)
        times[i] = 0;
    int ct = 0;

    for(i = n1; i < (k + n1); i += n1)
    {
        int cnt = n1;
        int tmp = i - n1;
        i = min(i, k);

        if(ct > times[i])
        {
            ct += t1;
        }
        else
            ct = times[i] + t1;
        //cout<<i<<endl;
        for(j = i; j > tmp; j--, cnt--)
        {
            times[j] = ct;
        }
    }
     cout<<endl;

    for(i = 1; i <= k; i++)
         cout<<i<<" "<<times[i]<<endl;
    ct = 0;

    for(i = n2; i < (k + n2); i += n2)
    {
        int cnt = n2;
        int tmp = i - n2;
        i = min(i, k);
        if(ct > times[i])
        {
            ct += t2;
        }
        else
            ct = times[i] + t2;
        //cout<<ct<<endl;
        for(j = i; j > tmp; j--)
        {
            times[j] = ct;
        }
    }
     cout<<endl;

    for(i = 1; i <= k; i++)
         cout<<i<<" "<<times[i]<<endl;

    ct = 0;

    for(i = n3; i < (k + n3); i += n3)
    {
        int cnt = n3;
        int tmp = i - n3;
        i = min(i, k);
        if(ct > times[i])
        {
            ct += t3;
        }
        else
            ct = times[i] + t3;
        //cout<<i<<endl;
        for(j = i; j > tmp; j--, cnt--)
        {
            times[j] = ct;
        }
    }
    cout<<endl;
     for(i = 1; i <= k; i++)
        cout<<i<<" "<<times[i]<<endl;
    cout<<times[k]<<endl;



    return 0;
}

/*

8 3 4 3 10 9 4


*/
