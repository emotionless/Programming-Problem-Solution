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


#define inp(a) scanf("%d", &a)
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100000009



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




int main()
{
    int i, j, k;
    string str;
    LL t, n;
    LL m;
    cin>>n;
    cin>>m;
    vector<LL>vec;
    fr(i, n)
    {
        cin>>t;
        vec.pb(t);
    }
    sort(vec.begin(), vec.end());
    LL sum = 0;
    for(i = 0; i < n; i++)
    {

        for(j = i; j < n; j++)
        {
            if(vec[j] != vec[i]) break;
        }

        LL tot = j - i;
        LL st = 0, ed = n - 1;
        LL mid, ans = -1;
        while(st <= ed)
        {
            mid = (st + ed)/2;
            if((mid + 1) * tot + sum >= m)
            {
                ed = mid - 1;
            }
            else
            {
                ans = max(ans, mid);
                st = mid + 1;
            }
        }
        sum += (ans+1)*tot;
//        cout<<i<<" "<<sum<<" "<<ans<<endl;
        if(ed < n - 1)
        {

//            cout<<i<<" "<<sum<<" "<<ans<<endl;
            cout<<vec[i]<<" "<<vec[ans + 1]<<endl;
            return 0;
        }
        if(ans == n - 1 && sum == m)
        {
//            cout<<"here"<<endl;
            cout<<vec[i]<<" "<<vec[n-1]<<endl;
            return 0;
        }
        i = j - 1;

    }
//    cout<<vec[i]<<" "<<vec[m - sum-1]<<endl;








    return 0;
}

/*
3 3
1 3 2

*/
