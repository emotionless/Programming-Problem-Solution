#include <bits/stdc++.h>

#define LL long long
#define MAX 100009
#define MOD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

bool is[MAX];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int p;
    int n;
    int t, K;
    for(i = 1; i < MAX; i++)
    {
        int sum = 0;
        int num = i;
        while(num)
        {
            sum += num%10;
            num /= 10;
        }

        if(i%sum == 0) is[i] = 1;
    }

//    cin>>t;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &a, &b);
        int cnt = 0;
        for(i = a; i <= b; i++)
        {
            if(i < MAX)
            {
                cnt += is[i];
                continue;
            }
            int sum = 0;
            int num = i;
            while(num)
            {
                sum += num%10;
                num /= 10;
            }

            if(i%sum == 0) cnt++;
        }
        printf("%d\n", cnt);
//        cout<<cnt<<endl;
    }




    return 0;
}

/*

1
7 3
1 1 1 2 2 2 3


*/
