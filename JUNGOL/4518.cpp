#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> arr(K);
    for (int i = 0; i < K; ++i) {
        arr[i] = i + 1;
        N -= i + 1;
    }

    int cnt = K - 1;
    while (N-- && N >= 0) {
        arr[cnt]++;
        cnt--;
        if (cnt < 0) cnt = K - 1;
    }
    N++;

    if (N < 0) cout << -1 << "\n";
    else cout << arr[K - 1] - arr[0] << "\n";

    return 0;
}
