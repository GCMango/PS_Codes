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

void solve() {
    int N, ans, mn = 1e9, arr[303];
    bool ok = 1;
    cin >> N;
    arr[0] = 0;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    sort(arr, arr + N + 1);
    for (int i = 0; i < N; ++i)
        if (arr[i + 1] - arr[i])
            mn = min(mn, arr[i + 1] - arr[i]);
    for (int i = 0; i < N; ++i)
        if ((arr[i + 1] - arr[i]) % mn) { ok = 0; break; }
    if (ok) ans = (arr[N] - min(mn, arr[1])) / mn + 1;
    else { ans = arr[N]; mn = 1; }
    if (arr[0] < 0 || ans > 300) { cout << "NO\n"; return; }
    cout << "YES\n" << ans << '\n';
    for (int i = min(mn, arr[1]); i <= arr[N]; i += mn)
        cout << i << ' ';
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

// 1 2 3 4 5 6 7 8 9 10 12 16

// 1 3 4 6 8
