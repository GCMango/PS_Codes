#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    int cnt = 0, sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
        if (i > 0 && arr[i] != arr[i - 1]) cnt++;
    }
    if (sum == K || (cnt == 0 && ))
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
