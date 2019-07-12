#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 200009


using namespace std;


int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    string ans = "";
    int f = 0, s = 0;
    if(c == d)
    {
        if(c == 1)
        {
            if(a == 1)
            {
                ans = "747";

                f = 1;
                s = 2;
            }
            else
            {
                ans = "474";
                f = 2;
                s = 1;
            }
        }
        else if(c == 2)
        {
            if(b > a && (a != 10 || b!= 100))
            {
                ans = "74747";

                f = 2;
                s = 3;
            }
            else //if(a == 2)
            {
                ans = "47474";

                f = 3;
                s = 2;
            }

        }
        else if(a > b)
        {
            for(i = 0; i < c; i++)
            {
                ans += "47";
            }
            ans += '4';
            f = c + 1;
            s = c;
        }
        else if(a == b)
        {
            for(i = 0; i < c; i++)
                ans += "47";
            ans += "74";
            f = c + 1;
            s = c + 1;
        }
        else if(a != b)
        {
            if(a > b || (a == 100 && b == 200))
            {
                for(i = 0; i < c; i++)
                    ans += "47";
                ans += "4";
                f = c + 1;
                s = c;
            }
            else
            {
                for(i = 0; i < c; i++)
                    ans += "74";
                ans += "7";
                f = c;
                s = c + 1;
            }
        }
        else
        {
            ans += '7';
            for(i = 0; i < c; i++)
                ans += "47";
            s = c + 1;
            f = c;
        }
    }
    else if(c - 1 == d)
    {
        ans += '4';
        f ++;
        for(i = 0; i < d; i++)
            ans += "74", f++, s++;
        ans += '7';
        s ++;
    }
    else if(d - 1 == c)
    {
        ans += '7';
        s++;
        for(i = 0; i < c; i++)
            ans += "47", f++, s++;
        ans += '4';
        f++;
    }
    else
    {
        cout<<-1<<endl;
        return 0;
    }

    if(f > a || s > b)
    {
        cout<<-1<<endl;
        return 0;
    }
    int pos1 = 0;
    for(i = 0; i < ans.size(); i++)
    {
        if(ans[i] == '4')
        {
            pos1 = i;
            break;
        }
    }
    string sub1 = ans.substr(0, pos1);
//    cout<<sub1<<endl;
    string sub2 = ans.substr(pos1);

    for(i = 0; i < a - f; i++)
    {
        sub1 += '4';
    }
    sub1 += sub2;
    ans = sub1;


    int pos2 = 0;
    for(i = 0; i < ans.size(); i++)
    {
        if(ans[i] == '7')
            pos2 = i;
    }
    sub1 = ans.substr(0, pos2);
    sub2 = ans.substr(pos2);

    for(i = 0; i <b - s ; i++)
    {
        sub1 += '7';
    }
    sub1 += sub2;
    cout<<sub1<<endl;















    return 0;
}

/*

10 9 5 5


*/
