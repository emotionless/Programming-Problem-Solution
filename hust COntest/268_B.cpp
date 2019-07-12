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
#define ll long long
#define MX 50009
#define MAXN 50009
#define MOD 1000000000+7
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define mp make_pair

using namespace std;

struct Z
{
    int year, month, day;
    Z() {}
    Z(int _, int __, int ___)
    {
        year = _;
        month = __;
        day = ___;
    }
};

int dd[] = {31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap_year(int year)
{
    if( (year%400==0 || year%100!=0) &&(year%4==0))
        return 1;
    else
        return 0;
}

Z add(int year, int mon, int day)
{
    day++;
    int d = dd[mon - 1];
    if(leap_year(year) && mon == 2)
        d = 29;
    if(day > d)
        mon++, day = 1;
    if(mon > 12)
        year++, mon = 1;
    return Z(year, mon, day);
}

int getmonth(char str[])
{
    if(str[0] == 'J' && str[1] == 'a') return 1;
    if(str[0] == 'F') return 2;
    if(str[0] == 'M' && str[2] == 'r') return 3;
    if(str[0] == 'A' && str[1] == 'p') return 4;
    if(str[0] == 'M' && str[2] == 'y') return 5;
    if(str[0] == 'J' && str[3] == 'e') return 6;
    if(str[0] == 'J' && str[3] == 'y') return 7;
    if(str[0] == 'A' && str[1] == 'u') return 8;
    if(str[0] == 'S') return 9;
    if(str[0] == 'O') return 10;
    if(str[0] == 'N') return 11;
    if(str[0] == 'D') return 12;
}

string convert(int m)
{
    switch(m)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    }
}

int  main()
{

    int i, j, k;
    int m;
    int cases = 1;
    int tc;
    int n;
    char mon[20];
    int  day, next, year;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d-%s", &year, mon);
        cin>>next;
        day = (mon[strlen(mon) - 2] - '0') * 10 + (mon[strlen(mon) - 1] - '0');
        //cout<<year<<" "<<mon<<" "<<day<<endl;

        m = getmonth(mon);
        for(i = 1; i <= next; i++)
        {
            Z get = add(year, m, day);
            year = get.year;
            m = get.month;
            day = get.day;
        }
        printf("Case %d: ", cases++);
        cout<<year<<"-"<<convert(m)<<"-";
        if(day < 9)
            cout<<0;
        cout<<day<<endl;
    }
    return 0;
}
