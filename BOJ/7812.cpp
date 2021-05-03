#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N;
ll mn;
vector<ll> cnt, sum;
vector<vector<p>> graph;

void get_tree(int cur, int pnode) {
    cnt[cur] = 1;

    for (int i = 0; i < graph[cur].size(); ++i) {
        if (graph[cur][i].x == pnode) continue;
        int next = graph[cur][i].x;
        int cost = graph[cur][i].y;
        get_tree(next, cur);
        cnt[cur] += cnt[next];
        sum[cur] += cnt[next] * cost + sum[next];
    }
}

void get_sum(int cur, int pnode) {
    for (int i = 0; i < graph[cur].size(); ++i) {
        if (graph[cur][i].x == pnode) continue;
        int next = graph[cur][i].x;
        int cost = graph[cur][i].y;
        ll csum = sum[cur];
        csum -= cost * cnt[next];
        csum += (N - cnt[next]) * cost;
        sum[next] = csum;
        get_sum(next, cur);
    }
    mn = min(mn, sum[cur]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        cin >> N;
        if (N == 0) break;

        graph.clear();
        graph.resize(N);
        cnt.clear();
        sum.clear();
        cnt = sum = vector<ll>(N);
        mn = 1e18;
        for (int i = 0; i < N - 1; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        get_tree(0, 0);
        get_sum(0, 0);

        cout << mn << "\n";
    }

    return 0;
}
