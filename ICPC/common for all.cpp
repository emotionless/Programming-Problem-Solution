#include <bits/stdc++.h>

#define LL long long
#define MX 2009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define ll long long
#define MOD  1000000007ll
#define PB push_back

#define PI 3.14159265358979323846264338328

using namespace std;

bool check(int m, int d)
{
    if(m<1||d<1||m>12||d>31)
        return false;
    if(m == 1)
    {
        if(d <= 31) return true;
    }
    if(m == 2)
    {
        if(d <= 28) return true;
    }
    if(m == 3)
    {
        if(d <= 31) return true;
    }
    if(m == 4)
    {
        if(d <= 30) return true;
    }
    if(m == 5)
    {
        if(d <= 31) return true;
    }
    if(m == 6)
    {
        if(d <= 30) return true;
    }
    if(m == 7)
    {
        if(d <= 31) return true;
    }
    if(m == 8)
    {
        if(d <= 31) return true;
    }
    if(m == 9)
    {
        if(d <= 30) return true;
    }
    if(m == 10)
    {
        if(d <= 31) return true;
    }
    if(m == 11)
    {
        if(d <= 30) return true;
    }
    if(m == 12)
    {
        if(d <= 31) return true;
    }
    return false;
}

bool check2(int d1, int m1, int d2, int m2)
{
    if(m1 == m2)
    {
        if(d1 < d2) return true;
        return false;
    }
    return (bool)(m1 < m2);
}

int main()
{
    int d1, m1, d2, m2;
    int cases = 1;
    int t;

    scanf("%d", &t);
    while(t--)
    {
        bool first = false, second = false, third = false;
        scanf("%d", &d1);
        scanf("%d", &m1);
        scanf("%d", &d2);
        scanf("%d", &m2);

        if(check(d1,m1) && check(d2, m2) && check2(d1, m1, d2, m2))
            first = true;

        if(check(m1,d1) && check(m2, d2) && check2(m1, d1, m2, d2))
            second = true;

        printf("Case %d: ", cases++);
        if((d1 <1) || (d2 <1)  || (m1 <1)  || (m2 <1 ))
            first = second = false;

        if(first && second)
            printf("Oh no it is ambiguous!\n");
        else if(first || second)
            printf("Okay got it!\n");
        else
            printf("I am sure there is some kinda mistake!\n");
    }
    return 0;
}

/*

4
4 3 3 3



*/
