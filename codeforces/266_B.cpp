#include <bits/stdc++.h>

#define LL long long
#define MX 100009
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


using namespace std;
LL aaa, bbb;
//LL BS(LL n, LL a, LL b)
//{
//    LL st = 1ll, ed = 10000000000ll, mid, ret = 1000000000000ll;
//    while(st <= ed)
//    {
//        mid = (st + ed) / 2;
//        LL area = mid * a;
//        if(area < n || mid < b)
//        {
//            st = mid + 1;
//        }
//        else
//        {
//            ed = mid - 1;
//            if(area < ret)
//            {
//                ret = area;
//                aa = a;
//                bb = mid;
//            }
//        }
//    }
//    return ret;
//}


int main()
{

    int i, j, k;
    LL n, a, b;

    cin>>n>>a>>b;

//    LL res = BS(n * 6, a, b);
//    LL aaa = aa;
//    LL bbb = bb;
//
//    LL ar = BS(n * 6, b, a);
//    if(ar < res)
//    {
//        res = ar;
//        aaa = aa;
//        bbb = bb;
//    }
//    cout<<res<<endl;
//    cout<<aaa<<" "<<bbb<<endl;
    LL res = 100000000000ll;
    aaa = a;
    bbb = b;
    for(LL i = b; i <= b + 1000000; i++)
    {
        LL need = ceil((double)(n * 6)/(double)i);
        if(need < a)
            need = a;
        LL area = need * i;

        if(area < res && area >= (n * 6) && need >= a)
        {
            res = area;
            aaa = need;
            bbb = i;
        }

    }

    for(LL i = a; i <= a + 1000000; i++)
    {
        LL need = ceil((double)(n * 6)/(double)i);
        if(need < b)
            need = b;
        LL area = need * i;
        if(area < res && area >= (n * 6) && need >= b)
        {
            res = area;
            aaa = i;
            bbb = need;
        }
    }

    cout<<aaa * bbb<<endl;
    cout<<aaa<<" "<<bbb<<endl;







    return 0;
}

/*


4 4
4 4 4 4



*/
