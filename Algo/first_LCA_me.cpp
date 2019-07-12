#include<bits/stdc++.h>

#define LL long long

using namespace std;

int info[101];

void INSERT(int poss, long val)
{
    info[poss]=val;
}

int query1(int ind, int n1, int n2)
{
    if(info[ind]==n1 || info[ind]==n2) return -1;
    if(info[ind*2+1]==n1 || info[ind*2+1]==n2)
        return info[ind];
    if(info[ind*2]==n1 || info[ind*2]==n2)
        return info[ind];

    if(info[ind]>n1 && info[ind]>n2)
    {
        return query1(ind*2, n1, n2);
    }
    else if(info[ind]<n1 && info[ind]<n2)
    {
        return query1(ind*2+1, n1, n2);
    }
    else
    {
        return info[ind];
    }
}



int main()
{
    int i,k,j;
    int n, num, n1, n2;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>num;
        INSERT(i,num);
    }

    cin>>n1>>n2;
    int res=query1(1, n1, n2);
    cout<<res<<endl;

    return 0;
}
/*

            2
           / \
         1   4
             / \
           3   5


7
2 1 4 0 0 3 5
1 2

*/
