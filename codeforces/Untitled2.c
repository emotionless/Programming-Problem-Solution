#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b);

/* Change these string to test the program */
#define STRING_1 "MZJAWXU"
#define STRING_2 "XMJYAXU"

/* Algorithm visulization helper */
void display(int *base, int row, int col)
{
    int r, c;

    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            printf("\t%4d", (base + r * col));
        }

        printf("\n");
    }
}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    int L[sizeof(STRING_1)][sizeof(STRING_2)];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            L[i][j] = -1;
        }
    }

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
    that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if(X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }

        /* Algorithm visulization code */
        display((int *)L, m+1, n+1);
        printf("\n\n");
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Driver program to test above function */
int main()
{
    char X[] = STRING_1;
    char Y[] = STRING_2;

    int m = sizeof(STRING_1) - 1;
    int n = sizeof(STRING_2) - 1;

    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    return 0;
}
