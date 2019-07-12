

#include<iostream>
using namespace std;
int v[10];
int sum,half;
bool flag;
void DFS(int vaule,int pre)
{
    //cout<<"YES";
    int i;
    if(vaule>half)
    {
        return;
    }
    if(flag)
        return ;
    if(vaule ==half)
    {
        flag=true;
        return;
    }
    for(i=pre; i>0; i--)
    {
        if(v[i]>0)
        {
            if(vaule+i<=half)
            {
                v[i]--;
                DFS(vaule+i,i);//这里为什么下一次要从i开始想想就知道了，因为这是递归，第一个会一次次比上一次多一个然后向下递归
                if(flag)
                    break;

            }
        }


    }
}

int main()
{
    int i,j=0;

    while(1)
    {
        j++;
        flag=false;
        sum=0;
        for(i=1; i<=6; i++)
        {
            cin>>v[i];
            sum+=v[i]*i;
        }
        if(sum==0)
            return 0;
        if(sum%2!=0)
        {
            cout<<"Collection #"<<j<<':'<<endl;
            cout<<"Can't be divided."<<endl;
            cout<<endl;
            continue;
        }
        half=sum/2;
        DFS(0,6);
        if(flag)
        {
            cout<<"Collection #"<<j<<':'<<endl;
            cout<<"Can be divided."<<endl<<endl;
            continue;
        }
        else
        {
            cout<<"Collection #"<<j<<':'<<endl;
            cout<<"Can't be divided."<<endl<<endl;
            continue;
        }

    }
    return 0;
}
