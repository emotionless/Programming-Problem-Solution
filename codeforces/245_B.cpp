#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;
vector<int>V, tmp;
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n, m, k;
    cin>>n>>k>>m;
    for(i=0; i<n; i++)
    {
        cin>>a;
        V.PB(a);
    }
    tmp=V;
    int mx=0;

    for(i=1; i<n; i++)
    {
        tmp=V;
        if(tmp[i]==tmp[i-1] && tmp[i]==m)
        {
            int ind=i;
            tmp.erase(tmp.begin()+ind-1);
            tmp.erase(tmp.begin()+ind-1);
            //  cout<<i<<" "<<tmp[i-1]<<" "<<tmp[i]<<" "<<tmp[i+1]<<endl;
            bool c=false;
            for(j=0; j<tmp.size(); j++)
            {
                c=false;
                if(j+2<tmp.size() && tmp[j]==tmp[j+1] && tmp[j]==tmp[j+2])
                {
                    while(tmp[j]==tmp[j+1] && j+1<tmp.size())
                    {
                        tmp.erase(tmp.begin()+j);
                        c=true;
                    }
                    tmp.erase(tmp.begin()+j);

                }
                if(c)
                    j=(-1);
            }
          //  for(int o=0; o<tmp.size(); o++)
           //     cout<<tmp[o]<<" ";
            mx=max(mx, (int)(V.size()-tmp.size()));
        }
    }
    cout<<mx<<endl;





    return 0;
}

/*

8 2 1
1 1 2 1 1 2 2 1

*/
