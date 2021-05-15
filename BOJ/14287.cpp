#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, cnt = 0;
vector<vector<int>> graph;
vector<pii> range;
vector<int> tree;

void init_tree(int cur) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        init_tree(next);
    range[cur].y = cnt;
}

void update_tree(int start, int fin, int cur, int idx, int val) {
    if (idx < start || idx > fin) return;
    if (idx >= start && idx <= fin)
        tree[cur] += val;
    if (start == fin) return;

    int mid = (start + fin) / 2;
    update_tree(start, mid, cur * 2, idx, val);
    update_tree(mid + 1, fin, cur * 2 + 1, idx, val);
}

int get_val(int start, int fin, int cur, int left, int right) {
    if (right < start || left > fin) return 0;
    if (left <= start && right >= fin) return tree[cur];

    int mid = (start + fin) / 2;

    return get_val(start, mid, cur * 2, left, right) + get_val(mid + 1, fin, cur * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    range.resize(N + 1);
    tree.resize(N * 4);

    for (int i = 1; i <= N; ++i) {
        int n;
        cin >> n;
        if (n == -1) continue;
        graph[n].push_back(i);
    }

    init_tree(1);

    while (M--) {
        int n, a, b;
        cin >> n;
        if (n == 1) {
            cin >> a >> b;
            update_tree(1, N, 1, range[a].x, b);
        }
        else {
            cin >> a;
            cout << get_val(1, N, 1, range[a].x, range[a].y) << '\n';
        }
    }

    return 0;
}
