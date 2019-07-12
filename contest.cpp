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


//data query(node *ob, int s, int ed);

struct node
{
    int mx;
    int st;
    int end;
    int mxposs;
    node *l, *r;
    node() {}
    node(int a, int b)
    {
        st=a;
        end=b;
        mx=mxposs=0;
        l=r=NULL;
    }
};

struct data
{
    int a;
    int b;
};

data query(node *ob, int s, int ed)
{
    data r= {0,0};
    if(ob->st==s && ob->end==ed)
    {
        r.a=ob->mx;
        r.b=ob->mxposs;
        return r;
    }
    int mid=(ob->st + ob->end)/2;
    data p= {0,0};
    data q= {0,0};
    if(ed<=mid)
    {
        if(ob->l !=NULL) p=query(ob->l,s,ed);
    }
    else if(s>mid)
    {
        if(ob->r !=NULL) q=query(ob->r, s,ed);
    }
    else
    {
        if(ob->l !=NULL) p=query(ob->l, s, mid);
        if(ob->r !=NULL) q=query(ob->r, mid+1, ed);
    }
    if(p.b==0)
    {
        r.a=0;
        r.b=p.b;
    }
    else if(q.b==0)
    {
        r.a=0;
        r.b=q.b;
    }
    else if(p.a<0 && q.a>0)
    {
        r.a=p.a;
        r.b=p.b;
    }
    else if(p.a>0 && q.a<0)
    {

        r.a=q.a;
        r.b=q.b;
    }
    else if(p.a>0 && q.a>0)
    {
        r.a=p.a;
        r.b=p.b;
    }
    else if(p.a<0 && q.a<0)
    {

        r.a=p.a;
        r.b=p.b;
    }
    return r;
}


void inserting(node *obj, int poss, int val)
{
    if(obj->st==poss && obj->end==poss)
    {
        obj->mx=val;
        obj->mxposs=poss;
        return;
    }
    int mid=(obj->st + obj->end)/2;
    if(poss<=mid)
    {
        if(obj->l==NULL) obj->l= new node(obj->st, mid);
        inserting(obj->l, poss, val);
    }
    else
    {
        if(obj->r == NULL) obj->r=new node(mid + 1, obj->end);
        inserting(obj->r, poss, val);
    }
    data p= {0,0};
    data q= {0,0};
    if(obj->l !=NULL)
    {
        p.a=obj->l->mx;
        p.b=obj->l->mxposs;
    }
    if(obj->r !=NULL)
    {
        q.a=obj->r->mx;
        q.b=obj->r->mxposs;
    }
    if(p.b==0)
    {
        obj->mx=0;
        obj->mxposs=p.b;
    }
    else if(q.b==0)
    {
        obj->mx=0;
        obj->mxposs=q.b;
    }
    else if(p.a<0 && q.a>0)
    {
        obj->mx=p.a;
        obj->mxposs=p.b;
    }
    else if(p.a>0 && q.a<0)
    {

        obj->mx=q.a;
        obj->mxposs=q.b;
    }
    else if(p.a>0 && q.a>0)
    {
        obj->mx=p.a;
        obj->mxposs=p.b;
    }
    else if(p.a<0 && q.a<0)
    {

        obj->mx=p.a;
        obj->mxposs=p.b;
    }
}

int main()
{
    int i,j,k;
    int n;
    int p,q,r,s,t;
    cin>>n;
    node *root=new node(1,n);
    for(i=1; i<=n; i++)
    {
        cin>>p;
        if(p!=0)
            p=p/p;
        inserting(root,i,p);
    }
    cin>>q;
    for(j=0; j<q; j++)
    {
        cin>>s>>t;
        data res=query(root,s,t);
        cout<<res.a<<endl;//<<res.b<<endl;
    }
}

/*

5
1 2 -3 4 -5
5
1 2
1 3
1 5
3 5
5 5

*/
