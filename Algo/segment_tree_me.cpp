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
    int st, ed, gcd;
    node *l,*r;
    node() {}
    node(int a, int b)
    {
        st=a;
        ed=b;
        l=r=NULL;
        gcd=107;
    }
};

int GCD(int a, int b)
{
    while(1)
    {
        a=a%b;
        if(a==0) return b;
        b=b%a;
        if(b==0) return a;
    }
}


void insert(node* obj, int pos, int val)
{
    if(obj->st==pos && obj->ed==pos)
    {
        obj->gcd=val;
        return;
    }
    int mid=(obj->st+obj->ed)/2;
    //  cout<<"here\n";
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
    if(obj->gcd==107)
        obj->gcd=val;
    else
        obj->gcd=GCD(obj->gcd,val);
}

int query1(node* obj, int start, int end)
{
    if(obj->st==start && obj->ed==end)
    {
        return obj->gcd;
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
        return GCD(query1(obj->l, start,mid),query1(obj->r,mid+1,end));
    }
}





int main()
{
    int i,j,k;
    int n,q,num,cases=0,t;
//    scanf("%d",&t);
    //  while(t--)
    {
        // printf("Case %d:\n",++cases);
        scanf("%d %d",&n,&q);
        node *root=new node(1,n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&num);
            insert(root,i,num);
        }
        cout<<"hmm\n";
        loop(q)
        {
            int a,b;
            string str;
            cin>>str;
            scanf("%d %d",&a,&b);
            if(str=="Q")
            {
                printf("%d\n",query1(root,a,b));
            }
            else
                insert(root,a,b);
        }
    }
    return 0;
}
/*


10 10
5 1 3 7 5 6 1 23 35 28
1 2
2 3
3 4

*/
