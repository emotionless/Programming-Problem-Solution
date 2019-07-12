#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long coord_t;
struct point
{
    coord_t x, y;
    bool operator <(const point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
} ver;
vector<point> in,C;
coord_t cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (coord_t)(B.y - O.y) - (A.y - O.y) * (coord_t)(B.x - O.x);
}
vector<point> convexHull(vector<point> P)
{
    coord_t n = P.size(), k = 0;
    vector<point> H(2*n);
    sort(P.begin(), P.end());
    for (coord_t i = 0; i < n; i++)
    {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (coord_t i = n-2, t = k+1; i >= 0; i--)
    {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}
double calcAng(point A,point B,point C)
{
    double a = ((B.x-C.x)*(B.x-C.x))+((B.y-C.y)*(B.y-C.y));
    double b = ((A.x-C.x)*(A.x-C.x))+((A.y-C.y)*(A.y-C.y));
    double c = ((A.x-B.x)*(A.x-B.x))+((A.y-B.y)*(A.y-B.y));
    return acos((double)((a+c-b)/(2*sqrt((double)a)*sqrt((double)c))))*180/acos((double)-1);
}
double code()
{
    C.push_back(C[1]);
    double minAng = 400;
    for(coord_t i=1; i<C.size()-1; i++)
    {
        double recAng = calcAng(C[i-1],C[i],C[i+1]);
        if(recAng<minAng) minAng = recAng;
    }
    return minAng;
}
int main()
{
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(6);
    coord_t T,cases = 1;
    in.clear();
    C.clear();
    coord_t n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ver.x>>ver.y;
        in.push_back(ver);
    }
    if(n==1)
    {
        cout<<4<<endl;
    }
    else if(n==2)
    {
        long long aa,bb,cc,dd;
        long long ans=0;
        aa=abs(in[0].x-in[1].x);
        bb=abs(in[0].y-in[1].y);
        cc=min(aa,bb);
        dd=max(aa,bb);
        ans=dd*2;
        ans+=4;
//            cout<<aa<<" "<<bb<<endl;
        cout<<ans<<endl;
    }
    else
    {
        C = convexHull(in);
        long long aa,bb,cc,dd;
        long long ans=0;
        int sz=C.size();
        for(int i=1; i<sz; i++)
        {
            aa=abs(C[i].x-C[i-1].x);
            bb=abs(C[i].y-C[i-1].y);
            dd=max(aa,bb);
            ans+=dd;
        }
        ans+=4;// max(4,sz-1);
        cout<<ans<<endl;
    }
    return 0;
}
