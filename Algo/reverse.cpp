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

using namespace std;
int main()
{
	int i,j,k;
	int n;
	vector<int>V;
	vector<int>:: iterator it;
	for(i=0;i<5;i++)
	{
	    cin>>n;
	    V.PB(n);
	}
	it=V.begin();
	cout<<*it;
	reverse(V.begin(), V.end());
	for(i=0;i<5;i++)
	{
	    cout<<V[i]<<ends;
	}
	cout<<*it;
}
