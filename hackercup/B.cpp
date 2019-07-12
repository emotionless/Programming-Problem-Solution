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
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 200009


using namespace std;

int a[30], b[30], c[30];


int main()
{
    int tc,cs=1,i,j,k, cases = 1;
    int n, m;
    int t;
    int A, B, C;
    ofstream myfile;
    myfile.open ("out.txt");


    cin>>tc;
    while(tc--)
    {
        cin>>A>>B>>C;
        cin>>n;
        for(i = 0; i < n; i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        bool ok = false;
        for(i = 0; i < (1<<n); i++)
        {
            int f = 0, s = 0, t = 0;
            for(j = 0; j < n; j++)
            {
                if(check_bit(i, j))
                {
                    f += a[j];
                    s += b[j];
                    t += c[j];
                }
            }
            if(f == A && s == B && t == C)
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        {
            myfile<<"Case #"<<cases<<": "<<"yes\n";
//            cout<<"Case #"<<cases<<": "<<"yes\n";
        }
        else
        {
            myfile<<"Case #"<<cases<<": "<<"no\n";
//            cout<<"Case #"<<cases<<": "<<"no\n";
        }
        cases++;
    }
    return 0;
}

/*

5
101 100 100
1
100 100 100
100 100 100
3
10 10 40
10 30 10
10 60 50
100 100 100
5
40 70 30
30 10 40
20 20 50
10 50 90
40 10 20
292 264 512
20
909 302 261
705 597 823
291 51 126
28 697 57
593 31 826
311 256 57
292 14 47
29 730 716
12 529 146
768 16 439
37 472 15
350 192 34
163 468 238
69 173 10
203 72 690
424 875 213
223 593 292
151 46 10
88 90 16
773 653 711
991 827 352
20
29 560 929
139 681 102
144 853 10
84 729 80
218 20 67
140 80 901
428 20 500
520 970 128
422 419 30
413 101 192
467 448 501
32 939 684
34 20 38
251 317 132
588 437 10
648 21 79
391 25 14
499 22 24
854 77 361
405 25 20


*/
