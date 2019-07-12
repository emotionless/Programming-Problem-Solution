/************** Miller Rabin method ***********/
/********* For determining if a number is prime or not. where n <= 10^18 ***********/

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


/** here n is the number which we want to test
k is the highest number of checking. here k = 10
is enough for 10^18
**/
bool isPrime(long long n, int k)
{
    if(n < 2) return false;
    if(n != 2 && n%2 == 0)
        return false;

    long long s = n - 1;
    while(s%2 == 0)
        s >>= 1;
    for(int i = 0; i < k; i++)
    {
        long long a = (rand()%(n - 1)) + 1;
        long long temp = s;
        long long mod = bigmod(a, temp, n) % n;
        while(temp != n - 1ll && mod != 1ll && mod != n - 1ll)
        {
            mod = multimod(mod, mod, n);
            temp = temp * 2ll;
        }
        if(mod != n - 1ll && temp%2 == 0)
            return false;
    }
    return true;
}
