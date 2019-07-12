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

int largestArea(int arr[], int len)
{
    int area[len]; //initialize it to 0
    int n, i, t;
    stack<int> St;  //include stack for using this #include<stack>
    bool done;

    for (i=0; i<len; i++)
    {
        while (!St.empty())
        {
            if(arr[i] <= arr[St.top()])
            {
                St.pop();
            }
            else
                break;
        }
        if(St.empty())
            t = -1;
        else
            t = St.top();
//Calculating Li
        area[i] = i - t - 1;
        St.push(i);
    }

//clearing stack for finding Ri
    while (!St.empty())
        St.pop();

    for (i=len-1; i>=0; i--)
    {
        while (!St.empty())
        {
            if(arr[i] <= arr[St.top()])
            {
                St.pop();
            }
            else
                break;
        }
        if(St.empty())
            t = len;
        else
            t = St.top();
//calculating Ri, after this step area[i] = Li + Ri
        area[i] += t - i -1;
        St.push(i);
    }

    int max = 0;
//Calculating Area[i] and find max Area
    for (i=0; i<len; i++)
    {
        area[i] = arr[i] * (area[i] + 1);
        if (area[i] > max)
            max = area[i];
    }

    return max;
}

int main()
{
    int i,j,k;
    int n;
    int array[100];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>array[i];
    cout<<largestArea(array,n);
}
