#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
vector<int>v;
int main()
{
    int test,i,j,k,l,M,N,K,cnt;
    string s;
    cin>>test;
    while(test--)
    {
        cin>>M>>N>>K;
        cnt=0;
        int total=0;
        for(i=0; i<M; i++)
        {
            cin>>s;
            int off=0,on=0;
            for(j=0; j<N; j++)
            {
                if(s[j]=='.') off++;
                else
                {
                    total++;
                    on++;
                }
            }
            if(off>on)
            {
                v.push_back(off);
            }
        }
        //cout<<total<<endl;
        sort(v.begin(),v.end());
        //cout<<"c "<<v[0]<<endl;
        int len=v.size();
        //cout<<len<<endl;
        if(K<=len)
        {
          //  cout<<len-K<<endl;
            for(i=len-1; i>=len-K; i--)
            {
                total+=(v[i]-(N-v[i]));
            //    cout<<"l "<<total<<" "<<v[i]<<" "<<(N-v[i])<<endl;
            }
            //cout<<"1 "<<total<<endl;
        }
        else
        {
            for(i=1;i<len;i++)
            {
                total+=(v[i]-(N-v[i]));
            }
        //    cout<<"2 "<<total<<endl;
            K=K-len+1;
          //  cout<<"k "<<K<<endl;
            if(K%2==1) total+=(v[0]-(N-v[0]));
        }
        cout<<total<<endl;
        v.clear();
    }
    return 0;
}
/*
4
4 3 2
...
..*
*.*
.**
*/
