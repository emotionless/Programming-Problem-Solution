#include <bits/stdc++.h>
/**********TYPE CASTING**********/
#define LL long long

using namespace std;

bool calculate(LL n)
{
    while(n)
    {
        int rem=n%10;
        if(rem==0 || rem==1 || rem==4 || rem==9)
            n=n/10;
        else
            return false;
    }
    return true;
}


bool is_sq[100001];

void call()
{
    LL i;
    for(i=1; i<=100000; i++)
    {
        is_sq[i]=calculate(i*i);
    }
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    call();
    LL a ,b,i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        int cnt=0;
        for(i=1; i<=100000; i++)
        {
            LL sq=i*i;

            if(sq>=a && sq<=b)
            {
                if(is_sq[i])
                    cnt++;
            }
            if(sq>b) break;
        }
        printf("%d\n", cnt);

    }

    return 0;
}

/*

2
1 10
100 10000

*/
