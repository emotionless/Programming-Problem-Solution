/* LIS in O(n log n)*/
#include<cstdio>
#include<cmath>
#define max(a,b) a>b?a:b
#define MAX 10010

using namespace std;
int a[MAX];
int main()
{
    int i,k,l;
    int n,top;
    scanf("%d",&n);
    int s[MAX],f1[MAX],f2[MAX],mid;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    top=0;
    int res=0;
    s[top=0]=-1;
    int maxv=0,minv=0;
    for(i=0; i<n; i++)
    {
        if(a[i]>s[top])
        {
            s[++top]=a[i];
            f1[i]=top;
        }
        else
        {
            maxv=top;
            minv=0;
            while(1)
            {
                mid=(maxv+minv+1)/2;
                if(mid==maxv)
                    break;
                if(s[mid]<a[i])
                    minv=mid;
                else
                    maxv=mid;
            }
            s[mid]=a[i];
            f1[i]=mid;
        }
        res=max(res,f1[i]);
    }
    printf("%d\n",res);
}
/*
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
out:  6  */
