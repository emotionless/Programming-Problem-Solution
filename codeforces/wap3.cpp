#include <bits/stdc++.h>


using namespace std;

string mat[10];

int N, M, K;

map< pair< pair<int, int>, vector<int> >, int> MP;

// set this value true if solution finds.
bool check;

bool canDifferentiate(int ind, vector<int> V, int rest)
{
    if(check == true) return 1;
    if(ind == N*M)
    {
        set<int>S;
        for(int i = 0; i < K; i++)
        {
            S.insert(V[i]);
        }
        if(S.size() == K)
        {
            // solution found...
            check = 1;
            return true;
        }
        return false;
    }
    pair<int,int> p = make_pair(ind, rest);
    pair< pair<int, int>, vector<int> > ret = make_pair(p, V);
    if(MP.find(ret) != MP.end()) return MP[ret];
    MP[ret] = 0;
    int res = 0;
    res = canDifferentiate(ind + 1, V, rest);
    if(rest > 0)
    {
        vector<int> tmp;
        for(int i = 0; i < K; i++)
            tmp.push_back(V[i]*2 + (mat[i][ind]-'0'));
        res += canDifferentiate(ind + 1, tmp, rest - 1);
    }
    return MP[ret] = res;
}


int main()
{
    int i, j;
    string str;

    cin >> N >> M >> K;
    int block;
    for(block = 0; block < K; block++)
    {
        for(int i = 0; i < N; i++)
        {
            cin>>str;
            mat[block] += str;
        }
    }
    // see how the blocks look like
    //for(i = 0; i < K; i++)
    //    cout<<mat[i]<<endl;

    vector<int>V;
    for(i = 0; i < K; i++)
        V.push_back(0);

    for(i = 1; i <= K; i++)
    {
        if(canDifferentiate(0, V, i))
        {
            cout<<i<<endl;
            return 0;
        }

        //cout<<"not found in: "<<i<<endl;

    }
    // create a runtime error if not found by K bits

    assert(0);


return 0;
}

/*


1 4 8
0000
0001
0100
1011
1001
1100
1111
0101

*/
