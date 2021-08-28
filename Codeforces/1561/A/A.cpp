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
        int N; cin >> N;
        vector<int> arr(N);
        for (auto &i : arr) cin >> i;
        int ans = N;
        for (int i = 0; i < N; ++i) {
            bool chk = 0;
            for (int j = 0; j < N - 1; ++j)
                if (arr[j] > arr[j + 1]) chk = 1;
            if (!chk) { ans = i; break; }
            for (int j = i % 2; j < N - 1; j += 2)
                if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
        cout << ans << '\n';
    }

    return 0;
}
