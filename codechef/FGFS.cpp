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
#define PB push_back


using namespace std;

struct Z
{
    LL st, fn;
    LL pl;
    Z() {}
    Z(LL a, LL b, LL c)
    {
        st=a;
        fn=b;
        pl=c;
    }
    bool operator<(const Z& A) const
    {
        if(A.pl==pl)
        {
            if(A.fn==fn) return A.st>st;
            return A.fn>fn;
        }
        return A.pl>pl;
    }
};

inline int solve(vector<Z>V)
{
    int sz=V.size();
    int cnt=1;
    LL pre=V[0].fn;

   //  cout<<V[0].st<<" "<<V[0].fn<<endl;
    for(int i=1; i<sz; i++)
    {
     //    cout<<V[i].st<<" "<<V[i].fn<<endl;
        if(V[i].st>=pre)
        {
            pre=V[i].fn;
            cnt++;
        }
    }
    V.clear();
    return cnt;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k, n;
    LL  q,m, s , f, p;
    int t;
    vector<Z>V, tmp;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %lld", &n, &m);
        V.clear();
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld %lld", &s, &f, &p);
            V.PB(Z(s,f,p));
        }
        sort(V.begin(), V.end());
        int ind=0;
        int res=0;
        tmp.clear();
        for(ind=0; ind<n; )
        {
            tmp.clear();
            for(i=ind; i<n && V[i].pl==V[ind].pl; i++)
            {
                tmp.PB(V[i]);
            }
            res+=solve(tmp);
            ind=i;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*

3 3
1 3 1
4 6 2
7 10 3

*/
