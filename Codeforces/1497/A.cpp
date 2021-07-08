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

void solve() {
    int N; cin >> N;
    vector<int> arr(N), chk(101, 0);
    for (int i = 0; i < N; ++i) { cin >> arr[i]; chk[arr[i]]++; }
    sort(all(arr)); arr.erase(unique(all(arr)), arr.end());
    for (int i = 0; i < arr.size(); ++i) cout << arr[i] << ' ';
    for (int i = 0; i <= 100; ++i)
        for (int j = 2; j <= chk[i]; ++j)
            cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}

