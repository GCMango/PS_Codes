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
    int N, sum = 0, ans = 0, arr[200002];
    cin >> N;
    for (int i = 0; i < N; ++i) { cin >> arr[i]; sum += arr[i]; }
    if (sum % N) {
        cout << "-1\n";
        return;
    }
    int x = sum / N;
    for (int i = 0; i < N; ++i)
        if (arr[i] > x) ans++;
    cout << ans << '\n';
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

