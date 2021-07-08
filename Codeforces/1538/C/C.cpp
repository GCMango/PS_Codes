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
        ll N, l, r, arr[200000], ans = 0;
        cin >> N >> l >> r;
        for (ll i = 0; i < N; ++i) cin >> arr[i];
        sort(arr, arr + N);
        for (ll i = 0; i < N; ++i) {
            ll lpos = lower_bound(arr, arr + N, l - arr[i]) - arr;
            ll rpos = upper_bound(arr, arr + N, r - arr[i]) - arr - 1;
            if (lpos <= i && rpos <= i) continue;
            lpos = max(lpos, i + 1);
            ans += rpos - lpos + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
