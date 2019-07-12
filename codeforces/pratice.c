#include <stdio.h>
#define MAX 100009



char str[MAX];


int failure()
{
    int F[MAX];
    int i = 1, j = 0;
    F[0] = 0;
    while(str[i] != '\0')
    {
        if(str[i] == str[j])
        {
            F[i] = j+1;
            j++;
            i++;
        }
        else if(j > 0)
            j = F[j-1];
        else
        {
            F[i] = 0;
            i++;
        }
    }
    return i/(i-j);
}

int main()
{
    int i,j, k;
    int n, len;
    int val;
    while(scanf(" %s", str))
    {
        if(str[0] == '*' && str[1]=='\0') break;
        j = failure();
        printf("%d\n", j);
    }



    return 0;
}
