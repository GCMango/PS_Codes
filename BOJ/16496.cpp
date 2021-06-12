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

    int N, cnt;
    cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(all(arr), [&](string &a, string &b) { return a + b > b + a; });
    if (arr[0][0] == '0') { cout << "0\n"; return 0; }
    for (int i = 0; i < N; ++i) cout << arr[i];
    cout << '\n';

    return 0;
}
