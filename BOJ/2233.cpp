#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, a, b;
string s;
vector<vector<int>> graph;
vector<int> par;
vector<int> depth;
vector<p> result;

void solve(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next != pnode) {
            depth[next] = depth[cur] + 1;
            solve(next, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> s >> a >> b;
    graph.resize(N + 2);
    par.resize(N + 2);
    depth.resize(N + 2, 0);
    result.resize(N + 2, {0, 0});

    int cur = 0, cnt = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            graph[cur].push_back(cnt);
            par[cnt] = cur;
            cur = cnt;
            result[cnt].x = i + 1;
            cnt++;
        }
        else {
            result[cur].y = i + 1;
            cur = par[cur];
        }
    }

    /*for (int i = 1; i <= N + 1; ++i) {
        cout << i << ' ';
        for (auto node : graph[i])
            cout << node << ' ';
        cout << "\n";
    }*/

    solve(1, 0);

    for (int i = 1; i <= N; ++i) {
        if (result[i].x == a || result[i].y == a) {
            a = i;
            break;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (result[i].x == b || result[i].y == b) {
            b = i;
            break;
        }
    }

    while (depth[a] != depth[b]) {
        if (depth[a] > depth[b])
            a = par[a];
        else
            b = par[b];
    }
    while (a != b) {
        a = par[a];
        b = par[b];
    }
    int lca = a;

    cout << result[lca].x << ' ' << result[lca].y << "\n";

    return 0;
}
