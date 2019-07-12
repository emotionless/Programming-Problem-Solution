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
#define MX 64000+7
#define MOD 1000000000+7
#define PB push_back


using namespace std;

string str1, str2;
int arr[MX];
int N;
double P;

double solve(int ind, int len)
{
    int cnt=arr[ind+len-1]-arr[ind-1];
    double have=((double)cnt*100.0)/(double)len;

    return have;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    int t;

    scanf("%d %lf", &N, &P);

    cin>>str1;
    cin>>str2;
    int tot=N*N*N;
    /*
        int l;

        for(l=1; l>0; l--)
        {
            int len=l, st;
            vector<int>V;
            bool ck=false;
            for(st=0; st+len-1<N; st++)
            {
                int cnt=0;
                for(i=st; i<st+len; i++)
                {
                    for(j=st; j<st+len; j++)
                    {
                        for(k=st; k<st+len; k++)
                        {
                            int ind=i*len*len+j*len+k;
                            cout<<ind<<endl;
                            if(str1[ind]==str2[ind])
                            {
                                cnt++;
                                cout<<ind<<" "<<len<<endl;
                            }
                        }
                    }
                }
                double per=(double)(cnt*100.0)/(double)(l*l*l);
                if(per>=P)
                {
                    ck=true;
                    V.PB(st);
                }
            }
            if(ck)
            {
                //   cout<<l<<endl<<V.size()<<endl;
                break;
            }
        }
        if(l==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    */


    char mat1[45][45][45];
    char mat2[45][45][45];
    int l1=0, l2=0;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            for(k=0; k<N; k++)
            {
                mat1[i][j][k]=str1[l1++];
                mat2[i][j][k]=str2[l2++];
            }
        }
    }
    int l;
    for(l=N; l>0; l--)
    {
        int len=l, st;
        vector<int>V;
        bool ck=false;
        for(st=0; st+len-1<N; st++)
        {
            int cnt=0;
            for(i=st; i<st+len; i++)
            {
                for(j=st; j<st+len; j++)
                {
                    for(k=st; k<st+len; k++)
                    {
                        if(mat1[i][j][k]==mat2[i][j][k])
                            cnt++;
                    }
                }
            }
            double per=(double)(cnt*100.0)/(double)(l*l*l);
            if(per>=P)
            {
                ck=true;
                V.PB(st);
            }
        }
        if(ck)
        {
              cout<<l<<endl<<V.size()<<endl;
            break;
        }
    }
    if(l==0)
    {
        cout<<-1<<endl;
        return 0;
    }


    return 0;
}

/*

1
2 100
abcdefgh
ccccccch

*/
