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
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\emotionless\\Desktop\\output.txt","w",stdout)
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

/// BigInteger

struct Bigint
{
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise

    Bigint() {} // default constructor
    Bigint( string b )
    {
        (*this) = b;    // constructor for string
    }
    Bigint( long long num )
    {
        if(num < 0) sign = -1;
        else sign = 1;
        if(num == 0)  a.push_back('0');
        while(num)
        {
            a.push_back( num % 10 + '0');
            num /= 10;
        }
    } // constructor for string

    int size()   // returns number of digits
    {
        return a.size();
    }
    Bigint inverseSign()   // changes the sign
    {
        sign *= -1;
        return (*this);
    }

    Bigint normalize( int newSign )   // removes leading 0, fixes sign
    {
        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
            a.erase(a.begin() + i);
        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }

    void operator = ( string b )   // assigns a string to Bigint
    {
        a = b[0] == '-' ? b.substr(1) : b;
        reverse( a.begin(), a.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
    }

    bool operator < ( const Bigint &b ) const   // less than operator
    {
        if( sign != b.sign ) return sign < b.sign;
        if( a.size() != b.a.size() )
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )
                return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator == ( const Bigint &b ) const   // operator for equality
    {
        return a == b.a && sign == b.sign;
    }

    Bigint operator + ( Bigint b )   // addition operator overloading
    {
        if( sign != b.sign ) return (*this) - b.inverseSign();
        Bigint c;
        for(int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++ )
        {
            carry += (i < a.size() ? a[i] - 48 : 0) + (i < b.a.size() ? b.a[i] - 48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator - ( Bigint b )   // subtraction operator overloading
    {
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign;
        sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ )
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator * ( Bigint b )   // multiplication operator overloading
    {

        int MAXN = a.size() + b.size() + 5;
        int tmp[MAXN];

        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < a.size(); i++)
            for(int j = 0, p = i; j < b.size(); j++)
            {
                tmp[p++] += (a[i] - '0') * (b.a[j] - '0');
            }

        Bigint c;
        for(int i = 0; i < MAXN - 1; i++)
        {
            tmp[i + 1] += tmp[i] / 10;
            tmp[i] %= 10;
            c.a.push_back(tmp[i] + '0');
        }
        return c.normalize(sign * b.sign);
    }
    Bigint operator / ( Bigint b )   // division operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0"), d;
        for( int j = 0; j < a.size(); j++ ) d.a += "0";
        int dSign = sign * b.sign;
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator % ( Bigint b )   // modulo operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0");
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');

            struct Bigint
            {
                string a; // to store the digits
                int sign; // sign = -1 for negative numbers, sign = 1 otherwise

                Bigint() {} // default constructor
                Bigint( string b )
                {
                    (*this) = b;    // constructor for string
                }
                Bigint( long long num )
                {
                    if(num < 0) sign = -1;
                    else sign = 1;
                    if(num == 0)  a.push_back('0');
                    while(num)
                    {
                        a.push_back( num % 10 + '0');
                        num /= 10;
                    }
                } // constructor for string

                int size()   // returns number of digits
                {
                    return a.size();
                }
                Bigint inverseSign()   // changes the sign
                {
                    sign *= -1;
                    return (*this);
                }

                Bigint normalize( int newSign )   // removes leading 0, fixes sign
                {
                    for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
                        a.erase(a.begin() + i);
                    sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
                    return (*this);
                }

                void operator = ( string b )   // assigns a string to Bigint
                {
                    a = b[0] == '-' ? b.substr(1) : b;
                    reverse( a.begin(), a.end() );
                    this->normalize( b[0] == '-' ? -1 : 1 );
                }

                bool operator < ( const Bigint &b ) const   // less than operator
                {
                    if( sign != b.sign ) return sign < b.sign;
                    if( a.size() != b.a.size() )
                        return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
                    for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )
                            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
                    return false;
                }
                bool operator == ( const Bigint &b ) const   // operator for equality
                {
                    return a == b.a && sign == b.sign;
                }

                Bigint operator + ( Bigint b )   // addition operator overloading
                {
                    if( sign != b.sign ) return (*this) - b.inverseSign();
                    Bigint c;
                    for(int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++ )
                    {
                        carry += (i < a.size() ? a[i] - 48 : 0) + (i < b.a.size() ? b.a[i] - 48 : 0);
                        c.a += (carry % 10 + 48);
                        carry /= 10;
                    }
                    return c.normalize(sign);
                }
                Bigint operator - ( Bigint b )   // subtraction operator overloading
                {
                    if( sign != b.sign ) return (*this) + b.inverseSign();
                    int s = sign;
                    sign = b.sign = 1;
                    if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
                    Bigint c;
                    for( int i = 0, borrow = 0; i < a.size(); i++ )
                    {
                        borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
                        c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
                        borrow = borrow >= 0 ? 0 : 1;
                    }
                    return c.normalize(s);
                }
                Bigint operator * ( Bigint b )   // multiplication operator overloading
                {

                    int MAXN = a.size() + b.size() + 5;
                    int tmp[MAXN];

                    memset(tmp, 0, sizeof(tmp));
                    for(int i = 0; i < a.size(); i++)
                        for(int j = 0, p = i; j < b.size(); j++)
                        {
                            tmp[p++] += (a[i] - '0') * (b.a[j] - '0');
                        }

                    Bigint c;
                    for(int i = 0; i < MAXN - 1; i++)
                    {
                        tmp[i + 1] += tmp[i] / 10;
                        tmp[i] %= 10;
                        c.a.push_back(tmp[i] + '0');
                    }
                    return c.normalize(sign * b.sign);
                }
                Bigint operator / ( Bigint b )   // division operator overloading
                {
                    if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
                    Bigint c("0"), d;
                    for( int j = 0; j < a.size(); j++ ) d.a += "0";
                    int dSign = sign * b.sign;
                    b.sign = 1;
                    for( int i = a.size() - 1; i >= 0; i-- )
                    {
                        c.a.insert( c.a.begin(), '0');
                        c = c + a.substr( i, 1 );
                        while( !( c < b ) ) c = c - b, d.a[i]++;
                    }
                    return d.normalize(dSign);
                }
                Bigint operator % ( Bigint b )   // modulo operator overloading
                {
                    if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
                    Bigint c("0");
                    b.sign = 1;
                    for( int i = a.size() - 1; i >= 0; i-- )
                    {
                        c.a.insert( c.a.begin(), '0');
                        c = c + a.substr( i, 1 );
                        while( !( c < b ) ) c = c - b;
                    }
                    return c.normalize(sign);
                }

                void print()
                {
                    if( sign == -1 ) putchar('-');
                    for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
                    puts("");
                }
            };

            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }

    void print()
    {
        if( sign == -1 ) putchar('-');
        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
        puts("");
    }
};






/// ends here



///***** Template ends here *****///
///********************* Code starts here ****************************

string str;

int dp[1001][1001][2];
int mx;
int solve(int i, int j, bool is)
{
    int &ret = dp[i][j][is];
    if(i > j) return ret = 0;
    if(i == j) return ret = 1;
    if(ret != -1) return ret;
    ret = 0;
    if(is)
    {
        if(str[i] == str[j])
        {
            ret = 2 + solve(i + 1, j - 1, 1);
        }
        else
        {
            ret = solve(i + 1, j, 0);
            ret = max(ret, solve(i, j - 1, 0));
        }
    }
    else
    {
        ret = max(ret, (str[i] == str[j]?2:0) + solve(i + 1, j - 1, str[i] == str[j]));
        ret = max(ret, solve(i + 1, j, 0));
        ret = max(ret, solve(i, j - 1, 0));
    }
    if(j - i + 1 != ret)
        ret = 0;
    mx = max(ret, mx);
    return ret;
}





int main()
{
    int i, j, K;
    int m;
    int t;
    cin>>str;
    clr(dp, -1);
    int len = str.length();
    mx = 1;
    solve(0, str.length() - 1, 0);
//    cout<<mx<<endl;
    for(i = 0; i + mx - 1 < len; i++)
    {
        if(dp[i][i + mx - 1][0] == mx || dp[i][i + mx - 1][1] == mx)
        {
            cout<<str.substr(i, mx)<<endl;
            return 0;
        }
    }

    return 0;
}

/*


18 9
85 29 29 15 17 71 46 69 48 80 44 73 40 55 61 57 22 68

ThesampletextthatcouldbereadedthesameinbothordersArozaupalanalapuazorA

ABAXXXAB
ArozaupalanalapuazorA
ArozaupalanalapuazorA
*/
