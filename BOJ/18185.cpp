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

ll N, B, C, ans = 0, arr[1111111];
ll a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B >> C;
    if (B < C) C = B;
    a = B, b = B + C, c = B + C * 2;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) {
        if (arr[i + 1] > arr[i + 2]) {
            int cnt = min(arr[i], arr[i + 1] - arr[i + 2]);
            ans += cnt * b;
            arr[i] -= cnt, arr[i + 1] -= cnt;
            cnt = min({arr[i], arr[i + 1], arr[i + 2]});
            ans += cnt * c;
            arr[i] -= cnt, arr[i + 1] -= cnt, arr[i + 2] -= cnt;
        }
        else {
            int cnt = min({arr[i], arr[i + 1], arr[i + 2]});
            ans += cnt * c;
            arr[i] -= cnt, arr[i + 1] -= cnt, arr[i + 2] -= cnt;
            cnt = min(arr[i], arr[i + 1]);
            ans += cnt * b;
            arr[i] -= cnt, arr[i + 1] -= cnt;
        }
        ans += arr[i] * a;
    }
    cout << ans << '\n';

    return 0;
}
