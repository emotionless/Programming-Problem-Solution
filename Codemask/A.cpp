#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int month[12]= {14,13,15,14,15,15,16,16,16,16,15,15};
    int month1[12]= {10,11,12,1,2,3,4,5,6,7,8,9};
    char bnmonth[12][50]= {"Baishakh", "Jaishtha", "Ashar", "Sraban", "Bhadra", "Ashwin", "Kartik" ,"Agrahayan", "Poush", "Magh", "Falgun", "Chaitra"};

    int  d, m, y, bday, bmonth, byear, ok;
    long long int t, caseno;
    scanf("%lld", &t);
    caseno=0;
    while(t--)
    {
        scanf("%d%d%d", &d, &m, &y);
        if(d<month[m-1])
        {
            if(month1[m-1]==1||month1[m-1]>=7&&month1[m-1]<=12)
            {
                bday=30-(month[m-1]-d-1);
                if(m==1)
                {
                    bmonth=9;
                }
                else
                    bmonth=month1[m-1-1];
            }
            else
            {
                bday=31-(month[m-1]-d-1);
                bmonth=month1[m-1-1];
            }
        }
        else if(d==month[m-1])
        {
            bday=1;
            bmonth=month1[m-1];
        }
        else
        {
            bday=d-month[m-1]+1;
            bmonth=month1[m-1];
        }
        byear=y-1972+1378;
        if(m>=4)
        {
            if(m==4&&d>=14)
                byear++;
            else if(m>4)
                byear++;
        }
        if(y%4 == 0)
        {
            ok=1;
            if(y%100==0)
            {
                if(y%400==0)
                    ok=1;
                else
                    ok=0;
            }
            if(ok==1)
                if(d>=1&&d<=14&&m==3)
                 bday++;

        }
        printf("Case %lld: %d, %s, %d\n", ++caseno, bday, bnmonth[bmonth-1], byear);

    }
    return 0;
}

/*

10
1 9 2016
14 4 2016
13 4 2016
31 12 2016
29 2 2016


10
1 9 2016
Case 1: 17, Bhadra, 1422
14 4 2016
Case 2: 1, Baishakh, 1423
13 4 2016
Case 3: 30, Chaitra, 1422
31 12 2016
Case 4: 17, Poush, 1423
29 2 2016
Case 5: 17, Falgun, 1422


*/
