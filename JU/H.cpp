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
#define LL long long
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MX 120001



using namespace std;

/*

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}




bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
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
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

int arr[65536+10];
int res[20];
int main()
{
    int i,k, j;
    int cases=1;
    int n, m;
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    int tot = round(pow(2.0, (double)n));
    map<int, int>M;
    M.clear();
    for(i = 0; i < tot; i++)
    {
        cin>>arr[i];
        M[arr[i]]++;
    }

    sort(arr, arr + tot);
    k = 2;
    if(n == 1)
    {
        cout<<arr[1]<<endl;
        continue;
    }
    M[arr[0]]--;
    M[arr[1]]--;
    int tmp = arr[2];

    vector<int>save;
    save.clear();
    save.push_back(0);
    save.push_back(arr[1]);
    j = 0;
    int ind = 0;
    res[ind++] = arr[1];
    res[ind++] = arr[2];
    n = n - 2;
    while(n--)
    {
        for(i = 0; i < k; i++)
        {
            int sum = tmp + save[i];
            M[sum]--;
          //  cout<<sum<<endl;
            save.push_back(sum);
        }
        k = save.size();
        for(; j < tot; j++)
        {
            if(M[arr[j]])
            {
                tmp = arr[j];
                res[ind++] = tmp;
                break;
            }
        }
    }
    for(i = 0; i < ind; i++)
    {
        printf("%d", res[i]);
        if(i == ind - 1)
            printf("\n");
        else
            printf(" ");
    }







    }





    return 0;
}
/*


5
0 1 2 3 3 5 6 7 7 8 9 10 5 6 7 8 8 9 10 15  4 5 6 4  11 9 10 11 12 12 13 14


1 2 3 4 5

*/
