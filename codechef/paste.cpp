#include<bits/stdc++.h>
#define f(x)  x*x-1
#define LL long long

using namespace std;

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int main()
{

    long long n=115;
    long long y=2;
    long long x=2;

    long long d=1;

    while(d==1)
	{
		x=(x*x+1)%n;
		y=(x*x+1)%n;
		d=gcd(n,abs(x)-abs(y));
	}
    cout<<"Divisor:"<<d<<endl;

    return 0;
}
