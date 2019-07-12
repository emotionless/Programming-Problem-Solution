#include <stdio.h>
#include <math.h>

int dist(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
    int p, q, r, s, m, n, i, j;
    int first, second;
    int ab;
    double x, y;
    printf("Enter the value of p, q, r, s, m, n: ");
    scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &m, &n);
    ab = dist(p, q, r, s);
    x = (ab - n*n + m*m)/(2.0 * (double)(sqrt((double)ab)));
    y = sqrt((double)(n*n - (r - x)*(r-x))) - s;

    printf("%.2lf %.2lf\n", x, y);

return 0;
}
/*

5 4 1 4 5 3


*/
