#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> input(N);
    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i) cin >> input[i];
    vector<int> a = input, b = input;

    for (int i = 1; i < N; ++i) {
        if (a[i] <= a[i - 1]) {
            arr[i] += (a[i - 1] + 1) - a[i];
            a[i] = a[i - 1] + 1;
        }
    }

    int mn = 1e9;
    for (int i = N - 2; i >= 0; --i) {
        if (b[i] <= b[i + 1]) {
            arr[i] += (b[i + 1] + 1) - b[i];
            b[i] = b[i + 1] + 1;
            mn = min(mn, b[i]);
        }
    }

    for (int i = 0; i < N; ++i) mn = min(mn, arr[i]);

    cout << mn << "\n";

    return 0;
}
