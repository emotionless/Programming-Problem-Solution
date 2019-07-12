#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    int t;
    cin>>t;
    while(t--)
    {
        string first, second, res;
        int val[15];
        for(i=0; i<15; i++)
        {
            val[i]=10;

        }
        int l=3;
        while(l--)
        {
            cin>>first>>second>>res;
            if(res=="even")
            {
                for(i=0; i<first.length(); i++)
                    val[first[i]-'A']=0;

                for(i=0; i<second.length(); i++)
                    val[second[i]-'A']=0;
            }
            else if(res=="up")
            {
                for(i=0; i<first.length(); i++)
                {
                    if(val[first[i]-'A'])
                        val[first[i]-'A']++;
                }
                for(i=0; i<second.length(); i++)
                {
                    if(val[second[i]-'A'])
                    {
                        val[second[i]-'A']--;
                    }
                }
            }
            else
            {
                for(i=0; i<first.length(); i++)
                {
                    if(val[first[i]-'A'])
                        val[first[i]-'A']--;
                }
                for(i=0; i<second.length(); i++)
                {
                    if(val[second[i]-'A'])
                        val[second[i]-'A']++;
                }
            }
        }
        int mx=0, pos=-1;
        for(i=0; i<12; i++)
        {
            if(val[i]>10)
            {
                printf("%c is the counterfeit coin and it is heavy.\n", 'A'+i);
                pos=1;
                break;
            }
            else if(val[i]<10 && val[i]>6)
            {
                printf("%c is the counterfeit coin and it is light.\n", 'A'+i);
                pos=1;
                break;
            }
        }

    }
    return 0;
}

/*

1
ABCD EFGH even
ABCI EFJK down
ABIJ EFGH even


EBCD AFGH down
GHIJ KABC down
GBKL AIJD down


ABCD EFGH up
GHIJ KABC down
ABKL GIJD down

*/
