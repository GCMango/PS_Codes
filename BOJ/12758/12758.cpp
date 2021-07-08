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

    const int MOD = 1e9 + 7;
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> arr(N), a, b;
        vector<vector<int>> dp(2, vector<int>(1000001, 0));
        for (int i = 0; i < N; ++i) {
            int n = i % 2;
            cin >> arr[i];
            a = b;
            b.clear(); b.push_back(0);
            for (int j = 1; j * j <= arr[i]; ++j) {
                if (arr[i] % j == 0) {
                    b.push_back(j);
                    b.push_back(arr[i] / j);
                }
            }
            sort(all(b)); b.erase(unique(all(b)), b.end());
            if (!i) {
                for (int j = 1; j < b.size(); ++j) dp[n][b[j]] = dp[n][b[j - 1]] + 1;
                continue;
            }
            for (int j = 1; j < b.size(); ++j) {
                auto pos = upper_bound(all(a), b[j]) - a.begin() - 1;
                dp[n][b[j]] = (dp[!n][a[pos]] + dp[n][b[j - 1]]) % MOD;
            }
        }
        cout << dp[(N - 1) % 2][b.back()] << '\n';
    }

    return 0;
}

