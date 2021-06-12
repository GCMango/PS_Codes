#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
double dp[101][101];
pii pos[101];

double dist(pii &a, pii &b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

double dfs(int s, int e) {
    if (s == N - 1 || e == N - 1) return dist(pos[s], pos[N - 1]) + dist(pos[e], pos[N - 1]);
    if (dp[s][e]) return dp[s][e];
    int next = max(s, e) + 1;
    double a = 0, b = 0;
    if (s < N - 1)
        a = dfs(next, e) + dist(pos[s], pos[next]);
    if (e < N - 1)
        b = dfs(s, next) + dist(pos[e], pos[next]);
    return dp[s][e] = min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> pos[i].x >> pos[i].y;
    sort(pos, pos + N, [&](pii &a, pii &b) { return a.x < b.x; });
    printf("%.2lf\n", dfs(0, 0));

    return 0;
}
