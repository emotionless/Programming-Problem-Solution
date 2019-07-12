/*
ID: milon_c1
LANG: C++
PROG: transform
*/
#include<stdio.h>
#include<string.h>

int N;
char c1[11][11],c2[11][11],c3[11][11];
void clear(char (*cp1)[11])
{
    memset(cp1,'\0',sizeof(cp1));
}
bool check(char (*cp1)[11],char (*cp2)[11])
{

    for(int i=0; i<N; i++) if(strncmp(*(cp1+i),*(cp2+i),N)) return(0);
    return(1);
}
void turn90(char (*cp1)[11],char (*cp2)[11])
{
    clear(cp2);
    for(int i1=0,i2=N-1; i1<N; i1++,i2--)
        for(int j=0; j<N; j++) *(*(cp2+j)+i2)=*(*(cp1+i1)+j);
}
void turn180(char (*cp1)[11],char (*cp2)[11])
{
    clear(cp2);
    char c[11][11];
    turn90(cp1,c);
    turn90(c,cp2);
}
void turn270(char (*cp1)[11],char (*cp2)[11])
{
    clear(cp2);
    char c[11][11];
    turn180(cp1,c);
    turn90(c,cp2);
}
void turn(char (*cp1)[11],char (*cp2)[11])
{
    clear(cp2);
    for(int i=0; i<N; i++)
        for(int j1=0,j2=N-1; j1<N; j1++,j2--)
            *(*(cp2+i)+j2)=*(*(cp1+i)+j1);
}
bool unit()
{
    char c[11][11],cc[11][11];
    turn(c1,c);
    turn90(c,cc);
    if(check(cc,c2)) return(1);
    turn180(c,cc);
    if(check(cc,c2)) return(1);
    turn270(c,cc);
    return(check(cc,c2));
}
int doit()
{
    int i=1;
    while(i)
    {
        switch(i)
        {
        case 1:
            turn90(c1,c3);
            break;
        case 2:
            turn180(c1,c3);
            break;
        case 3:
            turn270(c1,c3);
            break;
        case 4:
            turn(c1,c3);
            break;
        case 5:
            if(unit()) return(5);
            break;
        case 6:
            if(check(c1,c2)) return(6);
            else return(7);
        }
        if(check(c3,c2)) return(i);
        i++;
    }
}
int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%s",c1[i]);
    for(int i=0; i<N; i++) scanf("%s",c2[i]);
    printf("%d\n",doit());
    return 0;
}
