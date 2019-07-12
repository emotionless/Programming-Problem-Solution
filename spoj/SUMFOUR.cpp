#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second
#define pi pair<int, int>
#define mp make_pair
#define fr(i,a) for(i = 0; i < a; i++)
#define sc(a) scanf("%d", &a)

///***** Constant ******//
#define MX 10007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 4009        // 10^5 + 7
#define ll long long
#define prime 15485863

using namespace std;

int A[N];
int B[N];
int C[N];
int D[N];
int tabl[16000010];
int val[16000010];

void insert(int a)
{
    int key = (a%prime + prime)%prime;
    while(val[key] > 0 && tabl[key] != a) key = (key + 1)%prime;
    tabl[key] = a;
    val[key]++;
}

int search(int a)
{
    int key = (a%prime + prime)%prime;
    while(val[key] > 0 && tabl[key] != a) key = (key + 1)%prime;
    return val[key];
}


vector<int> store;
int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int n, m;
    scanf("%d", &n);

    fr(i, n)
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);

//    map<int, bool>M;
    k = 0;
    fr(i, n)
    {
        fr(j, n)
        {
            insert(A[i] + B[j]);
        }
    }
    int cnt = 0ll;
    fr(i, n)
    {
        fr(j, n)
        {
            int val = -(C[i] + D[j]);
            cnt += search(val);

        }
    }
    printf("%d\n", cnt);

    return 0;
}
/*



*/
