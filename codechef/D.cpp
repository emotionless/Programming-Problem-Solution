/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MAX 1562501
#define MOD 1000000007
#define N 1000007
#define PB push_back
#define set_mask(a,b) (a|(1<<b))


using namespace std;


vector<int>V[100001];
int arr[100001];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n,p,m;
    int x,y;
    cin>>n>>m>>p;
    for(i=0; i<p; i++)
    {
        cin>>x>>y;
        V[x].PB(y);
        if(y==m)
            arr[x]++;
    }
    for(i=1; i<=n; i++)
    {
        sort(V[i].begin(), V[i].end());
        int sz=V[i].size();
        map<int, int>M;
        int tot=0;
        M[m+1]=1000001;
        for(j=sz-1; j>=0; j--)
        {
            //  cout<<V[i][j]<<" ";
            M[V[i][j]]++;
            if(M[V[i][j]]>M[V[i][j]+1]+1)
                break;
        }
        if(j==(-1))
            cout<<m+arr[i]-1-M[1]<<endl;
        else
            cout<<-1<<endl;
        // cout<<endl;
    }

    return 0;
}

/*

4 4 7
2 2
3 2
3 2
4 3
4 4
1 1
1 1


*/
