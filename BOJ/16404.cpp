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
vector<pii> money;

void init_tree(int cur) {
    range[cur].x = ++cnt;
    for (auto next : graph[cur])
        init_tree(next);
    range[cur].y = cnt;
}

void update_tree(int start, int fin, int cur, int left, int right, int val) {
    if (money[cur].y != 0) {
        money[cur].x += (fin - start + 1) * money[cur].y;
        if (start != fin) {
            money[cur * 2].y += money[cur].y;
            money[cur * 2 + 1].y += money[cur].y;
        }
        money[cur].y = 0;
    }
    
    if (right < start || left > fin) return;

    if (left <= start && fin <= right) {
        money[cur].x += (fin - start + 1) * val;
        if (start != fin) {
            money[cur * 2].y += val;
            money[cur * 2 + 1].y += val;
        }
        return;
    }

    int mid = (start + fin) / 2;

    update_tree(start, mid, cur * 2, left, right, val);
    update_tree(mid + 1, fin, cur * 2 + 1, left, right, val);

    money[cur].x = money[cur * 2].x + money[cur * 2 + 1].x;
}

int get_money(int start, int fin, int cur, int idx) {
    if (money[cur].y != 0) {
        money[cur].x += (fin - start + 1) * money[cur].y;
        if (start != fin) {
            money[cur * 2].y += money[cur].y;
            money[cur * 2 + 1].y += money[cur].y;
        }
        money[cur].y = 0;
    }

    if (idx < start || idx > fin) return 0;
    if (start == fin) return money[cur].x;

    int mid = (start + fin) / 2;

    return get_money(start, mid, cur * 2, idx) + get_money(mid + 1, fin, cur * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    range.resize(N + 1);
    money.resize(N * 4, {0, 0});
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
            update_tree(1, N, 1, range[a].x, range[a].y, b);
        }
        else {
            cin >> a;
            cout << get_money(1, N, 1, range[a].x) << "\n";
        }
    }

    return 0;
}
