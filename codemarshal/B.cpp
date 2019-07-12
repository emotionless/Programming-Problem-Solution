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
#define MAX 200000


using namespace std;

int tmp[MAX];

int main()
{
    int tc,cs=1,i,j,k;
    int n,m;
    string str;
    int t;
    scanf("%d", &t);
    while(t--)
    {

        s1(n);
        s1(m);
        stack<int>ST[10004];
        string op;
        printf("Case %d:\n", cs++);
        while(m--)
        {
            cin>>op;
            if(op=="push")
            {
                s2(i, j);
                ST[i].push(j);
            }
            else if(op == "pop")
            {
                s1(i);
                if(!ST[i].empty())
                    ST[i].pop();
            }
            else if(op == "put")
            {
                s2(i, j);
                k = 0;
                while(!ST[j].empty())
                {
                    int top = ST[j].top();
                    ST[j].pop();
                    tmp[k++]=top;
                }
                for(int l = k - 1; l >= 0; l--)
                {
                    ST[i].push(tmp[l]);
//                cout<<"go "<<tmp[l]<<endl;
                }
            }
            else
            {
                s1(i);
                if(ST[i].empty())
                    printf("Empty!\n");
                else
                    printf("%d\n", ST[i].top());
            }
        }



    }




    return 0;
}

/*

5 3 1103


*/
