#include <bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long cas=1,tmpn,n,ar[305][305],mx[305][305],i,j,k,sum=0;
        while(cin>>n &&n)
        {
                tmpn=100+n;
                for(i=0;i<305;i++)
                        for(j=0;j<305;j++)
                        ar[i][j]=0;
                for(i=100;i<tmpn;i++)
                {
                        for(j=100;j<tmpn;j++)
                                cin>>ar[i][j];
                }
                int res=INT_MIN,tmpres;
                for(i=100;i<tmpn;i++)
                {
                                for(j=100;j<tmpn;j++)
                                {
                                        int l1,l2,l3,l4,z1,z2,z3,z4,z5,z6,z7,z8,k1,k2,k3,k4,t1,t2,t3,t4,s1,s2,s3,s4;

                                        int tmp[200];

                                        tmp[0]=l1=ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i][j+3];
                                        tmp[1]=l2=ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+3][j];
                                        tmp[2]=l3=ar[i][j]+ar[i][j-1]+ar[i][j-2]+ar[i][j-3];
                                        tmp[3]=l4=ar[i][j]+ar[i-1][j]+ar[i-2][j]+ar[i-3][j];


                                        tmp[4]=z1=ar[i][j]+ar[i][j+1]+ar[i+1][j+1]+ar[i+1][j+2];
                                        tmp[5]=z2=ar[i][j]+ar[i+1][j]+ar[i+1][j-1]+ar[i+2][j-1];
                                        tmp[6]=z3=ar[i][j]+ar[i][j-1]+ar[i-1][j-1]+ar[i-1][j-2];
                                        tmp[7]=z4=ar[i][j]+ar[i-1][j]+ar[i-1][j+1]+ar[i-2][j+1];

                                        tmp[8]=k1=ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i+1][j+2];
                                        tmp[9]=k2=ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+2][j-1];
                                        tmp[10]=k3=ar[i][j]+ar[i][j-1]+ar[i][j-2]+ar[i-1][j-2];
                                        tmp[11]=k4=ar[i][j]+ar[i-1][j]+ar[i-2][j]+ar[i-2][j+1];


                                        tmp[12]=t1=ar[i][j]+ar[i][j+1]+ar[i][j+2]+ar[i+1][j+1];
                                        tmp[13]=t2=ar[i][j]+ar[i+1][j]+ar[i+2][j]+ar[i+1][j-1];
                                        tmp[14]=t3=ar[i][j]+ar[i][j-1]+ar[i][j-2]+ar[i-1][j-1];
                                        tmp[15]=t4=ar[i][j]+ar[i-1][j]+ar[i-2][j]+ar[i-1][j+1];


                                        tmp[16]=s1=ar[i][j]+ar[i][j+1]+ar[i+1][j]+ar[i+1][j+1];
                                        tmp[17]=s2=ar[i][j]+ar[i+1][j]+ar[i+1][j-1]+ar[i][j-1];
                                        tmp[18]=s3=ar[i][j]+ar[i][j-1]+ar[i-1][j-1]+ar[i-1][j];
                                        tmp[19]=s4=ar[i][j]+ar[i-1][j]+ar[i-1][j+1]+ar[i][j+1];

                                        sort(tmp,tmp+20);
                                        res=max(res,tmp[19]);
                                }
                }
                cout<<cas<<". ";
                cout<<res<<endl;
                cas++;
        }
        return 0;
}
