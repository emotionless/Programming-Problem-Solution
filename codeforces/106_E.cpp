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
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100009


using namespace std;


string txt, pat;
int F[MAX];
int val[MAX];
int val1[MAX];
int val2[MAX];
int store[MAX];

void FailureFunction()
{
    int i = 1, j = 0;
    F[0] = 0;
    int m = (pat.length());
    while(i < m)
    {
        if(pat[i] == pat[j])
        {
            F[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
}
void KMP()
{
    int i = 0, j = 0;
    FailureFunction();
    int n = (txt.length());
    int m = (pat.length());
    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            if(j == m - 1)
            {
                i++;
                j = F[j];
                val[i - 1] = j;
            }
            else
            {
                val[i] = j + 1;
                i++;
                j++;
            }
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            val[i] = 0;
            i++;
        }
    }
}

int main()
{

    int i, j, k;
    int t, cases = 1;
    string str;
    int n;
    cin>>txt;
    cin>>n;
    int cnt = 0;
    while(n--)
    {
        cin>>pat;
        if(pat.length() == 1) continue;
        string str = txt;
        string rev = pat;
        KMP();
        int len = str.length();
        for(i = 0; i < len; i++){
            val1[i] = val[i];
//            cout<<i<<" "<<val1[i]<<endl;
        }
        reverse(pat.begin(), pat.end());
        reverse(txt.begin(), txt.end());
        memset(val, 0, sizeof val);
        memset(F, 0, sizeof F);
//        cout<<pat<<" "<<txt<<endl;
        KMP();
        int mx = 0;
        for(i = 0; i < len; i++)
        {
            mx = max(mx, val[i]);
            store[len - i - 1] = mx;
//            cout<<i<<" "<<mx<<endl;
        }
//        for(i = 0; i < len; i++)
//            cout<<i<<" "<<store[i]<<endl;
        int pat_len = pat.length();
        txt = str;
        for(i = 0; i < len; i++)
        {
            int have = val1[i];
            int need = pat_len - have;
            if(need == 0)
            {
                cnt++;
                break;
            }
            if(store[i + 1] >= need)
            {
                cnt++;
         //       cout<<n<<endl;
//                cout<<"yes "<<i<<" "<<need<<" "<<len - i - 2<<endl;
                break;
            }
//            cout<<i<<" "<<have<<" "<<need<<endl;
        }
    }
    cout<<cnt<<endl;

    return 0;
}



/*

BBABAABAABBBBAB
10
BBABAABAABBA
A
BBAA
AAAABB
AA
AABB
ABBBBABAABA
ABB
AAABABBAAABAAAA
BABAA

ABAAAAAAAAAAAA
1
AB



*/
