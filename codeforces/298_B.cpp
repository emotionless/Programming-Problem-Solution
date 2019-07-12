#include<bits/stdc++.h>

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
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
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


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 200009



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

///***** Template ends here *****///
///********************* Code starts here ****************************

LL arr[MAX];
int t;
int v1, v2;
int d;

int dp[101][10009];


int solve(int ind, int pre)
{
    if(ind == t)
    {
        if(abs(pre - v2) <= d) return v2;
        return -10000000;
    }
    int &ret = dp[ind][pre];
    if(ret != -1) return ret;

    ret = -10000000;

    for(int i = 0; i <= d; i++)
        ret = max(ret, (pre + i) + solve(ind + 1, pre + i));
    for(int i = 0; i <= d; i++)
    {
        if(pre - i >= v2)
            ret = max(ret, (pre - i) + solve(ind + 1, pre - i));
    }
//    cout<<ind<<" "<<pre<<" "<<ret<<endl;
    return ret;
}

struct Z
{
    int xx, yy, val;
};

bool vis[10001][109];
//
//int BT()
//{
//    queue<Z>Q;
//    Z tmp;
//    tmp.xx = v1;
//    tmp.yy = 1;
//    tmp.val = v1;
//    Q.push(tmp);
//    int res = 0;
//
//    while(!Q.empty())
//    {
//        Z top= Q.front();
//        Q.pop();
//        int cn = top.xx;
//        int ct = top.yy;
//        int cv = top.val;
//        if(ct == t)
//        {
//            if(cn == v2) res = max(res, cv);
//            continue;
//        }
//        if(vis[cn][ct]) continue;
//        vis[cn][ct] = 1;
//        for(int i = 0; i <= d; i++)
//        {
//            tmp.xx = cn + i;
//            tmp.yy = ct + 1;
//            tmp.val = cv + cn + i;
//            Q.push(tmp);
//            if(cn - i >= v2)
//            {
//                tmp.xx = cn - i;
//                tmp.yy = ct + 1;
//                tmp.val = cv + cn - i;
//                Q.push(tmp);
//            }
//        }
//    }
//    return res;
//}

int main()
{
    int i, j;
    int num;
    string str;
    int n;
    cin>>v1>>v2;
    cin>>t>>d;
    memset(dp, -1, sizeof dp);

    int res = solve(2, v1) + v1;
//    cout<<BT()<<endl;
    cout<<res<<endl;




    return 0;
}

/*

100 10
90 1

100 91
10 1


*/
