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

    int N, K, idx = 0;
    cin >> N >> K;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(all(arr), [&](string &a, string &b) { return a + b > b + a; });
    for (int i = 0; i < N; ++i)
        if (arr[i].size() > arr[idx].size())
            idx = i;
    for (int i = 0; i < N; ++i) {
        if (i == idx)
            for (int j = 0; j < K - N; ++j)
                cout << arr[i];
        cout << arr[i];
    }
    cout << '\n';

    return 0;
}

