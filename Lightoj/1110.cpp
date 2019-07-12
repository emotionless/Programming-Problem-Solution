#include <bits/stdc++.h>




using namespace std;
string first, second;

string rec(int i, int j)
{
    if(i==n || j==m) return "";

    if(first[i]==second[j])
        return first[i]+ rec(i+1, j+1);
    //  string a=rec(n-1, m);
    // string b=rec(n, m-1);
    // if(a.length()==b.length())
    //     return min(a, b);
    return cmp(rec(n-1,m), rec(n, m-1));
}

string cmp(string a, string b)
{
    if(a.length()==b.length())
        return min(a,b);
    return max(a, b);
}



int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>first>>second;
        first=" "+first;
        second=" "+second;
        string res[101][101];
        int n=first.length();
        int m=second.length();

        for(i=1; i<n; i++)
        {
            for(j=1; j<m; j++)
            {
                if(first[i]==second[j])
                {
                    res[i][j]=res[i-1][j-1]+first[i];
                }
                else
                {
                    res[i][j]=cmp(res[i-1][j], res[i][j-1]);
                }
            }
        }
        cout<<"Case "<<cases<<": ";
        cases++;
        if(res[n-1][m-1].length())
            cout<<res[n-1][m-1]<<endl;
        else
            cout<<":("<<endl;


    }
    return 0;
}
