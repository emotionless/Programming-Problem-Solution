#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

using namespace std;
#define inf INT_MAX
#define pi 2*acos(0.0)
#define mod 1000000000

int main()
{
    string in;
    string tmp;
    char c='"',sp=' ';
    int a,b,i,j,o,k,len1,len2;
    getline(cin,in);
//        int ar[100005];
//        for(i=0;i<len1;i++)
//        {
//                if(in[i]==c)
//                        ar[i]=1;
//        }
    len1=in.length();
    for(i=0; i<len1;)
    {
        if(in[i]==c)
        {
            printf("<");
            for(j=i+1; j<len1; j++)
            {
                if(in[j]==c)
                {
                    printf(">\n");
                    i=j+1;
                    break;
                }
                else
                {
                    printf("%c",in[j]);
                }
            }
        }
        else if(in[i]!=sp)
        {
            printf("<");
            for(j=i; j<len1; j++)
            {
                if(in[j]==sp)
                {
                    printf(">\n");
                    i=j+1;
                    break;
                }
                else
                {
                    printf("%c",in[j]);
                }
            }
        }
        else
            i++;
    }
    return 0;
}
