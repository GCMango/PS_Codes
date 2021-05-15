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
vector<pii> up;
vector<int> down;

void init_tree(int cur) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        init_tree(next);
    range[cur].y = cnt;
}

void update_up(int start, int fin, int cur, int left, int right, int val) {
    if (up[cur].y != 0) {
        up[cur].x += (fin - start + 1) * up[cur].y;
        if (start != fin) {
            up[cur * 2].y += up[cur].y;
            up[cur * 2 + 1].y += up[cur].y;
        }
        up[cur].y = 0;
    }

    if (right < start || left > fin) return;

    if (left <= start && fin <= right) {
        up[cur].x += (fin - start + 1) * val;
        if (start != fin) {
            up[cur * 2].y += val;
            up[cur * 2 + 1].y += val;
        }
        return;
    }

    int mid = (start + fin) / 2;
    update_up(start, mid, cur * 2, left, right, val);
    update_up(mid + 1, fin, cur * 2 + 1, left, right, val);
}

void update_down(int start, int fin, int cur, int idx, int val) {
    if (idx < start || idx > fin) return;
    if (idx >= start && idx <= fin)
        down[cur] += val;
    if (start == fin) return;

    int mid = (start + fin) / 2;
    update_down(start, mid, cur * 2, idx, val);
    update_down(mid + 1, fin, cur * 2 + 1, idx, val);
}

int get_up(int start, int fin, int cur, int idx) {
    if (up[cur].y != 0) {
        up[cur].x += up[cur].y;
        if (start != fin) {
            up[cur * 2].y += up[cur].y;
            up[cur * 2 + 1].y += up[cur].y;
        }
        up[cur].y = 0;
    }

    if (idx < start || idx > fin) return 0;
    if (idx <= start && fin <= idx) return up[cur].x;

    int mid = (start + fin) / 2;
    return get_up(start, mid, cur * 2, idx) + get_up(mid + 1, fin, cur * 2 + 1, idx);
}

int get_down(int start, int fin, int cur, int left, int right) {
    if (right < start || left > fin) return 0;
    if (left <= start && fin <= right) return down[cur];

    int mid = (start + fin) / 2;
    return get_down(start, mid, cur * 2, left, right) + get_down(mid + 1, fin, cur * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    range.resize(N + 1);
    up.resize(N * 4);
    down.resize(N * 4);

    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        if (n == -1) continue;
        graph[n].push_back(i);
    }

    init_tree(1);

    int option = 0;
    while (M--) {
        int n, a, b;
        cin >> n;
        if (n == 1) {
            cin >> a >> b;
            if (option == 0)
                update_up(1, N, 1, range[a].x, range[a].y, b);
            else
                update_down(1, N, 1, range[a].x, b);
        }
        else if (n == 2) {
            cin >> a;
            cout << get_up(1, N, 1, range[a].x) + get_down(1, N, 1, range[a].x, range[a].y) << '\n';
        }
        else
            option = !option;
    }

    return 0;
}
