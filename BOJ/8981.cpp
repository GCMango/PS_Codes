#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> input(N);
    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i) cin >> input[i];

    cout << N << "\n";
    int idx = 0;
    arr[0] = input[0];
    for (int i = 1; i < N; ++i) {
        int val = arr[idx];
        idx = (val + idx) % N;
        while (arr[idx] != 0) idx = (idx + 1) % N;
        arr[idx] = input[i];
    }

    for (int i = 0; i < N; ++i) cout << arr[i] << ' ';
    cout << "\n";

    return 0;
}
