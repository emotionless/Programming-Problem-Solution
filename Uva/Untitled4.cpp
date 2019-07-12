#include <cstdio>
#include <iostream>
#include <cmath>
#define MAX 10001000
using namespace std;
bool ver[MAX]= {false};
long long primes[1000000];
int sieve()
{
    int i, j, k;
    k=0;
    for (i=2 ; i<=MAX ; i++)
    {
        if (ver[i]==false)
        {
            primes[k++]=(long long)i;
            for (j=2 ; i*j<=MAX ; j++)
            {
                ver[i*j]=true;
            }
        }
    }
    primes[0]=2;
    return k;
}

int main()
{

    int i, j, divcount, plim=sieve();;
    long long num, lastdiv;
    while (cin >> num && num)
    {
        if (num<0)
        {
            num*=(-1);
        }
        for (i=0, divcount=0, lastdiv=-1 ; i<plim && num>1 && primes[i]<=num ; i++)
        {
            if (num%primes[i]==0)
            {
                divcount++;
                while (num>1 && num%primes[i]==0)
                {
                    num/=primes[i];
                }
                lastdiv = primes[i];
            }
            if (num==1)
            {
                break;
            }
        }

        if (num==1)
        {
            if (divcount>1) cout << lastdiv << endl;
            else cout << -1 << endl;
        }
        else
        {
            if (divcount>0) cout << num << endl;
            else cout << -1 << endl;
        }
    }

    return 0;

}
