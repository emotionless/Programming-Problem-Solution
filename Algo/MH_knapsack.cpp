#include<bits/stdc++.h>


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
#define ll int
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("semipal.out","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("semipal.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define sp printf(" ")
#define nl printf("\n")
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MAX (lim+2)
#define INF 1000000000000000ll
#define PI acos(-1.0)
#define piii pair<int, pii>

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

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)
#define ull unsigned long long

#define MX 10000000000000ll
#define MOD 1000000007
#define lim 5000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************




int main()
{
    int j,  i;
    int w[8] = {4, 128, 32, 1, 8, 2, 16, 64}; // can be any random numbers power.
    int B[8];
    int encrypted[10], ind = 0;
    int n = 8; // as we took 8 numbers
    int sum = 0; // summation
    for(i = 0; i < n; i++)
    {
        sum = sum + w[i];
    }
    int q = 287; // greater than sum
    int r = 3; // any number which is co-prime of q
    for(i = 0; i < n; i++)
        B[i] = (w[i]*r)%q;
    printf("Public key sequence is:");
    for(i = 0; i < n; i++)
        printf(" %d", B[i]);
    printf("\n");

    /// encryption

    char inp;
    printf("Enter a single character to test: ");
    scanf("%c", &inp);
    int message = inp;
    int MH_encrypted_message = 0;

    for(i = 7; i >= 0; i--)
    {
        if((message&(1<<i)))
        {
            MH_encrypted_message += B[n-i-1];
        }
    }
    printf("Markle-Hellman encrypted message is: %d\n", MH_encrypted_message);
    // for base conversion...
    int base = 13;
    while(MH_encrypted_message > 0)
    {
        encrypted[ind++] = (MH_encrypted_message) % base;
        MH_encrypted_message /= base;
    }
    reverse(encrypted, encrypted + ind);

    printf("Private keys are:  r = %d, q = %d, b = %d\n", r, q, base);
    printf("Private sequence is:");
    for(i = 0; i < n; i++)
        printf(" %d", w[i]);
    printf("\n");
    printf("Encrypted message is: " );
    for(i = 0; i < ind; i++)
        printf("%d", encrypted[i]);
    printf("\n");

    /// decryption

    reverse(encrypted, encrypted + ind);

    int decrypt_MH_encrypted_message = 0;
    for(i = 0; i < ind; i++)
    {
        decrypt_MH_encrypted_message += encrypted[i]*(round(pow(base, i)));
    }
    printf("During decrypt, MH encrypted message is: %d\n", decrypt_MH_encrypted_message);

    int modular_inverse = 96;    // modular multiplicative inverse of r with mod q
    printf("Modular multiplicative inverse of r is: %d\n", modular_inverse);

    // so, now value of c = (modular_inverse * decrypt_MH_encrypted_message) % q;
    int c = (modular_inverse * decrypt_MH_encrypted_message) % q;


    // use meet-in-the-middle
    int firstHalf = n/2;
    map<int, int>store;


    for(i = 0; i < (1<<firstHalf); i++)
    {
        int sum = 0;
        for(j = 0; j < firstHalf; j++)
        {
            if(i&(1<<j))
                sum += w[firstHalf - j - 1];
        }
        store[sum] = i;
    }
    int st = (1<<firstHalf);
    int first_part_size = firstHalf;
    int last_part_size = n-firstHalf;
    int total_size = n;
    n = n - firstHalf;
    for(i = 0; i < (1<<n); i++)
    {
        int sum = 0;
        for(j = 0; j < n; j++)
        {
            if(i&(1<<j))
            {
                sum += w[total_size-j-1];
            }
        }
        int rest = c-sum;
        if(rest < 0) continue;
        if(store[rest])
        {
            int num = store[rest];
            int ans = (num << last_part_size) + i;
            printf("Found ASCI value is %d and message is '%c'\n", ans, (char)ans);
            break;
        }
    }

    return 0;
}

/*


1
ABC
ABC


*/
