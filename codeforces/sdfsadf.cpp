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
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\B-large-practice.in","r",stdin)
#define WRITE freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 200009



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

///***** Template ends here *****///
///********************* Code starts here ****************************

#define YES printf("GABRIEL\n")
#define NO printf("RICHARD\n")

int mat[21][21];
int ans[21][21];

int main()
{
    READ;
    WRITE;
    int i, j;
    int num;
    string tmp;
    int t,m,n,cases = 1;
    scanf("%d", &t);
    int x;
    string str;
    while(t--)
    {
        cin>>n>>str;

        memset(ans, 0, sizeof ans);
        memset(mat, 0, sizeof mat);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin>>mat[i][j];

        switch(str[0])
        {
        case 'l':
        {
            for(i = 0; i < n; i++)
            {
                int k = 0;
                for(j = 0; j < n; j++)
                {
                    while(k<n && mat[i][k] == 0)
                    {
                        k++;
                    }
                    int l = k + 1;
                    for(; l < n; l++)
                    {
                        if(!mat[i][l]) continue;
                        if(mat[i][k] == mat[i][l])
                        {
                            ans[i][j] = mat[i][k]*2;
                            k = l+1;
                            break;
                        }
                        else
                        {
                            ans[i][j] = mat[i][k];
                            k=l;
                            break;
                        }
                    }
                    if(l >= n)
                        ans[i][j] = mat[i][k++];
                }
            }
            break;
        }
        case 'r':
        {
            for(i = n - 1; i >= 0; i--)
            {
                int k = n-1;
                for(j = n-1; j >= 0; j--)
                {
                    while(k>=0 && mat[i][k] == 0)
                    {
                        k--;
                    }
                    int l = k - 1;
                    for(; l >= 0; l--)
                    {
                        if(!mat[i][l]) continue;
                        if(mat[i][k] == mat[i][l])
                        {
                            ans[i][j] = mat[i][k]*2;
                            k = l-1;
                            break;
                        }
                        else
                        {
                            ans[i][j] = mat[i][k];
                            k=l;
                            break;
                        }
                    }
                    if(l < 0)
                        ans[i][j] = mat[i][k--];
                }
            }
            break;
        }

        case 'u':
        {
            for(i = 0; i < n; i++)
            {
                int k = 0;
                for(j = 0; j < n; j++)
                {
                    while(k<n && mat[k][i] == 0)
                    {
                        k++;
                    }
                    int l = k + 1;
                    for(; l < n; l++)
                    {
                        if(!mat[l][i]) continue;
                        if(mat[k][i] == mat[l][i])
                        {
                            ans[j][i] = mat[k][i]*2;
                            k = l+1;
                            break;
                        }
                        else
                        {
                            ans[j][i] = mat[k][i];
                            k=l;
                            break;
                        }
                    }
                    if(l >= n)
                        ans[j][i] = mat[k++][i];
                }
            }
            break;

        }

        case 'd':
        {
            for(i = n - 1; i >= 0; i--)
            {
                int k = n - 1;
                for(j = n - 1; j >= 0; j--)
                {
                    while(k>=0 && mat[k][i] == 0)
                    {
                        k--;
                    }
                    int l = k - 1;
                    for(; l >= 0; l--)
                    {
                        if(!mat[l][i]) continue;
                        if(mat[k][i] == mat[l][i])
                        {
                            ans[j][i] = mat[k][i]*2;
                            k = l-1;
                            break;
                        }
                        else
                        {
                            ans[j][i] = mat[k][i];
                            k=l;
                            break;
                        }
                    }
                    if(l < 0)
                        ans[j][i] = mat[k--][i];
                }
            }
            break;
        }
        }

        printf("Case #%d:\n", cases++);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cout<<ans[i][j];
                if(j == n - 1) cout<<endl;
                else
                    cout<<" ";
            }
        }
    }



    return 0;
}

/*


5
4 right
2 0 2 4
2 0 4 2
2 2 4 8
2 2 4 4
10 up
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0
3 down
2 2 2
4 0 0
8 8 8
3 right
0 0 0
0 0 0
8 8 8
1 up
1




*/
