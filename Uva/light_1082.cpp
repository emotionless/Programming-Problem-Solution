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
#define loop(n) for(int o=1;o<=n;o++)

using namespace std;

struct node
{
    int st, ed, min;
    node *l,*r;
    node() {}
    node(int a, int b)
    {
        st=a;
        ed=b;
        l=r=NULL;
        min=INT_MAX;
    }
};

void insert(node* obj, int pos, int val)
{
    if(obj->st==pos && obj->ed==pos)
    {
        obj->min=min(obj->min,val);
        return;
    }
    int mid=(obj->st+obj->ed)/2;
    if(pos<=mid)
    {
        if(obj->l==NULL) obj->l=new node(obj->st,mid);
        insert(obj->l,pos,val);
    }
    else
    {
        if(obj->r==NULL) obj->r=new node(mid+1, obj->ed);
        insert(obj->r,pos,val);
    }
    obj->min=min(obj->min,val);
}

int query1(node* obj, int start, int end)
{
    if(obj->st==start && obj->ed==end)
    {
        return obj->min;
    }
    int mid=(obj->st + obj->ed)/2;
    if(end<=mid)
    {
        return query1(obj->l,start, end);
    }
    else if(start>mid)
    {
        return query1(obj->r,start,end);
    }
    else
    {
        return min(query1(obj->l, start,mid), query1(obj->r,mid+1,end));
    }
}





int main()
{
    int i,j,k;
    int n,q,num,cases=0,t;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++cases);
        scanf("%d %d",&n,&q);
        node *root=new node(1,n);
        rep(i,1,n)
        {
            scanf("%d",&num);
            insert(root,i,num);
        }
        loop(q)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",query1(root,a,b));
        }
    }
return 0;
}
