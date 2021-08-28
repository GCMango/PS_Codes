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
        int N, K; cin >> N >> K;
        vector<int> arr(N), v;
        for (auto &i : arr) cin >> i;

        v = arr;
        sort(all(v)), v.erase(unique(all(v)), v.end());

        int cnt = 1;
        for (int i = 0; i < N - 1; ++i) {
            int pos = lower_bound(all(v), arr[i]) - v.begin();
            if (arr[i] == arr[i + 1]) continue;
            if (arr[i] > arr[i + 1] || v[pos + 1] != arr[i + 1]) cnt++;
        }

        if (cnt <= K) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

