#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;
int D[101];
int main()
{
    int n = 1, Ds, N = 100, etaN[101], NidN;
    for(int i = 1; i <= 100; i++)
        D[i] = rand()%1000;
    Ds = D[1];

    do
    {
        scanf("%d", &NidN);
        etaN[n] = NidN/D[n];
        if(etaN[n-1]<=etaN[n])
            Ds = D[n];
    }
    while(n <= N);

// Ds holds the answer

return 0;
}
