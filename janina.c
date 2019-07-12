#include<stdio.h>

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c)==3)
    {
        if(a==b && b==c)
            printf("*\n");
        else if(a==b)
            printf("C\n");
        else if(b==c)
            printf("A\n");
        else
            printf("B\n");
    }
    return 0;
}

