#include<stdio.h>
#include<windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void load()
{
    int r,c,q,i,j=1;
    int ara[10]= {73,32,76,79,86,69,32,89,79,85};
    for(i=0; i<10; i++)
    {
        for(q=0; q<=100000000; q++);
        {
            printf("%c", ara[i]);
        }
        gotoxy(25+j,5+j);
        j++;
    }
//    getch();
}
main()
{
    gotoxy(25,5);
    load();
}
