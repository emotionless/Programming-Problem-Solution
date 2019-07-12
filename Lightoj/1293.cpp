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
#define MAX 50009



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

int val[MAX];
int M[MAX];
int k;
int n;
int check(int num)
{
    memset(M, 0, sizeof M);
    int p = 0;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(M[val[i]] == 0)
        {
            M[val[i]]++;
            p++;
        }
        else
            M[val[i]]++;

        if(i - j == num)
        {
            int ind = j;
            M[val[ind]]--;
            if(M[val[ind]] == 0)
                p--;
            j++;
        }
//        cout<<i<<" "<<j<<" "<<p<<endl;
        if(p == k)
        {
            return i;
        }

    }
    return -1;
}


int main()
{
//    READ;
//    WRITE;
    int i, j;
    string str, tmp, inp;
    int t;
    int cases = 1;
    int num, m;
    int a, b, c;
    scanf("%d", &t);
    getchar();

    stringstream ss;
    map<string, int >MP;
    while(t--)
    {
        str = "";
        while(1)
        {
            getline(cin, inp);
            if(inp == "END") break;
            str += " "+inp;
        }
        int len = str.length();
        for(i = 0; i < len; i++)
        {
            if(!isalpha(str[i]))
                str[i] = ' ';
        }
        ss.clear();
        MP.clear();
        ss<<str;
        i = 0;
        k = 0;
        while(ss >> tmp)
        {
            if(MP.find(tmp) == MP.end())
            {
                MP[tmp] = (++k);
            }
            val[i++] = MP[tmp];
        }
        n = i;
        int st = 0, ed = n, mid;
        int ans1 = 0, ans2 = 0;
        while(st <= ed)
        {
            mid = (st + ed)/2;
//            cout<<"When: "<<mid<<endl;
            int get = check(mid);
            if(get != -1)
            {
                ans1 = get;
                ans2 = get - mid + 1;
                ed = mid - 1;
            }
            else
                st = mid + 1;
        }
        printf("Case %d: %d %d\n", cases++, ans2 + 1, ans1 + 1);
    }
    return 0;
}

/*

10 5
4 4 5 8 8

1 2 3 4
1 4 3 2
2 4 3 1

*/
