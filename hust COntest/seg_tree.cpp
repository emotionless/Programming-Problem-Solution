/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: emotionless ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;

int seg[4*130][130][130];

void insert(int ind, int st, int ed)
{
    if(st==pos && ed==pos)
    {
        seg[ind][r][c]+=val;
        return;
    }
    int mid=(st+ed)/2;
    int lft=ind*2;
    int rgt=ind*2+1;

    if(pos<=mid)
        insert(lft, st, mid, pos, val, r, c);
    else
        insert(rgt, mid+1, ed, pos, val, r, c);

    seg[ind][r][c]=seg[lft][r][c]+seg[rgt][r][c];
}

int query(int ind, int st, int ed, int l, int r, int col, int col1, int c, int c1)
{
    if(st==l && ed==r)
    {
        // return seg[ind][col][c];
        int ret=0;
        for(int i=min(c,c1); i<=max(c,c1); i++)
        {
            for(int j=min(col, col1); j<=max(col, col1); j++)
            {
                ret+=seg[ind][j][i];
            }
        }
        return ret;
    }
    int mid=(st+ed)/2;
    int lft=ind*2;
    int rgt=ind*2+1;

    if(r<=mid)
        return query(lft, st, mid, l, r, col,col1, c, c1);
    else if(l>mid)
        return query(rgt, mid+1, ed, l, r, col,col1, c, c1);

    else
    {
        int a=query(lft, st, mid, l, mid, col,col1, c, c1);

        int b=query(rgt, mid+1, ed, mid+1, r, col,col1, c, c1);

        return a+b;
    }
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,m,l,val, op, r, l1, r1;
    int t,c,c1;

    cin>>n;
    cin>>op;
    while(op!=3)
    {
        cin>>l>>r>>c;
        l++;
        r++;
        c++;
        if(op==1)
        {
            cin>>val;
            insert(1,1,n,l,val,r,c);
        }
        else
        {
            cin>>l1>>r1>>c1;
            l1++;
            r1++;
            c1++;
            int res=query(1,1,n,min(l1,l), max(l1,l), r1, r, c1, c);
            cout<<res<<endl;
        }
        cin>>op;
    }

    memset(seg, 0, sizeof seg);




    return 0;
}
