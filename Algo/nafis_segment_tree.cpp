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

using namespace std;
struct  node
{
    long st,ed,mx;
    node *l,*r;
    node() {};
    node(long x,long y)
    {
        st=x;
        ed=y;
        mx=-15008;
        l=r=NULL;
    }
};
void insert(node *ob,long pos,long val)
{
    if(ob->st==pos && ob->ed==pos)
    {
        ob->mx=val;
        return;
    }
    long mid=(ob->st+ob->ed)/2;
    if(pos<=mid)
    {
        if(ob->l==NULL)ob->l=new node(ob->st,mid);
        insert(ob->l,pos,val);
    }
    else if(pos>mid)
    {
        if(ob->r==NULL)ob->r=new node(mid+1,ob->ed);
        insert(ob->r,pos,val);
    }
    long l=-15008;
    long r=-15008;
    //ob->mx=max(ob->l->mx, max(ob->l->mx + ob->r->mx,ob->r->mx));
    if(ob->l!=NULL)
        l=ob->l->mx;
    if(ob->r!=NULL)
        r=ob->r->mx;
    ob->mx=(l+r)>0?(l+r):0;
}
long query(node *ob,long st,long ed)
{
    if(ob->st==st && ob->ed==ed)
    {
        return ob->mx;
    }
    long mid=(ob->st+ob->ed)/2;
    if(ed<=mid)
    {
        return query(ob->l,st,ed);
    }
    else if(st>mid)
    {
        return query(ob->r,st,ed);
    }
    else
    {
        int l=query(ob->l,st,mid);
        int r=query(ob->r,mid+1,ed);
        return max(l,max(r,l+r));
    }
}
void destroy(node *ob)
{
    if(ob->l!=NULL)destroy(ob->l);
    if(ob->r!=NULL)destroy(ob->r);
    delete(ob);
}
int main()
{
    long a,b,c,d,e,f,x,y,z;
    scanf("%ld",&a);
    node *root=new node(1,a);
    for(x=1; x<=a; x++)
    {
        scanf("%ld",&c);
        insert(root,x,c);
    }
    cin>>b;
    for(x=0; x<b; x++)
    {
        scanf("%ld %ld",&c,&d);
        cout<<query(root,c,d)<<endl;
    }
}
