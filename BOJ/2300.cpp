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

    int N, mx[10000], dp[10000];
    pii arr[10000];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + N, [&](pii &a, pii &b) { return a.x < b.x; });
    fill(dp, dp + N, 1e9);

    for (int i = 0; i < N; ++i) {
        for (int j = i; j >= 0; --j) {
            mx[i] = max({mx[i], abs(arr[j].y) * 2, arr[i].x - arr[j].x});
            dp[i] = min(dp[i], (j == 0 ? 0 : dp[j - 1]) + mx[i]);
        }
    }

    cout << dp[N - 1] << '\n';

    return 0;
}
