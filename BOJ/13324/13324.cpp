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
    vector<ll> arr(N), ans(N);
    for (auto &i : arr) cin >> i;

    priority_queue<ll> pq;
    pq.push(arr[0]); ans[0] = arr[0];
    for (int i = 1; i < N; ++i) {
        ll tmp = pq.top() + i;
        if (arr[i] <= tmp) {
            pq.pop();
            pq.push(arr[i] - i);
        }
        pq.push(arr[i] - i);
        ans[i] = pq.top();
    }

    for (int i = N - 2; i >= 0; --i) ans[i] = min(ans[i], ans[i + 1]);
    for (int i = 0; i < N; ++i) cout << ans[i] + i << '\n';

    return 0;
}
