/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;

struct Z
{
    int sum, lft, rgt;
};

Z res[4*1000001+5];

void insert(int ind, int st, int ed, int pos, int val)
{
    if(st==ed)
    {
        if(val==40)
        {
            res[ind].lft=1;
            res[ind].rgt=0;
        }
        else
        {
            res[ind].rgt=1;
            res[ind].lft=0;
        }

        res[ind].sum=0;
        return;
    }

    int mid=(st+ed)/2;

    if(pos<=mid)
        insert(ind*2, st, mid, pos, val);
    else
        insert(ind*2+1, mid+1, ed, pos, val);

    int tmp=min(res[ind*2].lft, res[ind*2+1].rgt);
    res[ind].sum=res[ind*2].sum+res[ind*2+1].sum+tmp;
    res[ind].lft=res[ind*2].lft+res[ind*2+1].lft-tmp;
    res[ind].rgt=res[ind*2].rgt+res[ind*2+1].rgt-tmp;
}
Z QUERY(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
    {
        return res[ind];
    }
    int mid=(st+ed)/2;

    if(ul<=mid)
        return QUERY(ind*2, st, mid, ll, ul);
    else if(ll>mid)
        return QUERY(ind*2+1, mid+1, ed, ll, ul);
    else
    {
        Z a = QUERY(ind*2, st, mid, ll, mid) ;
        Z b= QUERY(ind*2+1, mid+1, ed, mid+1, ul);

        Z tmp;
        int mn=min(a.lft, b.rgt);
        tmp.sum=a.sum+b.sum+mn;

        tmp.lft=a.lft+b.lft-mn;
        tmp.rgt=a.rgt+b.rgt-mn;
        return tmp;
    }
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    string str;
    cin>>str;

    int len=str.length();

    for(i=0; i<len; i++)
    {
        insert(1, 1, len, i+1, (int)str[i]);
    }

    int q;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        //cout<<lft[a]<<" "<<rgt[a]<<" "<<sum[a]<<endl;
        cout<<2*QUERY(1, 1, len, a, b).sum<<endl;
    }



    return 0;
}

/*

()()(())(())
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

*/
