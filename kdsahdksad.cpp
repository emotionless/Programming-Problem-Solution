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

struct node
{
    long st;
    long end;
    long ma;
    long mapos;
    long mb;
    long mbpos;
    node *l, *r;
    node() {}
    node(long a, long b)
    {
        st=a;
        end=b;
        ma=mapos=mb=mbpos=0;
        l=r=NULL;
    }
};

struct data
{
    long m1,m1poss,m2,m2poss;
};

data query(node *ob, long st, long ed)
{
    data r= {0,0,0,0};
    if(ob->st==st && ob->end==ed)
    {
        r.m1=ob->ma;
        r.m1poss=ob->mapos;
        r.m2=ob->mb;
        r.m2poss=ob->mbpos;
        return r;
    }
    long mid=(ob->st+ob->end)/2;
    data p= {0,0,0,0};
    data q= {0,0,0,0};
    if(ed<=mid)
    {
        if(ob->l!=NULL) p=query(ob->l,st,ed);
    }
    else if(st>mid)
    {
        if(ob->r!=NULL) q=query(ob->r, st, ed);
    }
    else
    {
        if(ob->l!=NULL) p=query(ob->l,st,mid);
        if(ob->r!=NULL) q=query(ob->r,mid+1,ed);
    }
    if(p.m1>q.m1)
    {
        r.m1=p.m1;
        r.m1poss=p.m1poss;
        if(p.m2>q.m1)
        {
            r.m2=p.m2;
            r.m2poss=p.m2poss;
        }
        else
        {
            r.m2=q.m1;
            r.m2poss=q.m1poss;
        }
    }
    else
    {
        r.m1=q.m1;
        r.m1poss=q.m1poss;
        if(p.m1>q.m2)
        {
            r.m2=p.m1;
            r.m2poss=p.m1poss;
        }
        else
        {
            r.m2=q.m2;
            r.m2poss=q.m2poss;
        }
    }
    return r;
}


void insert(node *obj, long poss, long val)
{
    if(obj->st==poss && obj->end==poss)
    {
        obj->ma=val;
        obj->mapos=poss;
        return;
    }
    long mid=(obj->st+obj->end)/2;
    if(poss<=mid)
    {
        if(obj->l==NULL) obj->l= new node(obj->st,mid);
        insert(obj->l,poss,val);
    }
    else
    {
        if(obj->r==NULL) obj->r=new node(mid+1, obj->end);
        insert(obj->r,poss,val);
    }
    data p= {0,0,0,0};
    data q= {0,0,0,0};
    if(obj->l!=NULL)
    {
        p.m1=obj->l->ma;
        p.m1poss=obj->l->mapos;
        p.m2poss=obj->l->mbpos;
        p.m2=obj->l->mb;
    }
    if(obj->r!=NULL)
    {
        q.m1=obj->r->ma;
        q.m1poss=obj->r->mapos;
        q.m2poss=obj->r->mbpos;
        q.m2=obj->r->mb;
    }
    if(p.m1==0 || q.m1==0)
    {
     /*   obj->ma=p.m1;
        obj->mapos=p.m1poss;
        if(q.m1>p.m2)
        {
            obj->mb=q.m1;
            obj->mbpos=q.m1poss;
        }
        else
        {
            obj->mb=p.m2;
            obj->mbpos=p.m2poss;
        } */
        obj->ma=0;
        if(p.m1==0)
            obj->mapos=p.m1poss;
        else
            obj->mapos=q.m1poss;
    }
    else
    {
        obj->ma=q.m1;
        obj->mapos=q.m1poss;
        if(p.m1>q.m2)
        {
            obj->mb=p.m1;
            obj->mbpos=p.m1poss;
        }
        else
        {
            obj->mb=q.m2;
            obj->mbpos=q.m2poss;
        }
    }
}

int main()
{
    long i,j,k;
    long n,c,b,d;
    string str;
    cin>>n;
    node *root=new node(1,n);
    for(i=1; i<=n; i++)
    {
        cin>>c;
        if(c!=0)
        c=c/c;
        insert(root,i,c);
    }
    scanf("%d",&b);
    for(i=1; i<=b; i++)
    {
        cin>>str>>c>>d;
        if(str=="Q")
        {
            data p=query(root,c,d);
            printf("%ld\n",p.m1+p.m2);
        }
        else
            insert(root,c,d);
    }
}
