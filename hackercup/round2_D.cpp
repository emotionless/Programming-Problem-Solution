
#include<bits/stdc++.h>

#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr(a,b) make_pair(a,b)
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,a,n) for(i=n;i>=a;i--)
#define MXE(x) *max_element(all(x))
#define MNE(x) *min_element(all(x))

#define INFILE()  freopen("corporate_gifting.txt","r",stdin)
#define OUTFILE() freopen("outputDDDD.txt","w",stdout)


using namespace std;
typedef long long ll;

#define MX  200002

int arr[MX];
bool vis[MX];
int main()
{

    int tc,n,x,cs=1,i,j,k;
    string str;
    cin>>str;
    str = str;
//    if(str[str.length() - 1] == 'I')
        str += 'I';
//    else
//        str += 'D';
    int len = str.length();
    int mx = len, mn = 1;
    for(i = 0; i < len; i++)
    {
        if(str[i] == 'D')
        {
            int pos = -1;
            for(j = i; j < len && str[j] == 'D'; j++)
            {
                vis[mx] = true;
//                cout<<mx<<endl;
                arr[j] = (mx--);
                pos++;

            }
            i += pos;
        }
    }

    for(i = 0; i < len; i++)
    {
        if(str[i] == 'I')
        {
            int pos = -1;
            for(j = i; j < len && str[j] == 'I'; j++)
            {
                pos++;
            }
            for(j= j - 1; j>=i; j--){
//                cout<<mx<<endl;
                vis[mx] = 1, arr[j]  = (mx--);
            }
            i += pos;
        }
    }
    for(i = 0; i < len; i++){
        if(arr[i] == 0) cout<<mx<<" ";
     else   cout<<arr[i]<<" ";
    }
//    for(i = 1; i <= len + 1; i++)
//        if(!vis[i])
//        cout<<i<<endl;







    return 0;
}
