#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(x,y)(((x)<(y))?(x):(y))
char a[100]="#";
char b[100]="#";

int dp[100][100];
int s = 1;

int findDp(int i,int j)
{
    if(dp[i][j]==-1)
    {
        if(i*j==0)dp[i][j] = i+j;
        else if(a[i]==b[j])
        {
            dp[i][j] = findDp(i-1,j-1);
        }
        else
        {
            dp[i][j] = MIN(findDp(i-1,j-1),MIN(findDp(i-1,j),findDp(i,j-1)))+1;
        }
    }
    return dp[i][j];
}

void printA(int i,int j)
{
    if(i*j==0)
    {
        while(i>0)
        {
            printf("D%c%.2d",a[i],i);
            --i;
        }
        while(j>0)
        {
            printf("I%c%.2d",b[j],1);
            --j;
        }
    }
    else if(a[i]==b[j])
    {
        printA(i-1,j-1);
    }
    else
    {
        if(dp[i][j]-1 == dp[i-1][j-1])
        {
            printf("C%c%.2d",b[j],i);
            printA(i-1,j-1);
        }
        else if(dp[i][j]-1 == dp[i][j-1])
        {
            printf("I%c%.2d",b[j],i+1);
            printA(i,j-1);
        }
        else if(dp[i][j]-1 == dp[i-1][j])
        {
            printf("D%c%.2d",a[i],i);
            printA(i-1,j);
        }
    }
}

int main()
{

    while(scanf("%s",&a[1])&&a[1]!='#')
    {
        scanf("%s",&b[1]);
        s = 1;
        memset(dp,-1,sizeof(dp));
        findDp(strlen(a)-1,strlen(b)-1);
        printA(strlen(a)-1,strlen(b)-1);
        puts("E");
    }

    return 0;
}
