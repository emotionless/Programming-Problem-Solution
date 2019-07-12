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

#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO

#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);

#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9


#define deb cout<<"I am here"<<endl


#define MOD 1000000007
#define MAX 109



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

#define MX 1000000000000000000ll

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

bool mat[10009][109];
string strr[109];

int main()
{
//    READ;
//    WRITE;
//    use_cin;


    int i, j, k;
    int n, m;
    string str, tmp;
    int tc;
    vector<string>ans;
    while(scanf("%d", &n)== 1)
    {
        getchar();
        map<string, int>M, MP;
        M.clear();
        MP.clear();
        k = 0;
        clr(mat, false);
        for(i = 1; i <= n; i++)
        {
            cin>>str;
            getchar();
//        cout<<str<<endl;
            M[str] = i;
            getline(cin, strr[i]);
//        cout<<str<<endl;
            stringstream ss;
            ss.clear();
            ss<<strr[i];
            while(ss>>tmp)
            {
                if(!MP[tmp])
                    MP[tmp] = (++k);
                int id = MP[tmp];
                mat[id][i] = 1;
            }
        }
        if(k >= 10009)
            assert(0);
        int t;
        scanf("%d", &t);
            getchar();
        int arr[202];
        while(t--)
        {
            getline(cin, str);
//            getchar();

            stringstream ss;
            ss.clear();
            ss<<str;
            k = 1;
            while(ss >> tmp)
            {
                arr[k++] = M[tmp];
            }
            int id = arr[k - 1];
            ss.clear();
            ss<<strr[id];
            ans.clear();
            while(ss >> tmp)
            {
                int line_id = MP[tmp];
                int cnt = 0;
                for(i = 1; i < k; i++)
                {
                    if(mat[line_id][ arr[i] ])
                        cnt++;
                }
                if(cnt == k - 1)
                    ans.pb(tmp);
            }
            int sz = ans.size();
            if(sz == 0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            sort(ans.begin(), ans.end());
            for(i = 0; i < sz; i++)
            {
                if(i) cout<<" ";
                cout<<ans[i];
            }
            cout<<endl;
            ans.clear();
        }

    }


    return 0;
}
/*


4
fish
agile animal a
horse
swift animal a
eagle
fierce animal a
Kyuubee
alien incubator
2
fish horse eagle
fish horse eagle Kyuubee

*/
