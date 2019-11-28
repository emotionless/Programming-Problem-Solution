#include <message.h>
#include "sandwich.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using int_ = int;
#define int ll

void distributed(int left, int right) {
    int sum=0;
    vector<int> values(right-left);
    for (int i=left; i<right; ++i) {
        int x = GetTaste(i);
        sum += x;
        values[i-left] = x;
    }
    vector<int> prefix(values.size()+1);
    partial_sum(values.begin(), values.end(), prefix.begin()+1);
    {
        int m = 0;
        for (auto& x : prefix)
            m = x = max(x, m);
    }

    vector<int> suffix(values.size()+1);
    partial_sum(values.rbegin(), values.rend(), suffix.begin()+1);
    {
        int m = 0;
        for (auto& x : suffix)
            m = x = max(x, m);
    }
    reverse(suffix.begin(), suffix.end());

    int both=0;
    for (int i=0; i<=right-left; ++i) {
        int lhs = prefix[i];
        int rhs = suffix[i];
        both = max(both, lhs + rhs);
    }

    PutLL(0, sum);
    PutLL(0, prefix.back());
    PutLL(0, suffix.front());
    PutLL(0, both);
    Send(0);
}

int_ main() {
    int nodes = NumberOfNodes();
    int id = MyNodeId();

    auto n = GetN();
    auto left = n*id/nodes;
    auto right = n*(id+1)/nodes;
    distributed(left, right);

    if (id != 0)
        return 0;

    vector<int> sum(nodes);
    vector<int> partsum(nodes+1);
    vector<int> prefix(nodes);
    vector<int> suffix(nodes);
    vector<int> both(nodes);
    for (int i=0; i<nodes; ++i) {
        int x = Receive(-1);
        sum[x] = GetLL(x);
        prefix[x] = GetLL(x);
        suffix[x] = GetLL(x);
        both[x] = GetLL(x);
    }
    partial_sum(sum.begin(), sum.end(), partsum.begin()+1);

    int best=0;
    int best_prefix=0;
    for (int i=0; i<nodes; ++i) {
        best = max({
            best,
            best_prefix + suffix[i] + partsum.back() - partsum[i+1],
            both[i] + partsum.back() - sum[i]
        });
        best_prefix = max(best_prefix, partsum[i] + prefix[i]);
    }
    cout << best << '\n';
}
