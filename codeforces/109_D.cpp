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
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define debug cout<<"here"<<endl;



#define MOD 1000000007
#define MAX 100009



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

bool is_prime[MAX + 7];
int prime[MAX];
int k;
int sieve()
{
    int i, j;
    k = 0;
    prime[k++] = 2;
    int sq = sqrt(MAX);
    for(i = 3; i <= sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j = i+i; j <= MAX; j+=i)
                is_prime[j] = 1;
        }
    }

    for(i = 3; i < MAX; i+=2)
    {
        if(!is_prime[i])
        {
            prime[k++] = i;
//            cout<<i<<" ";
        }
    }

}


int M[MAX];

int val[MAX];

bool on[MAX];

int main()
{
    int i, j;
    string str;
    int t, n, q, num;
    k = 0;
    sieve();

    for(i = 0; i < k; i++)
    {
        M[prime[i]] = i+1;
    }

    vector<int>vec;
    char op;
    cin>>n>>q;
    while(q--)
    {
        cin>>op>>num;
        vec.clear();
        if(op == '+')
        {
            if(on[num])
            {
                cout<<"Already on"<<endl;
                continue;
            }
            int sq = sqrt(num);
            int save = num;
            bool ck = 0;
            for(i = 0; i < k && prime[i] <= sq; i++)
            {
                if(num%prime[i] == 0)
                {
//                    cout<<i<<endl;
                    vec.pb(prime[i]);
                    if(val[M[prime[i]]])
                    {
                        cout<<"Conflict with "<<val[M[prime[i]]]<<endl;
                        vec.clear();
                        ck = 1;
                        break;
                    }
                    while(num%prime[i] == 0)
                    {
                        num = num/prime[i];
                    }
                    sq = sqrt(num);
                }
            }
            if(num > 1)
            {
                vec.pb(num);
                if(val[M[num]])
                {
                    cout<<"Conflict with "<<val[M[num]]<<endl;
                    ck = 1;
                }
            }
            if(!ck)
            {
                cout<<"Success"<<endl;
                int sz = vec.size();
                on[save] = 1;
                for(i = 0; i < sz; i++)
                {
                    val[M[vec[i]]] = save;
//                    cout<<val[M[vec[i]]]<<endl;
                }
            }
        }
        else
        {
            if(!on[num])
            {
                cout<<"Already off"<<endl;
                continue;
            }
            else
            {
                cout<<"Success"<<endl;

                // calc is here
                int sq = sqrt(num);
                int save = num;
                on[save] = 0;
                bool ck = 0;
                for(i = 0; i < k && prime[i] <= sq; i++)
                {
                    if(num%prime[i] == 0)
                    {
//                    cout<<i<<endl;
                        vec.pb(prime[i]);

                        while(num%prime[i] == 0)
                        {
                            num = num/prime[i];
                        }
                        sq = sqrt(num);
                    }
                }
                if(num > 1)
                    vec.pb(num);

                int sz = vec.size();
                for(i = 0; i < sz; i++)
                {
                    val[M[vec[i]]] = 0;
//                    cout<<vec[i]<<endl;
                }

            }


        }
    }







    return 0;
}

/*

25 20
+ 7
+ 14
- 7
+ 11
+ 15
+ 10
+ 20
- 15
+ 13
- 14
+ 4
- 11
- 20
+ 15
+ 16
+ 3
+ 11
+ 22
- 16
- 22


*/
