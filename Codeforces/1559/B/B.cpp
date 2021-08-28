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
        for (auto &i : arr) {
            char c; cin >> c;
            if (c == '?') i = -1;
            else i = c == 'R';
        }
        int pos = N;
        for (int i = 0; i < N; ++i)
            if (arr[i] != -1) { pos = i; break; }
        if (pos == N) pos--, arr[pos] = 0;
        for (int i = pos - 1; i >= 0; --i) arr[i] = !arr[i + 1];
        for (int i = pos + 1; i < N; ++i) {
            if (arr[i] != -1) continue;
            arr[i] = !arr[i - 1];
            if (i + 1 < N && arr[i + 1] != -1) arr[i] = !arr[i + 1];
        }
        for (auto &i : arr) cout << (i ? 'R' : 'B');
        cout << '\n';
    }

    return 0;
}
