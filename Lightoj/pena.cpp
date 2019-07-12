#include <stdio.h>
#include <stdlib.h>


// IO
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\input.txt","r",stdin)
#define WRITE  freopen("C:\\Users\\emotionless\\Desktop\\output.txt","w",stdout)

int main()
{
//    READ;
//    WRITE;
    int a,b,c,d,e,mid, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf ("%d %d %d %d %d",&a,&b,&c,&d,&e);
        if (b<=a && c<=a && a<=d && a<=e||b<=a && d<=a && a<=c && a<=e||b<=a && e<=a && a<=c && a<=d||c<=a && d<=a && a<=b && a<=e||d<=a && e<=a && a<=b && a<=d||c<=a && e<=a && a<=b && a<=d)
        {
            printf ("middle value is :%d",a);
        }
        else if (a<=b && c<=b && b<=d && b<=e||a<=b && d<=b && b<=c && b<=d||a<=b&& e<=b && b<=c && b<=d||c<=b && d<=b && b<=a && b<=e||d<=b && e<=b && b<=a && b<=c||c<=b && e<=b && b<=a && b<=d)
        {
            printf ("middle value is :%d",b);
        }
        else if (a<=c && b<=c && c<=d && c<=e||a<=c && d<=c && c<=b && c<=e||a<=c&& e<=c && c<=b && c<=d||b<=c && d<=c && c<=a && c<=e||b<=c && e<=c && c<=a && c<=d||d<=c && e<=c && c<=a && a<=b)
        {
            printf ("middle value is :%d",c);
        }
        else if (a<=d && b<=d && d<=c && d<=e||a<=d && c<=d && d<=b && d<=e||a<=d&& e<=d && d<=b && d<=c||b<=d && c<=d && d<=a && d<=e||b<=d && e<=d && d<=a && d<=b||c<=d && e<=d && d<=a && d<=b)
        {
            printf ("middle value is :%d",d);
        }
        else
        {
            printf ("middle value is :%d",e);
        }
        printf("\n");

    }
    return 0;
}
/*



ok done. I have checked. All are okay...

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 2 5 3
1 4 3 2 5
1 4 3 5 2
1 4 5 2 3
1 4 5 3 2
1 5 2 3 4
1 5 2 4 3
1 5 3 2 4
1 5 3 4 2
1 5 4 2 3
1 5 4 3 2
2 1 3 4 5
2 1 3 5 4
2 1 4 3 5
2 1 4 5 3
2 1 5 3 4
2 1 5 4 3
2 3 1 4 5
2 3 1 5 4
2 3 4 1 5
2 3 4 5 1
2 3 5 1 4
2 3 5 4 1
2 4 1 3 5
2 4 1 5 3
2 4 3 1 5
2 4 3 5 1
2 4 5 1 3
2 4 5 3 1
2 5 1 3 4
2 5 1 4 3
2 5 3 1 4
2 5 3 4 1
2 5 4 1 3
2 5 4 3 1
3 1 2 4 5
3 1 2 5 4
3 1 4 2 5
3 1 4 5 2
3 1 5 2 4
3 1 5 4 2
3 2 1 4 5
3 2 1 5 4
3 2 4 1 5
3 2 4 5 1
3 2 5 1 4
3 2 5 4 1
3 4 1 2 5
3 4 1 5 2
3 4 2 1 5
3 4 2 5 1
3 4 5 1 2
3 4 5 2 1
3 5 1 2 4
3 5 1 4 2
3 5 2 1 4
3 5 2 4 1
3 5 4 1 2
3 5 4 2 1
4 1 2 3 5
4 1 2 5 3
4 1 3 2 5
4 1 3 5 2
4 1 5 2 3
4 1 5 3 2
4 2 1 3 5
4 2 1 5 3
4 2 3 1 5
4 2 3 5 1
4 2 5 1 3
4 2 5 3 1
4 3 1 2 5
4 3 1 5 2
4 3 2 1 5
4 3 2 5 1
4 3 5 1 2
4 3 5 2 1
4 5 1 2 3
4 5 1 3 2
4 5 2 1 3
4 5 2 3 1
4 5 3 1 2
4 5 3 2 1
5 1 2 3 4
5 1 2 4 3
5 1 3 2 4
5 1 3 4 2
5 1 4 2 3
5 1 4 3 2
5 2 1 3 4
5 2 1 4 3
5 2 3 1 4
5 2 3 4 1
5 2 4 1 3
5 2 4 3 1
5 3 1 2 4
5 3 1 4 2
5 3 2 1 4
5 3 2 4 1
5 3 4 1 2
5 3 4 2 1
5 4 1 2 3
5 4 1 3 2
5 4 2 1 3
5 4 2 3 1
5 4 3 1 2
5 4 3 2 1




*/
