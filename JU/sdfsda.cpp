#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0; i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<LL, LL>
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


#define MOD 1000007

#define MAX 100009
#define MAXLG 20
#define inf 100000

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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************


char str[MAX], tar[MAX];

bool is[MAX];

int main()
{
//    READ;
//    WRITE;
//    use_cin;
    int i, j, type, k;
    int  a, b, t, cases = 1;
    int u, v, w, n;
    while(gets(str))
    {
        gets(tar);

        int len = strlen(str);
        int tarlen = strlen(tar);
        int p = 0, prei = 0, prej = 0;
        j = 0;
        tar[tarlen] = ' ';
        str[len] = ' ';
        tar[tarlen + 1] = '\0';
        str[len + 1] = '\0';
        for(i = 0; i <= len; i++)
        {
            if(str[i] == tar[j])
            {
                if(str[i] == ' ')
                {
//                cout<<i<<" "<<j<<endl;
                    p = prej;
                    for(k = prei; k < i; k++)
                    {
                        if(str[k] == tar[p])
                            is[k] = 1, p++;
                        else
                            is[k] = 0;
                    }
                    prei = i + 1;
                    prej = j + 1;
                    j++;
                }
                else
                    j++;
            }
            if(str[i] == ' ')
            {
                prei = i + 1;
                j = prej;
            }
        }
//    cout<<i<<" "<<j<<endl;
        if(i == len + 1 && j == tarlen + 1)
        {
            for(i = 0; i < len; i++)
            {
                if(str[i] == ' ')
                    printf(" ");
                else if(is[i])
                    printf("%c", str[i]);
                else
                    printf("_");
            }
            puts("");
        }
        else
            printf("I HAVE FAILED!!!\n");
        clr(is, false);
    }

    return 0;
}

/*


1
5
2 1
2 3
3 4
3 5


*/
