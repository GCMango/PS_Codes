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

int N, K;
ll a[100001], mx, cnt;
vector<int> graph[100001];

ll dfs(int cur, int pnode = -1) {
    ll now = a[cur];
    priority_queue<ll> pq;

    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        ll t = dfs(next, cur);
        now += t;
        pq.push(t);
    }

    while (!pq.empty() && now > mx) {
        now -= pq.top();
        pq.pop();
        cnt++;
    }

    return now;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll sum = 0;

        for (int i = 1; i <= N; ++i) cin >> a[i], sum += a[i], graph[i].clear();
        for (int i = 1; i < N; ++i) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        ll l = *max_element(a + 1, a + N + 1), r = sum;
        while (l < r) {
            ll m = (l + r) / 2;
            mx = m; cnt = 0;
            dfs(1);
            if (cnt <= K) r = m;
            else l = m + 1;
        }

        cout << r << '\n';
    }

    return 0;
}
