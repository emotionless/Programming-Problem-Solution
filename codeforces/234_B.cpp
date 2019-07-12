#include<bits/stdc++.h>

#define LL long long
#define inf 1000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define MOD 1000000007ll
#define MP make_pair
#define MX 100000

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n,m;
    cin>>n>>m;
    bool say=true;
    set<int>S;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        int ar[m+5],g=0;
        memset(ar,0,sizeof ar);
        for(int j=0;j<m;j++){
            if(str[j]=='S'){
                say=false;
                break;
            }
            if(str[j]=='G'){
                g++;
                int k=j+1;
                while(k<m){
                    if(str[k]=='G') break;
                    if(str[k]=='S') ar[k-j]++;
                    k++;
                }
                if(k==j+1){
                    say=false;
                    break;
                }
                j=k-1;
            }
        }
        bool chk=false;
        for(int j=1;j<=m;j++){
            if(ar[j]==g){
                S.insert(j);
                chk=true;
                break;
            }
        }
        if(!chk) say=false;
    }
    if(say) cout<<S.size()<<endl;
    else cout<<-1<<endl;
    return 0;
}
