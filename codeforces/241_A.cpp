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


using namespace std;
int n;
string str[10001];
char ch[10001];
LL num[10001];
int ck[100];

LL BS()
{
    LL st=(-1000000000);
    LL ed=(-1000000000), mid;

    while(st<ed)
    {
        mid=(st+ed)/2;
        int i;
        for(i=0; i<n; i++)
        {
            if(str[i]==">")
            {
                if((mid>num[i])==ck[ch[i]]);
                else
                    break;
            }
            if(str[i]=="<")
            {
                if((mid<num[i])==ck[ch[i]]);
                else
                    break;
            }
            if(str[i]==">=")
            {
                if((mid>=num[i])==ck[ch[i]]);
                else
                    break;
            }
            if(str[i]=="<=")
            {
                if((mid<=num[i])==ck[ch[i]]);
                else
                    break;
            }
        }
        if(i==n)
            return mid;
    }
    return ed;
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    cin>>n;
    ck['N']=0;
    ck['Y']=0;
    for(i=0; i<n; i++)
        cin>>str[i]>>num[i]>>ch[i];

    //  LL mid=BS();
    // cout<<mid<<endl;

    for(j=0; j<n; j++)
    {
        LL mid=num[j];
        if((str[j]==">=" || str[j]=="<="));
        if(str[j]==">" && ck[ch[j]]==1)
            mid=mid+1;
        else if(str[j]=="<" && ck[ch[j]]==1)
            mid=mid-1;
        for(i=0; i<n; i++)
        {
            if(str[i]==">")
            {
                if((mid>num[i])==ck[ch[i]]);
                else
                    break;
            }
            if(str[i]=="<")
            {
                if((mid<num[i])==ck[ch[i]]);
                else
                    break;
            }
            if(str[i]==">=")
            {
                if((mid>=num[i])==ck[ch[i]]);
                else
                    break;
            }
            if(str[i]=="<=")
            {
                if((mid<=num[i])==ck[ch[i]]);
                else
                    break;
            }
        }
        if(i==n)
        {
            cout<<mid<<endl;
            return 0;
        }
    }
    cout<<"Impossible"<<endl;











    return 0;
}

/*

4544545454

*/