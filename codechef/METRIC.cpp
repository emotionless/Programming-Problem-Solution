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

long long arr[1001];
long long res[1001];

/*
a,b,c is <=10^18
(all operation is by mod c)
res=(a*b)%c
so, a*b=(2*a)*(b/2) // if b is even
and a*b=a+(2*a)*((b-1)/2) // if b is odd
and 0 if b is 0
// src topcoder.com
*/

LL modulo_op(LL a, LL b, LL c)
{
    LL res=0LL, tmp=a;
    LL x=b;
    b=abs(b);
    while(b>0)
    {
        if(b%2==1)
        {
            res=(res+tmp)%c;
        }
        tmp=(2*tmp)%c;
        b=b/2;
    }
    if(x<0)
        res=((-1LL)*res+c)%c;
    return res;
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    int t;
    string str;
    long long A,B,C;
    scanf("%d", &t);
    while(t--)
    {
        memset(arr, 0, sizeof arr);
        scanf("%d", &n);
        for(i=0; i<n; i++)
            cin>>arr[i];

        cin>>A>>B>>C;
        A=A%C;
        B=B%C;
        cin>>str;
        LL save=arr[0];
        for(i=0; i<n; i++)
        {
            arr[i]=arr[i]%C;
            if(i==0)
            {
                if(str[i]=='M')
                    res[i]=modulo_op(arr[i],B,C);
                else if(str[i]=='A')
                    res[i]=((arr[i]%C)+(A%C))%C;
                else
                    res[i]=arr[i]%C;
                // cout<<res[i]<<endl;
                continue;
            }
            if(str[i]=='M')
                res[i]=modulo_op(res[i-1],B,C);
            else if(str[i]=='A')
                res[i]=((res[i-1]%C)+A)%C;
            else
                res[i]=res[i-1];
            // cout<<i<<" "<<res[i]<<endl;
        }
        LL mul=1LL;
        for(i=0; i<n; i++)
        {
            if(str[i]=='M')
            {
                mul=modulo_op(mul,B,C);
            }
            if(str[i]=='R')
            {
                j=n-1;
                k=i;
                while(k<j)
                {
                    LL tmp=arr[k];
                    arr[k]=arr[j];
                    arr[j]=tmp;
                    k++;
                    j--;
                }
            }

            LL a=arr[i];
            LL x=save;
         //   cout<<a<<" "<<x<<" "<<res[i]<<" ";
            LL tmp=(modulo_op(mul,(a-x),C) + res[i]%C)%C;

            cout<<tmp;
            if(i<n-1)
                cout<<" ";
            else
                cout<<endl;
        }
    }
    return 0;
}

/*

3
1 2 3
4 5 1000000007
RMA

4
1 2 3 4
1 2 3
RAMA




2
1000000000000000000 1000000000000000000
2 1000000000000000000 99999999999999999
MM

4
1 2 3 4
2 3 17
AMAM
10
1 2 3 4 5 6 7 8 9 10
2 5 3
MMRRRRRRRR

*/
