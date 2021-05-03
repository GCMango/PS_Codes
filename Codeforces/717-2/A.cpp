#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) cin >> arr[i];
        cout << "\n";

        int a = arr.size() / 2 - (arr.size() % 2 == 0), b = a + 1;
        while (K--) {
            if (arr[a] <= arr[b])
                a--, b++;
            if (a < 0 && b >= N && arr[a] <= arr[a + 1] && arr[b] >= arr[b - 1]) break;
            if (a < 0) a = 0;
            if (b >= N) b = N - 1;
            arr[a]--, arr[b]++;
        }

        for (int i = 0; i < N; ++i) cout << arr[i] << ' ';
    }

    return 0;
}
