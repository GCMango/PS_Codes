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

    int N, arr[2000], a[2000], b[2000];
    cin >> N;
    fill(a, a + N, 1), fill(b, b + N, 1);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = N - 2; i >= 0; --i) {
        for (int j = N - 1; j > i; --j) {
            if (arr[j] > arr[i]) a[i] = max(a[i], a[j] + 1);
            else b[i] = max(b[i], b[j] + 1);
        }
    }
    int ans = N ? 1 : 0;
    for (int i = 0; i < N; ++i) ans = max(ans, a[i] + b[i] - 1);
    cout << ans << '\n';

    return 0;
}
