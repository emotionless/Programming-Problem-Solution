#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
};
float dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
Point Points[100001];
int main()
{
    int i, j, k, n;
    Point a, b;
    cin>>n;
    for(i=0; i < n; i++) cin>>Points[i].x>>Points[i].y;
    float mn = 10000000.0;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(dist(Points[i], Points[j])< mn)
            {
                mn = dist(Points[i], Points[j]);
                a = Points[i];
                b = Points[j];
            }
        }
    }
    cout<<"Points are: "<<a.x<<" "<<a.y<<"\n"<<b.x<<" "<<b.y<<endl;

    return 0;
}
