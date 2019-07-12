#include <bits/stdc++.h>

#define LL long long
#define MAX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

bool is_prime[MAX];
LL prime[MAX];
bool vis[MAX];
bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i = 4; i < MAX; i += 2)
        is_prime[i] = 1;
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
}

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;
    int a, b, h, m, n;
    sieve();
    cin>>n;
    vi res, V;

    for(i = n / 2; i >=2; i--)
    {
        if(is_prime[i]) continue;
        V.clear();
        for(j = i; j <= n; j = j + i)
        {
            if(!vis[j])
                V.PB(j);
        }
        int sz = V.size();
        if(sz & 1)
        {
            for(j = 0; j < sz; j++)
            {
                if(V[j] % 2 == 0)
                {
                    swap(V[j], V.back());
                    V.pop_back();
                    sz--;
                    break;
                }
            }
        }
        for(j = 0; j < sz ; j+=2)
        {

            //cout<<V[j]<<" "<<V[j + 1]<<endl;
            res.PB(V[j]);
            res.PB(V[1 + j]);
            vis[V[j]] = 1;
            vis[V[1 + j]] = 1;
        }
    }
    int sz = res.size();
    cout<< sz / 2 << endl;
    for(i = 0; i < sz; i += 2)
        cout<<res[i] <<" "<<res[i + 1]<<endl;


    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
