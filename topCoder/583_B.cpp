#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

/**********TYPE CASTING**********/
#define LL long long
#define L long
#define D double
#define LD long double
#define S string
#define I int
#define ULL unsigned long long
#define q queue<int>
#define vi vector<int>
#define vl vector<long>

/**********INPUT**********/
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define s1(a) scanf("%d",&a)
#define s2(a,b) scanf("%d%d",&a,&b)
#define s3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sll(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",&a)
#define gc() getchar()

/**********OUTPUT**********/
#define p1(a) printf("%d\n",a)
#define p2(a,b) printf("%d %d\n",a,b)
#define pll(a) printf("%lld\n",a)
#define pd(a) printf("%.10lf\n",a)
#define pcs(a,n) printf("Case %d: %d\n",a,n)
#define nl() printf("\n")

/**********LOOP**********/
#define REV(i,e,s) for(i=e;i>=s;i--)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)

/********** min/max *******/
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))

/**********SHORTCUT**********/
#define len(a) a.length()
#define SET(a,x) memset(a,x,sizeof a)
#define VI vector<int>
#define SZ size()
#define CLR clear()
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))


/**********CONSTANT**********/
#define MIN INT_MIN
#define PI 2acos(-1.0)
#define INF 2<<15
#define MOD 1000000007
#define MAX 1000001



using namespace std;


class IDNumberVerification {
public:
bool leap_year(S a)
{
    I n=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+(a[3]-'0');
    if((n%4==0 && n%100!=0)||n%400==0)
        return true;
    return false;
}

bool check(string year, S mon, S day)
{
    S arr[]= {"31","28","31","30","31","30","31","31","30","31","30","31"};

    I n=(year[0]-'0')*1000+(year[1]-'0')*100+(year[2]-'0')*10+(year[3]-'0');
    if(n<1900 || n>2011)
    return false;


    if(mon>"12" || mon=="00" || day=="00")
    return false;

    if(leap_year(year))
    {
        arr[1]="29";
    }
    I mn=(mon[0]-'0')*10+mon[1]-'0';
    if(day<=arr[mn-1])
        return true;
    return false;
}



string verify(string id, vector <string> regionCodes)
{
    S take=id.substr(0,6);
    bool c=false;
    for(I i=0; i<regionCodes.size(); i++)
    {
        if(regionCodes[i]==take)
        {
            c=true;
            break;
        }
    }
    if(!c)
        return "Invalid";

    if(!check(id.substr(6,4),id.substr(10,2),id.substr(12,2)))
        return "Invalid";

    if(id.substr(14,3)=="000")
        return "Invalid";
    long sum;
    if(id[17]=='X')
        sum=10;
    else
        sum=id[17]-'0';
    for(I i=0; i<17; i++)
    {
        sum+=((id[i]-'0')*pow(2,(double)(17-i)));
    //    cout<<i<<" "<<((id[i]-'0')*pow(2,(double)(17-i)))<<endl;
    }
 //  cout<<sum<<endl;
    if(sum%11!=1)
        return "Invalid";
    if(id[16]%2)
        return "Male";
    else
        return "Female";
}


};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
