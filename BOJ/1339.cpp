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

    int N, mx = 0;
    cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        mx = max(mx, (int)arr[i].size());
        cout << mx << '\n';
    }
    for (int i = 0; i < N; ++i) {
        cout << "d\n";
        for (int j = 0; j <= mx - arr[i].size(); ++j)
            arr[i].insert(arr[i].cbegin(), '0');
        cout << arr[i] << '\n';
    }

    return 0;
}
