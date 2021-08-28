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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int M; cin >> M;
        vector<vector<int>> arr(2, vector<int>(M));
        vector<int> sa(M), sb(M);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < M; ++j)
                cin >> arr[i][j];
        sa[0] = arr[1][0], sb[M - 1] = arr[0][M - 1];
        for (int i = 1; i < M; ++i) sa[i] = sa[i - 1] + arr[1][i];
        for (int i = M - 2; i >= 0; --i) sb[i] = sb[i + 1] + arr[0][i];
        int ans = 1e9;
        for (int i = 0; i < M; ++i)
            ans = min(ans, max((i ? sa[i - 1] : 0), (i < M - 1 ? sb[i + 1] : 0)));
        cout << ans << '\n';
    }

    return 0;
}
