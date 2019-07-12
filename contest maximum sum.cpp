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
        max1=-INT_MAX;
        max2=-INT_MAX;
        l=r=NULL;
    }
};
struct nn
{
    int f;
    int s;
    nn() {}
    nn(int a, int b)
    {
        f=a;
        s=b;
    }
};

void insert(node *obj, int poss, int val)
{
    if(obj->st==poss && obj->ed==poss)
    {
        obj->max1=val;
        obj->max2=-99999;
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
    if(val>=obj->max1)
       {
           obj->max2=obj->max1;
           obj->max1=val;
       }
    else if(val>=obj->max2)
           obj->max2=val;
       /*
    int f=obj->max1+obj->max2+val;
    obj->max1=max(max(obj->max2,val),obj->max1);
    int s=min(min(obj->max2,val),obj->max1);
    obj->max2=f-obj->max1-s;*/

}
nn ret;
nn query(node *obj,int st, int ed)
{
    if(obj->st==st && obj->ed==ed)
    {
        ret.f=obj->max1;
        ret.s=obj->max2;
        return ret;
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
        ret=query(obj->l,st,mid);
        int a=ret.f;
        int b=ret.s;
        //cout<<a<<ends<<b<<endl;
        ret=query(obj->r,mid+1,ed);
        int c=ret.f;
        int d=ret.s;
        //cout<<c<<ends<<d<<endl;
        //ret.f=max(max(a,b),max(c,d));
        ret.f=ret.s=-999999;
        if(a>=ret.f)
        {
            ret.s=ret.f;
            ret.f=a;
        }
        else if(a>=ret.s)
            ret.s=a;
        if(b>=ret.f)
        {
            ret.s=ret.f;
            ret.f=b;
        }
        else if(b>=ret.s)
            ret.s=b;
        if(c>=ret.f)
        {
            ret.s=ret.f;
            ret.f=c;
        }
        else if(c>=ret.s)
            ret.s=c;
        if(d>=ret.f)
        {
            ret.s=ret.f;
            ret.f=d;
        }
        else if(d>=ret.s)
            ret.s=d;
        return ret;
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
    scanf("%d",&a);
    node *root=new node(1,a);
    for(i=1; i<=a; i++)
    {
        scanf("%d",&c);
        insert(root,i,c);
    }
    scanf("%d",&b);
    nn tmp;
    string str;
    for(i=1; i<=b; i++)
    {
        cin>>str;
        scanf("%d %d",&c,&d);
        if(str=="Q")
        {
        tmp=query(root, c, d);
        printf("%d\n",tmp.f+tmp.s);
        }
        else
        insert(root,c,d);
    }
}

/*

5 11
1 2 3 4 5

2 3
1 5
4 5
3 5
2 5
1 3
1 4
1 2
3 4
3 5
2 5


*/
