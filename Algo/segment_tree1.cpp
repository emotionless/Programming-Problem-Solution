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

using namespace std;

struct node
{
    int st,ed,max;
    node *l,*r;
    node(int a, int b)
    {
        st=a;
        ed=ed;
        max=INT_MAX;
        l=r=NULL;
    }
};

void insert(node *obj,int poss, int val)
{
    if(obj->st==poss && obj->ed==poss)
    {
        obj->max1=val;
        return;
    }
    int mid=(obj->st+obj->ed)/2;
    if(poss<=mid)
    {
        if(obj->l==NULL)
            obj->l=new node(obj->st, mid);
        insert(obj->l,poss, val);
    }
    else if(poss>mid)
    {
        if(obj->r==NULL)
            obj->r=new node(mid+1,obj->ed);
        insert(obj->r,poss,val);
    }
    obj->max=max(obj->max,val);
}

int main()
{
    int i=10,j,k;
    node *root;
    insert(root,1,i);
}
