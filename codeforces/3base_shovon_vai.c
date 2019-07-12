/// ******** 3 base bitmask *******///
int n,m;
int g[20][20];
int W[20],C[20];
int dp[11][60000];
int three[15];
string make(int nn)
{
    string str;
    FOR(i,0,n)str=str+"0";
    int i=0;
    while(nn)
    {
        str[i]=('0'+ nn%3);
        nn/=3;
        i++;
    }
    //reverse(arr,arr+i);
    return str;
}

int toint(string str)
{

    int cur=0;
    for(int i=0; i<n; i++)
    {
        int x=str[i]-'0';
        cur=cur+(x)*three[i];
    }
    return cur;
}


int solve(int pos  , int mask)
{

    //cout<<pos<<" "<<mask<<" "<<n<<endl;

    if(dp[pos][mask]!=-1)return dp[pos][mask];
    int &ret=dp[pos][mask]=0;

    string str=make(mask);
    for(int i=0; i<n; i++)
    {
        if(pos==i)continue;
        if(g[pos][i]==0)continue;
        if(str[i]=='0')
        {
            str[i]='1';
            int nmask=toint(str);
            ret=max(ret,solve(i,nmask)+C[i] );
            str[i]='0';
        }
        else if(str[i]=='1' && W[i]==2)
        {
            str[i]='2';
            int nmask=toint(str);
            ret=max(ret,solve(i,nmask));
            str[i]='1';
        }
    }
    return ret;
}

int main()
{



    int i,j,k;
    int cas,ks;
    n=6;
    three[0]=1;
    FOR(i,1,11)
    {
        three[i]=3*three[i-1];
    }



    cin>>ks;

    FOR(cas,1,ks+1)
    {
        cin>>n>>m;
        FOR(i,0,n)
        {
            scanf("%d",&W[i]);
        }
        FOR(i,0,n)
        {
            scanf("%d",&C[i]);
        }
        SET(g,0);
        int x,y;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            g[x][y]=g[y][x]=1;
        }
        int res=0;
        string str="";
        FOR(i,0,n)str=str+"0";
        SET(dp,-1);
        for(i=0; i<n; i++)
        {
            str[i]='1';
            int mask_val=toint(str);
            res=max(res,solve( i, mask_val )+C[i] );
            str[i]='0';
        }
        printf("Case %d: %d\n",cas,res);
    }

}
