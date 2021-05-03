#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, max_val = 1;
    cin >> N;
    vector<int> arr(N);
    vector<int> mx(N, 1);

    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[i] && mx[j] + 1 > mx[i]) {
                mx[i] = mx[j] + 1;
                max_val = max(max_val, mx[i]);
            }
        }
    }

    cout << max_val << "\n";

    return 0;
}
