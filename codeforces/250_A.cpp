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

int arr[1001];
string str[5];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n;
    int sum = 0;
    for(i = 0; i< 4; i++)
    {
        cin>>str[i];
     //   getchar();
        int l = str[i].length() - 2;
        arr[l]++;

        sum += str[i].length()-2;
    }
    vector<int>res;
    res.clear();
    for(i = 0; i < 4; i++)
    {
        int cnt = 0;
       for(j = 0; j< 4; j++)
       {
           if(i ==j) continue;

           if((str[i].length()-2)*2<=(str[j].length()-2)&& arr[(str[i].length()-2)]==1 && (str[i].length()-2))
            cnt++;

       }
       if(cnt==3)
       {
           res.PB(i);
       }

       cnt = 0;
       for(j = 0; j< 4; j++)
       {
           if(i ==j) continue;

           if( (str[j].length()-2)*2 <= (str[i].length()-2) && arr[(str[i].length()-2)]==1 && (str[i].length()-2))
            cnt++;
       }
       if(cnt==3)
       {
           res.PB(i);
       }
    }
    if(res.size()==1)
        cout<<(char)(res[0]+'A')<<endl;
    else
    cout<<"C"<<endl;








    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
