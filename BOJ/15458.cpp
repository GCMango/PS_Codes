#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, K;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> col;

void solve(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next == pnode) continue;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    graph.resize(N + 1);
    dp.resize(N + 1, vector<int>(4));
    col.resize(N + 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    return 0;
}
