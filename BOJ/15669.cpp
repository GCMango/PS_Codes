#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M, a, b, c;
int a1, a2, b1, b2;
vector<vector<int>> graph;
vector<int> depth;

void solve(int cur, int pnode, int n) {
    if (abs(depth[cur] - depth[n == 0 ? a : b]) % 2 == 0)
        n == 0 ? a1++ : b1++;
    else
        n == 0 ? a2++ : b2++;
    for (auto next : graph[cur]) {
        if (next == pnode || next == a || next == b) continue;
        depth[next] = depth[cur] + 1;
        solve(next, cur, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    depth.resize(N + 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    while (M--) {
        cin >> a >> b >> c;
        a1 = a2 = b1 = b2 = 0;
        solve(a, 0, 0);
        solve(b, 0, 1);
        //cout << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << "\n";
        if (c == 0)
            cout << a1 * b2 + a2 * b1 << "\n";
        else
            cout << a1 * b1 + a2 * b2 << "\n";
    }

    return 0;
}
