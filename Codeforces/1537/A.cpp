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
    int N, arr[50]; cin >> N;
    int pos = 0, neg = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i] > 0) pos += arr[i] - 1;
        else neg += abs(arr[i]) + 1;
    }
    int ans = pos - neg;
    if (ans < 0) cout << "1\n";
    else if (ans > 0) cout << ans << '\n';
    else cout << "0\n";
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
