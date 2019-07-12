#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;

int n;
float a[10][11];

void forwardSubstitution()
{
    int i, j, k, mx;
    float t;
    for (i = 0; i < n; ++i)
    {
        mx = i;
        for (j = i + 1; j < n; ++j)
        {
            cout<<i<<" "<<j<<" "<<a[j][i]<<" \n";
            if (a[j][i] > a[mx][i])
                mx = j;
        }
        cout<<endl;
        cin>>j;

        for (j = 0; j < n + 1; ++j)
        {
            t = a[mx][j];
            a[mx][j] = a[i][j];
            a[i][j] = t;
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
        for (k = 0; k < n; ++k)
        {
            for (j = 0; j < n + 1; ++j)
                printf("%.2f\t", a[k][j]);
            printf("\n");
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;

        for (j = n; j >= i; --j)
            for (k = i + 1; k < n; ++k){
                a[k][j] -= a[k][i]/a[i][i] * a[i][j];
                cout<<k<<" "<<j<<endl;
            }
    }
}

void reverseElimination()
{
    int i, j;
    for (i = n - 1; i >= 0; --i)
    {
        a[i][n] = a[i][n] / a[i][i];
        a[i][i] = 1;
        for (j = i - 1; j >= 0; --j)
        {
            a[j][n] -= a[j][i] * a[i][n];
            a[j][i] = 0;
        }
    }
}

void gauss()
{
    int i, j;

    forwardSubstitution();
    reverseElimination();

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n + 1; ++j)
            printf("%.2f\t", a[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n + 1; ++j)
            scanf("%f", &a[i][j]);
    gauss();

    return 0;
}

/*


3
2	1	-1	8
-3	-1	2	-11
-2	1	2	-3


*/
