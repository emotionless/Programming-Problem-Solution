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
#define ll long long
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
#define MAX 1000009
#define inf 1e9
#define deb cout<<"I am here\n"



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


ll seg[MAX];


void build(int ind, int st, int ed)
{
    if(st == ed)
    {
        seg[ind] = inf;
        return;
    }
    int mid = (st + ed)/2;
    build(ind * 2, st, mid);
    build(ind * 2 + 1, mid + 1, ed);

    seg[ind] = min(seg[ind * 2], seg[ind * 2 + 1]);
    return;
}

void update(int ind, int st, int ed, int pos, ll val)
{
    if(st == ed)
    {
        seg[ind] = min(seg[ind], val);
        return;
    }
    int mid= (st + ed)/2;
    if(pos <= mid)
        update(ind * 2, st, mid, pos, val);
    else
        update(ind * 2 + 1, mid + 1, ed, pos, val);

    seg[ind] = min(seg[ind * 2] , seg[ind * 2 + 1]);
}

ll query(int ind, int st, int ed, int l, int r)
{
    if(l > r) return inf;
    if(st == l && ed == r) return seg[ind];
    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind * 2, st, mid, l, r);
    else if(l > mid)
        return query(ind * 2 + 1, mid + 1, ed, l, r);
    else
        return min(query(ind * 2, st, mid, l, mid) , query(ind * 2 + 1, mid + 1, ed, mid + 1, r));
}


ll arr[MAX];
ll save[MAX];
ll go[MAX];

int main()
{
    ll i, j;
    string str;
    ll t,n, m, u, v;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
        save[i] = arr[i];
    }
    ll k = 0;
    map<ll, ll>M;
    sort(arr, arr + n);
    for(i = 0; i < n; i++)
    {
        if(arr[i] == arr[i - 1])
            continue;
        M[arr[i]] = (++k);
    }
    ll cnt = 0;

    build(1, 1, k + 1);

//    for(i = 1; i <= 16; i++)
//        cout<<i<<" "<<seg[i]<<endl;

    for(i = 0; i < n; i++)
    {
        ll mpInd = M[ save[i] ];
        ll getInd = query(1, 1, k + 1, mpInd, k);
//        cout<<i<<" "<<mpInd<<" "<<getInd<<endl;
        if(getInd == inf)
        {
            go[i] = i;
//            cnt++;
        }
        else
            go[i] = getInd;
        update(1, 1, k + 1, mpInd, i);
    }
    ll mn = inf, tot = 0, pre = 0;

//    for(i = 0; i < n; i++)
//        cout<<i<<" "<<go[i]<<endl;

    bool ck = 0;

    for(i = n - 1; i >= 0; i--)
    {
        mn = go[i];
        j = i;
        bool is = 0;
        while(mn <= j)
        {
            mn = min(mn, go[j]);
            if(M[ save[j] ] < M[save[j + 1]] && j < i)
            {
                is = 1;
//                cout<<j<< " bal"<<endl;
            }
            j--;
        }
//        cout<<i<< " "<<j<<endl;
        if((j+1) == i)
            tot++;
        else
        {
//            cout<<is<<endl;
            if(!is && (i - j)>=3)
            {
                ck = 1;
                is = 0;
//                cout<<i<<endl;
            }
        }
        cnt++;
        i = j+1;
    }

//    cout<<cnt<<" "<<tot<<endl;

    ll dep = cnt - tot;
    ll indep = tot;

    ll depp = bigmod(2ll, dep, (ll)MOD) % MOD;
    ll indepp = bigmod(2ll, indep, (ll)MOD) % MOD;
//    cout<<dep<<" "<<indep<<endl;
    if(ck)
        cout<<0<<endl;
    else
        cout<<(depp*indepp)%MOD<<endl;







    return 0;
}


/*


5
1 3 2 5 4

2
1 2

3
3 2 1


4
3 4 2 1

3
4 4 4

4
5 4 4 4

*/
