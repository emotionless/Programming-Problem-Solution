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
    int st,ed,max1,max2;
    node *l,*r;
    node() {}
    node(int u, int v)
    {
        st=u;
        ed=v;
        max1=0;
        max2=0;
        l=r=NULL;
    }
};

void insert(node *obj, int poss, int val)
{
    if(obj->st==poss && obj->ed==poss)
    {
        obj->max1=val;
        return;
    }
    int mid=(obj->st+obj->ed)/2;
    if(poss<=mid)
    {
        if(obj->l==NULL) obj->l=new node(obj->st,mid);
        insert(obj->l,poss,val);
    }
    else if(poss>mid)
    {
        if(obj->r==NULL) obj->r=new node(mid+1, obj->ed);
        insert(obj->r,poss,val);
    }
     int f=obj->max1+obj->max2+val;
   obj->max1=max(max(obj->max2,val),obj->max1);
   int s=min(min(obj->max2,val),obj->max1);
   obj->max2=f-obj->max1-s;
}

int query(node *obj,int st, int ed)
{
    if(obj->st==st && obj->ed==ed)
    {
        return obj->max2+obj->max1;
    }
    int mid=(obj->st+obj->ed)/2;
    if(ed<=mid)
    {
        return query(obj->l, st, ed);
    }
    else if(st>mid)
    {
        return query(obj->r,st,ed);
    }
    else
    {
        return query(obj->l,st,mid), query(obj->r,mid+1,ed);
    }
}
void destroy(node *obj)
{
    if(obj->l!=NULL) destroy(obj->l);
    if(obj->r!=NULL) destroy(obj->r);
    delete(obj);
}
int main()
{
    int i,j,k;
    int a,c,b,d,e,f,x,y,p,q;
    scanf("%d %d",&a,&b);
    node *root=new node(1,a);
    for(i=1; i<=a; i++)
    {
        scanf("%d",&c);
        insert(root,i,c);
    }
    for(i=1; i<=b; i++)
    {
        scanf("%d %d",&c,&d);
        cout<<query(root, c, d)<<endl;
    }
}
