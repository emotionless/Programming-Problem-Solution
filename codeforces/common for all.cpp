#include <bits/stdc++.h>

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
#define pll pair<ll, ll>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
#define set_bit(a, b) (a|(1ll<<b))
#define total_bit(a) __builtin_popcount(a)

///**** Max/Min********///

#define _max(aa, bb) (aa = max(aa, bb))
#define max2(aa, bb) max(aa, bb)
#define max3(aa, bb, cc) max(aa, max(bb, cc))
#define max4(aa, bb, cc, fk) max(max(aa, fk), max(bb, cc))
#define _min(aa, bb) (aa = min(aa, bb))
#define min2(aa, bb) min(aa, bb)
#define min3(aa, bb, cc) min(aa, min(bb, cc))
#define min4(aa, bb, cc, dd) min(min(aa, dd), min(bb, cc))


///******* File *********///

#define WRITE freopen("ethan_traverses_a_tree_out.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("ethan_traverses_a_tree.txt","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define nl printf("\n")
#define eps 1e-12
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define PI acos(-1.0)
#define piii pair<int, pii>
#define CLR(aa, nnn) for(int ii = 0; ii <= nnn; ii++) {aa[ii].clear();}

using namespace std;


#define T(a)            cerr << #a << ": " << a << endl;
#define TT(a,b)         cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define TTT(a,b,c)      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define TTTT(a,b,c,d)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;



///******* Template ********///

template <class T> inline T bigmod(T p,T e,T M) {
    if(e==0)
        return 1;
    if(e%2==0) {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b) {
    if(b==0)
        return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M) {
    return bigmod(a,M-2,M);
}

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m) {
    T res = 0;
    a%=m, b%=m;
    while(b) {
        if(b&1)
            res = m - res > a?(res + a): (res + a - m);
        b >>= 1;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)res;
}

void sc(int &a) {
    scanf("%d", &a);
}

void sc(ll &a) {
    scanf("%lld", &a);
}

void sc(double &a) {
    scanf("%lf", &a);
}

void sc(int &a, int &b) {
    scanf("%d %d", &a, &b);
}

void sc(ll &a, ll &b) {
    scanf("%lld %lld", &a, &b);
}

void sc(int &a, int &b, int &c) {
    scanf("%d %d %d", &a, &b, &c);
}


void sc(int &a, int &b, ll &c) {
    scanf("%d %d %lld", &a, &b, &c);
}


void sc(ll &a, ll &b, ll &c) {
    scanf("%lld %lld %lld", &a, &b, &c);
}

void sc(string &str) {
    cin>>str;
}


void sc(char *(str)) {
    scanf(" %s", str);
}

void sc(char &c) {
    scanf(" %c", &c);
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides

//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define LEN(a) strlen(a)
#define ull unsigned long long

#define nl printf("\n")

#define ds(p,q,r,s) sqrt((p-r)*(p-r)+(q-s)*(q-s))
#define INF 10000000000000000ll
#define MX (lim*4 + 10)
#define lim 100000    /// 10^5
#define MAXNUM 1000


///***** Template ends here *****///
///********************* Code starts here ****************************
string str[MAXNUM];
struct Z {
    int st, ed, ind;
    Z() {}
    Z(int _, int __, int ___) {
        st = _;
        ed = __;
        ind = ___;
    }
};

vector<Z> V;

void takeRight(int cnt, int st, int ed) {
    int last = ed + cnt;
    V.resize(last+1);
    for(int i = ed; i >= st; i--) {
        V[i+cnt] = V[i];
    }
    return;
}

void addString(int pos, int len, int ind) {
    int sz = V.size();
    int sum = 0;
    int pre = 0;

    if(sum == pos) {
        takeRight(1, 0, sz - 1);
        V[0] = Z(0, len, ind);
        return;
    }

    for(int i = 0; i < sz; i++) {
        pre = sum;
        sum += (V[i].ed - V[i].st + 1);
//        cout<<sum<<endl;
        if(sum == pos) {
            takeRight(1, i+1, sz - 1);
            V[i+1] = Z(0, len, ind);
            return;
        } else if(sum > pos) {
            takeRight(2, i+1, sz - 1);
            int point = pos - pre;
            int st = V[i].st, ed = V[i].ed, id = V[i].ind;
            V[i] = Z(st, point - 1, id);
            V[i+1] = Z(0, len, ind);
            V[i+2] = Z(point, ed, id);
//            cout<<point<<" sdf "<<endl;
            return;
        }
    }
    V.pb(Z(0, len, ind));

    return;
}

int deleteTill(int ind, int have) {
    int sz = V.size();
    for(int i = ind; i < sz; i++) {
        int now = V[i].ed - V[i].st + 1;
        if(now <= have) {
            have -= now;
        } else {
            V[i].st += have;
            return i;
        }
    }
    return sz;
}

void copyInto(int to, int from) {
    int sz = V.size();
    int cnt = 0;
    for(int i = from; i < sz; i++) {
        V[to+cnt] = V[i];
        cnt++;
    }
    V.resize(to+cnt);

    return;
}

void deleteString(int pos, int len) {
    int sz = V.size();
    int sum = 0;
    int pre = 0;

    if(sum == pos) {
        int get = deleteTill(0, len);
        copyInto(0, get);
        return;
    }

    for(int i = 0; i < sz; i++) {
        pre = sum;
        sum += (V[i].ed - V[i].st + 1);
//        cout<<sum<<endl;
        if(sum == pos) {
            int get = deleteTill(i+1, len);
            copyInto(i+1, get);
            return;
        } else if(sum > pos) {
            int point = pos - pre;
            int st = V[i].st, ed = V[i].ed, id = V[i].ind;
            int cur = (ed - point + 1);
            if (len == cur) {
                V[i] = Z(st, point - 1, id);
            }
            else if(len < cur) {
                V[i] = Z(st, point - 1, id);
                takeRight(1, i+1, sz - 1);
                int nxt = point + len;
                V[i+1] = Z(nxt, ed, id);
            } else {
                int get = deleteTill(i+1, len - cur);
                copyInto(i+1, get);
                V[i] = Z(st, point - 1, id);
            }
//            V[i] = Z(st, point - 1, id);
//            V[i+1] = Z(0, len, ind);
//            V[i+2] = Z(point, ed, id);
//            cout<<point<<" sdf "<<endl;
            return;
        }
    }

    return;
}

void print() {
    int sz = V.size();
    for(int i = 0; i < sz; i++) {
        int st = V[i].st;
        int ed = V[i].ed;
        int ind = V[i].ind;
        for(int j = st; j <= ed; j++) {
            cout<<str[ind][j];
        }
    }
    cout<<endl;
}

int main() {
    int i, t, cases = 1, j, k, pos;

    int ind = 0;
    cin>>str[++ind];
    addString(0, str[ind].length() - 1, ind);
    int q;
    cin>>q;
    while(q--) {
        int op;
        cin>>op;
        if(op == 1) {
            cin>>pos>>str[++ind];
            addString(pos, str[ind].length() - 1, ind);
        } else if(op == 2) {
            int len;
            cin>>pos>>len;
            deleteString(pos, len);
        } else {
            print();
        }
    }


    return 0;
}

/*

ABCDefg
4
1 0 MILON
1 5 FARUK
1 17 HOSSAIN
3

*/
