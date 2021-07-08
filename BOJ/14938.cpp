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

int N, M, R, arr[101], dist[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(&dist[0][0], &dist[100][101], 1e9);
    cin >> N >> M >> R;
    for (int i = 1; i <= N; ++i) { cin >> arr[i]; dist[i][i] = 0; }
    for (int i = 0; i < R; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int comp = 0;
        for (int j = 1; j <= N; ++j)
            if (dist[i][j] <= M)
                comp += arr[j];
        ans = max(ans, comp);
    }
    cout << ans << '\n';

    return 0;
}
