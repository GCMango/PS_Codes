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

struct comp { bool operator()(pii &a, pii &b) { return a.y > b.y; } };

void solve() {
    const int MXN = 100000;
    int N, M, X, arr[MXN], ans[MXN] = {0, };
    priority_queue<pii, vector<pii>, comp> pq;
    cin >> N >> M >> X;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < M; ++i) pq.push({i, 0});

    cout << "YES\n";

    for (int i = 0; i < N; ++i) {
        pii cur = pq.top();
        pq.pop();
        ans[cur.x] += arr[i];
        pq.push({cur.x, ans[cur.x]});
        cout << cur.x + 1 << ' ';
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}

