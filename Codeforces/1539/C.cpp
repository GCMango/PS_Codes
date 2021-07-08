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

    ll N, K, x; cin >> N >> K >> x;
    ll arr[200000];
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    vector<ll> v;
    for (int i = 0; i < N - 1; ++i)
        if (arr[i + 1] - arr[i] > x)
            v.push_back(arr[i + 1] - arr[i]);
    sort(rall(v));
    while (K > 0 && !v.empty()) {
        ll cmp = v.back() / x - (v.back() % x == 0);
        if (cmp <= K) {
            K -= cmp;
            v.pop_back();
        }
        else break;
    }
    cout << v.size() + 1 << '\n';

    return 0;
}
