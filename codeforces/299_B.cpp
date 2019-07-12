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
#define MAX 1000009



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


bool arr[MAX];
int val[MAX];

void Failure(string check, int F[], int m)
{
    int i=1,j=0;
    F[0]=0;
    while(i<m)
    {
        if(check[i]==check[j])
        {
            F[i]=j+1;
            i++;
            j++;
        }
        else if(j>0)
        {
            j=F[j-1];
        }
        else
        {
            F[i]=0;
            i++;
        }
    }
}

bool match[1000009];

int KMP(string input, string check)
{
    int i,j,k;
    i=j=0;
    int F[1000009];
    int m=check.length();
    int n=input.length();
    Failure(check,F,m);
    while(i<n)
    {
        if(input[i]==check[j])
        {
            if(j==m-1){

                i++;
                match[i-j -1] = 1;
                j = F[j];
                val[i-1] = j;
            }
            else
            {
                val[i] = j + 1;
                i++;
                j++;
            }
        }
        else if(j>0)
            j=F[j-1];
        else
            val[i] = 0, i++;
    }
    return -1;
}


int main()
{
    int i, j, k;
    string str;
    int t, n, m;
    cin>>n>>m;
    cin>>str;
    int num;
    int len = str.length();
    fr(i, m)
    {
        cin>>num;
        num--;
        arr[num] = 1;
    }
    string tmp = "";
    int s = len;
    for(i = 0; i < n; i++)
    {
        if(arr[i]) s = 0;
        if(s < len)
            tmp += str[s++];
        else
            tmp += '#';
    }
    KMP(tmp, str);
    int cnt = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i])
        {
            if(!match[i])
            {
                cout<<0<<endl;
                return 0;
            }
        }
        if(tmp[i] == '#')
            cnt++;
    }
    cout<<bigmod(26ll, (LL)cnt, (LL)MOD)<<endl;









    return 0;
}

/*


6 1
ioi
 2


*/
