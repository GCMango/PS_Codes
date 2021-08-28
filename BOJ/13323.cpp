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

    int N; cin >> N;
    vector<ll> arr(N);
    for (auto &i : arr) cin >> i;

    ll ans = 0;
    priority_queue<ll> pq;
    pq.push(arr[0]);
    for (int i = 1; i < N; ++i) {
        ll tmp = pq.top() + i;
        if (arr[i] <= tmp) {
            ans += tmp - arr[i];
            pq.pop();
            pq.push(arr[i] - i);
        }
        pq.push(arr[i] - i);
    }

    cout << ans << '\n';

    return 0;
}
