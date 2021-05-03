#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
vector<vector<int>> arr;
vector<int> dp;

int solve(int cur, int pnode) {
    for (auto node : arr[cur])
        if (node != pnode)
            dp[cur] += solve(node, cur);

    return dp[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;
    arr.resize(N + 1);
    dp.resize(N + 1, 1);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    solve(R, 0);

    while (Q--) {
        int query;
        cin >> query;
        cout << dp[query] << "\n";
    }

    return 0;
}

