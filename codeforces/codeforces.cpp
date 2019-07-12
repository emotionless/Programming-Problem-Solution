#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string lcs[1005][1005];
string a,b;
int al,bl;

void lcs_function(){
    for(int i=1;i<=al;i++){
        for(int j=1;j<=bl;j++){
            if(a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+a[i-1];
            else if(lcs[i-1][j].length()>lcs[i][j-1].length()) lcs[i][j]=lcs[i-1][j];
            else if(lcs[i-1][j].length()<lcs[i][j-1].length()) lcs[i][j]=lcs[i][j-1];
            else lcs[i][j]=min(lcs[i-1][j],lcs[i][j-1]);
        }
    }
}

int main()
{

    cin>>a>>b;

    al=a.length();
    bl=b.length();

    for(int i=0;i<=al;i++) lcs[i][0]="";
    for(int j=0;j<=bl;j++) lcs[0][j]="";

    lcs_function();
    string ans=lcs[al][bl];
    string hold=ans;
    reverse(ans.begin(),ans.end());
    cout<<min(hold,ans)<<endl;
    return 0;
}
