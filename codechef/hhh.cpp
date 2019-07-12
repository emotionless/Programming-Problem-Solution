#include<bits/stdc++.h>

using namespace std;

struct data{
    int njoy,voy;
};
data ar[1005][4];
int fun[1005],diz[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n,k,l;
    while(cin>>n>>k>>l){
        if(n==0 && k==0 && l==0) break;
        for(int i=0;i<n;i++){
            cin>>fun[i]>>diz[i];
        }
        ar[0][1].njoy=fun[0];
        ar[0][1].voy=diz[0];

        if(ar[0][1].voy>l){
            ar[0][1].njoy=0;
            ar[0][1].voy=0;
        }
        ar[0][0].njoy=0;
        ar[0][0].voy=0;
        int i;
        for(i=1;i<n;i++){
            data OFF_ON,OFF_OFF,ON_ON,ON_OFF;

            OFF_ON.njoy=ar[i-1][0].njoy+fun[i];
            OFF_ON.voy=ar[i-1][0].voy+diz[i];

            ON_ON.njoy=ar[i-1][1].njoy+fun[i];
            ON_ON.voy=ar[i-1][1].voy+diz[i];

            if(ON_ON.voy<=l && OFF_ON.voy<=l){
                if(ON_ON.njoy==OFF_ON.njoy){
                    if(ON_ON.voy<OFF_ON.voy) ar[i][1]=ON_ON;
                    else ar[i][1]=OFF_ON;
                }
                else if(ON_ON.njoy>OFF_ON.njoy) ar[i][1]=ON_ON;
                else ar[i][1]=OFF_ON;
            }
            else if(ON_ON.voy<=l) ar[i][1]=ON_ON;
            else if(OFF_ON.voy<=l) ar[i][1]=OFF_ON;
            else{
               break;
            }
            ON_OFF.njoy=ar[i-1][1].njoy;
            ON_OFF.voy=ar[i-1][1].voy-k;

            OFF_OFF.njoy=ar[i-1][0].njoy;
            OFF_OFF.voy=ar[i-1][0].voy-k;
            if(OFF_OFF.voy>=0 && ON_OFF.voy>=0){
                if(ON_OFF.njoy==OFF_OFF.njoy){
                    if(ON_OFF.voy<OFF_OFF.voy) ar[i][0]=ON_OFF;
                    else ar[i][0]=OFF_OFF;
                }
                else if(ON_OFF.njoy>OFF_OFF.njoy) ar[i][0]=ON_OFF;
                else ar[i][0]=OFF_OFF;
            }
            else if(OFF_OFF.voy>=0) ar[i][0]=OFF_OFF;
            else if(ON_OFF.voy>=0) ar[i][0]=ON_OFF;
            else{
                break;
            }
        }
        if(i==n)
        cout<<max(ar[n-1][0].njoy,ar[n-1][1].njoy)<<endl;
        else cout<<0<<endl;
        memset(ar,0,sizeof ar);
    }
    return 0;
}

