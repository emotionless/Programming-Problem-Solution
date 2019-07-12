#include <bits/stdc++.h>

#define LL long long
#define MAX 100099
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;



bool is_prime[MAX];
vector<int> prime;

bool sieve()
{
    long i,j;
    prime.PB(2);
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime.PB(j);
        }
    }
}
vector<int> ret;
void BS(int src)
{
    int sz=prime.size();
    if(src==1) return;
    for(int i=0; i<sz; i++)
    {
        if(prime[i]>src)
        {
            ret.PB(prime[i-1]);
            BS(src-prime[i-1]+1);
            return;
        }
    }
}

int arr[MAX];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    sieve();
    int n, m, u,v;


    cin>>n;
    map<int, int>M;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
        M[arr[i]]=i;
    }
    vector<int>res;
    for(i=n; i>0; i--)
    {
        int cn=arr[i];
        if(cn!=i)
        {
            int src=M[i];
            int dif=i-src+1;
            BS(dif);
           // cout<<dif<<endl;
            int sz=ret.size();
            for(j=0; j<sz; j++)
            {
                //cout<<src<<" "<<src+ret[j]-1<<endl;
                res.PB(src);
                res.PB(src+ret[j]-1);
                swap(arr[src], arr[src+ret[j]-1]);
                swap(M[arr[src]], M[arr[src+ret[j]-1]]);
                src=src+ret[j]-1;

            }
            ret.clear();
            //break;
        }
    }
    int sz=res.size();
    cout<<sz/2<<endl;
    for(i=0; i<sz; i+=2)
        cout<<res[i]<<" "<<res[i+1]<<endl;





    return 0;
}

/*

15
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
11 10
12 11
13 12
14 13
15 14
0 1 0 0 1 1 1 1 1 1 0 0 0 1 1
1 1 1 1 0 0 1 1 0 1 0 0 1 1 0


*/