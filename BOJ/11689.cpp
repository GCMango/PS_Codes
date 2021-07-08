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

    ll N, ans;
    cin >> N;
    ans = N;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            while (N % i == 0) N /= i;
            ans -= ans / i;
        }
    }
    if (N > 1) ans -= ans / N;
    cout << ans << '\n';

    return 0;
}
