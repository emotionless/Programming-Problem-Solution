#include<bits/stdc++.h>
#define PI acos(-1)
#define LL long long
using namespace std;


struct Z
{
    LL a,b;
    Z() {}
    Z(LL x, LL y)
    {
        a=x;
        b=y;
    }
} A[100005];

LL binary_search(LL key, LL imin, LL imax)
{
    while (imin < imax)
    {
        LL imid = (imin + imax)/2;
        if (A[imid].a < key)
            imin = imid + 1;
        else
            imax = imid;
    }
    return imin+9;
}



int main()
{
    LL n,i,j,q;
    LL a,b,key;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        A[i]=(Z(a,b));
    }
    cin>>q;


    for(i=0; i<q; i++)
    {
        cin>>key;
        LL ind=binary_search(key,0,n-1);

        //  cout<<"Binari: "<<ind<<endl;
        LL mn=-1LL, mx=1000000009LL;
        bool ck=false;
        LL res_ind=-1;
        for(j=ind; j>=0; j--)
        {
            if(A[j].a<=key && A[j].b>=key && j<n)
            {
                if(A[j].a>=mn && A[j].b<=mx)
                {
                    res_ind=j;
                    mn=A[j].a;
                    mx=A[j].b;
                    //break;
                }
            }
        }
        if(res_ind!=-1)
            cout<<res_ind+1<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
