#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int main()
{
    int i,j,k;
    char str[55];
    while(gets(str) && str[0]!='#')
    {
        if(next_permutation(str,str+strlen(str)))
            printf("%s\n",str);
        else
            printf("No Successor\n");
    }
}
