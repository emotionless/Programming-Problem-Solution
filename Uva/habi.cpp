#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int INDEG[MAX], node, edge;

vector<int> TOPOLOGICAL_SORT(int [][MAX]);

int main(void)
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<a+b<<endl;
    }
}
