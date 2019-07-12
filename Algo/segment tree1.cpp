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

struct node
{
    int st,ed,res;
    node *l,*r;
    node() {}
    node(int a, int b)
    {
        st=a;
        ed=b;
        l=r=NULL;
        res=0;
    }
};

void ins(node *obj, int val, int poss)
{
    if(obj->st==poss && obj->ed==poss)
    {
        obj->res=val;
        return;
    }
    int mid=(obj->st+obj->ed)/2;
    if(poss<=mid)
    {
        if(obj->l==NULL) obj->l=new node(obj->st,mid);
        ins(obj->l,val,poss);
    }
    else
    {
        if(obj->r==NULL) obj->r=new node(mid+1,obj->ed);
        ins(obj->r,val,poss);
    }
    int l=1,r=1;
    if(obj->l!=NULL)
    {
        l=obj->l->res;
    }
    if(obj->r!=NULL)
    {
        r=obj->r->res;
    }
    obj->res=l*r;

}

int qury(node *obj, int s, int e)
{
    if(obj->st==s && obj->ed==e)
    {
        return obj->res;
    }
    int mid=(obj->st+obj->ed)/2;
    if(e<=mid)
    {
        return qury(obj->l,s,e);
    }
    else if(s>mid)
    {
        return qury(obj->r,s,e);
    }
    else
    {
        int l=qury(obj->l,obj->st,mid);
        int r=qury(obj->r,mid+1, obj->ed);
        return l*r;
    }
}


int main()
{
    int i,j,k;
    int n;
    cin>>n;
    node *root=new node(1,n);

    for(i=1;i<=n; i++)
    {
        cin>>j;
        if(j!=0)
            j=j/abs(j);
        ins(root,j,i);
    }
    cin>>k;
    int a,b;
    for(i=0; i<k; i++)
    {
        cin>>a>>b;
        cout<<qury(root,a,b)<<endl;
    }
    return 0;
}
