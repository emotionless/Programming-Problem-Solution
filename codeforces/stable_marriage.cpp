
int mat[2*MAX][MAX];
int wPartner[MAX];
int mFree[MAX];
int take[2*MAX][2*MAX];
int n;

bool wPrefersM1OverM(int w, int m, int m1)
{
    if(take[w][m1] < take[w][m]) return true;
    return false;
}

void solve(int n)
{
    clr(wPartner, -1);
    clr(mFree, false);

    int freeCnt = n, i;
    int m, w, m1;
    while(freeCnt > 0)
    {
        for( i = 1; i <= n; i++)
        {
            if(mFree[i] == false)
            {
                m = i;
                break;
            }
        }

        for( i = 1; i <= n && mFree[m] == false; i++)
        {
            w = mat[m][i];

            if(wPartner[w-n] == -1)
            {
                wPartner[w-n] = m;
                mFree[m] = true;
                freeCnt--;
                break;
            }
            else
            {
                m1 = wPartner[w-n];
                if(wPrefersM1OverM(w, m, m1) == false)
                {
                    wPartner[w-n] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                    break;
                }
            }
        }
    }

    for( i = 1; i <= n; i++)
        printf(" (%d %d)", wPartner[i], i+n);

    return;
}


int main()
{
    int m, i, j, k, cases = 1;
    sc(t);
    while(t--)
    {
        sc(n);
        for(i = 1; i <= 2*n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                sc(mat[i][j]);
                take[i][ mat[i][j] ] = j;
            }
        }
        printf("Case %d:", cases++);
        solve(n);
        printf("\n");
    }

    return 0;
}

/**********************************************/


/************ Multi-mod**********
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}

