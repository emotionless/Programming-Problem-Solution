#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second
#define pi pair<int, int>
#define mp make_pair
#define fr(i, a) for(i = 0; i < a; i++)
#define sc(a) scanf("%d", &a)

///***** Constant ******//
#define MX 10007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7
#define ull unsigned LL

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int i, j, k;

ull make_bit(int b[8][8])
{
    ull ret = 0ull;
    for(int i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(b[i][j])
                ret = ret | (1ull<<(i*8+j));
        }
    }
    return ret;
}

int cur[8][8];


void make_grid(ull mask)
{
    for(int i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            cur[i][j] = 0;
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if((1ull<<(i*8+j))&mask)
                cur[i][j] = 1;
        }
    }
}




int start[8][8];
int end[8][8];

bool outside(int a, int b)
{
    if(a >= 8 || a < 0 || b >= 8 || b < 0) return true;
    return false;
}


void go(set<ull> &S, ull curr)
{
    queue<ull>Q;
    queue<int>dis;
    Q.push(curr);
    dis.push(0);

    while(!Q.empty())
    {
        ull top = Q.front();
        Q.pop();
        int cc = dis.front();
        dis.pop();
        if(cc >= 4) continue;
        make_grid(top);
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(!cur[i][j]) continue;

                for(int k = 0; k < 4; k++)
                {
                    int adi = i + dr[k];
                    int adj = j + dc[k];
                    if(outside(adi, adj)) continue;
                    if(cur[adi][adj])
                    {
                        adi += dr[k];
                        adj += dc[k];
                        if(outside(adi, adj)) continue;
                    }
                    swap(cur[i][j], cur[adi][adj]);
                    ull nxt_mask = make_bit(cur);
                    if(S.find(nxt_mask) == S.end())
                    {
                        S.insert(nxt_mask);
                        Q.push(nxt_mask);
                        dis.push(cc + 1);
//                        cout<<nxt_mask<<endl;
                    }
                    swap(cur[i][j], cur[adi][adj]);
                }
            }
        }
    }
}


int main()
{
    int i,j,k;
    int cases=1;
    int t, a, b;
    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        memset(start, 0, sizeof start);
        memset(end, 0, sizeof end);
        for(i = 0; i < 4; i++)
        {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            start[a][b]++;
        }

        set<ull>S1;
        S1.clear();
        S1.insert(make_bit(start));

        for(i = 0; i < 4; i++)
        {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            end[a][b]++;
        }

        set<ull>S2;
        S2.clear();
        S2.insert(make_bit(end));
//    cout<<make_bit(start)<<endl;
//    cout<<make_bit(end)<<endl;
        go(S1, make_bit(start));
        go(S2, make_bit(end));
        bool ck = false;
        for(set<ull>::iterator i = S1.begin(); i != S1.end(); i++)
        {
            if(S2.count(*i) > 0)
            {
                ck = 1;
                printf("YES\n");
                break;
            }
        }
        if(!ck)
            printf("NO\n");

    }

    return 0;
}
/*

4 4 4 5 5 4 6 5
4 4 4 5 5 5 6 5


*/
