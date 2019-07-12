#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const int M = 100010;
struct node
{
    int l,r;
    int c;
} tr[10*M];
struct group
{
    int v;
    int s,e;
} map[M];
int n,q;
int a[M];

int cmp(const void *a,const void *b)
{
    return *(int *)a -*(int *)b;
}
void build(int l,int r,int p)
{
    tr[p].l=l;
    tr[p].r=r;
    tr[p].c=0;
    if(l==r)
        return;
    int mid = (l+r)>>1;

    build(l,mid,p*2);
    build(mid+1,r,p*2+1);
}
void insert(int r,int c,int p)
{
    if(tr[p].r==tr[p].l && tr[p].r==r)
    {
        tr[p].c=c;
        return;
    }

    int mid= (tr[p].l+tr[p].r)>>1;
    if(r<=mid)
        insert(r,c,p*2);
    else
        insert(r,c,p*2+1);

    tr[p].c = tr[p*2].c>tr[p*2+1].c?tr[p*2].c:tr[p*2+1].c;
}
int query(int l,int r,int p)
{
    if(l==tr[p].l && r==tr[p].r)
    {
        return tr[p].c;
    }

    int mid = (tr[p].l+tr[p].r)>>1;

    if(l>mid)
        return query(l,r,p*2+1);
    else if(r<=mid)
        return query(l,r,p*2);
    else
    {
        int tmp1=query(l,mid,p*2);
        int tmp2 = query(mid+1,r,p*2+1);
        return tmp1>tmp2?tmp1:tmp2;
    }
}
int bin_search(int n,int key)
{
    int l=1;
    int h=n;
    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(map[mid].v>key)
            h=mid-1;
        else if(map[mid].v<key)
            l=mid+1;
        else
            return mid;

    }
    return l;
}
int main()
{
    scanf("%d",&n);
    while(n!=0)
    {
        memset(tr,0,sizeof(tr));
        memset(map,0,sizeof(map));
        memset(a,0,sizeof(a));
        scanf("%d",&q);
        int i =0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        int j=1;
        map[j].v=a[1];
        map[j].s=1;
        map[j].e=1;
        for(i=2; i<=n; i++)
        {
            if(a[i]!=a[i-1])
            {
                j++;
                map[j].v=a[i];
                map[j].s=i;
                map[j].e=i;
            }
            else
                map[j].e++;
        }
        int len = j;
        build(1,j,1);
        for(i=0; i<n; i++)
        {
            int tmp = bin_search(len,a[i]);
            int c = map[tmp].e-map[tmp].s+1;
            insert(tmp,c,1);
        }
        for(i=0; i<q; i++)
        {
            int sum=0;
            int l,r;
            scanf("%d %d",&l,&r);

            int g1 = bin_search(len,a[l]);
            int g2 = bin_search(len,a[r]);

            if(g1==g2)
                sum = r-l+1;
            else if(g2-g1==1)
            {
                int tmp1 = r-map[g2].s+1;
                int tmp2 = map[g1].e-l+1;
                sum = tmp1>tmp2?tmp1:tmp2;
            }
            else
            {
                int tmp1 = r-map[g2].s+1;
                int tmp2 = map[g1].e-l+1;
                sum = tmp1>tmp2?tmp1:tmp2;

                int sum1 = query(g1+1,g2-1,1);
                if(sum1>sum)
                    sum=sum1;
            }
            printf("%d/n",sum);
        }
        scanf("%d",&n);

    }
}
