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

    bool dp[10000] = {0, };
    dp[0] = 1;
    for (int i = 0; i < 10000; ++i) {
        if (i >= 11) dp[i] |= dp[i - 11];
        if (i >= 111) dp[i] |= dp[i - 111];
    }

    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        if (N >= 10000) cout << "YES\n";
        else cout << (dp[N] ? "YES" : "NO") << '\n';
    }

    return 0;
}
