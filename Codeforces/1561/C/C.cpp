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
        int N; cin >> N;
        vector<vector<int>> arr(N);
        vector<pii> order(N);
        for (int i = 0; i < N; ++i) {
            int n; cin >> n;
            int mx = 0;
            for (int j = 0; j < n; ++j) {
                int k; cin >> k;
                arr[i].push_back(k);
                mx = max(mx, k - j + 1);
            }
            order[i] = {i, mx};
        }
        sort(all(order), [&](auto &a, auto &b) { return a.y < b.y; });
        vector<int> v;
        for (auto &[i, _] : order)
            for (auto &j : arr[i]) v.push_back(j);
        int ans = 0;
        for (int i = 0; i < (int)v.size(); ++i)
            ans = max(ans, v[i] - i + 1);
        cout << ans << '\n';
    }

    return 0;
}
