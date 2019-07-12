#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;



int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    bool is[]={1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0};

    string str;
    cin>>str;
    int l=str.length();
    j=l-1;
    for(i=0; i<l && i<=j; i++)
    {
        if(str[i]==str[j] && is[ str[i]-'A']==1);
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
        j--;
    }
    cout<<"YES"<<endl;



    return 0;
}

/*

4544545454

*/
