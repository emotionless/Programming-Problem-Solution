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
    LL st, ed;
    Z(){}
    Z(LL a, LL b)
    {
        st=a;
        ed=b;
    }
};

vector<Z>V;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    LL l,c;
    int n, op;
    cin>>n;
    LL ind=0;
    for(i=0; i<n; i++)
    {
        cin>>op;
        if(op==1)
        {
            V.PB(Z(ind, ind));
            ind++;
        }
        else
        {
            cin>>l>>c;

            LL tot=l*c;
            V.PB(Z(ind, ind+tot-1));
            ind=ind+tot-1;
        }
    }

    for(i=0; i<V.size(); i++)
    {
        cout<<V[i].st<<" "<<V[i].ed<<endl;
    }




    return 0;
}

/*

4544545454

*/
