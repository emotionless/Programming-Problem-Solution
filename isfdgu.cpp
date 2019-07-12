#include<iostream>

using namespace std;
class graph
{
private:
    int n;
    int data[20];
    int gptr[20][20];
public:
    void create();
    void topological();
};
void graph::create()
{
//   cout<<”**********************************************************\n”<<”This program sorts the given numbers in increasing order\n”<<”\t\t using topological sorting\n”<<”***********************************************************\n";
    cout<<"Enter the no. of nodes in the directed unweighted graph ::";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"enter data for the node “<<i<<” ::";
        cin>>data[i];
    }
    int j;
    for(int i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cin>>gptr[i][j];
    }
}
void graph::topological()
{
    int flag;
    int i,j;
    int poset[20],included[20];
    for(i=1; i<=n; i++)
    {
        poset[i]=0;
        included[i]=false;
    }
    int k=1;
    flag=true;
    int zeroindegree;
    int c=1;
    while(flag==1)
    {
        for(i=1; i<=n; i++)
        {
            if(!included[i])
            {
                zeroindegree=true;
                for(j=1; j<=n; j++)
                {
                    if(gptr[j][i]>0)
                    {
                        zeroindegree=false;
                        break;
                    }
                }

                if(zeroindegree)
                {
                    included[i]=true;
                    poset[k]=data[i];
                    k=k+1;
                    for(j=1; j<=n; j++)
                    {
                        gptr[i][j]=-1;
                        gptr[j][i]=-1;
                    }
                    break;
                }
            }
        }
        if(i==n+1)
        {
            if(zeroindegree==false)
            {
                cout<<"Graph is not acyclic\n";
                return;
            }
            else
            {
                poset[k]=data[i-1];
                k=k+1;
                flag=false;
            }
        }
    }
    cout<<"After topological sorting the numbers are :\n";
    for(i=1; i<=n; i++)
        cout<<poset[i]<<"\t";

    cout<<endl<<endl;
}
int main()
{
    graph obj;
    obj.create();
    obj.topological();
    return 0;
}
