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
    int N;
    vector<int> arr;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n == 1)
            arr.push_back(1);
        else {
            while (!arr.empty()) {
                if (arr[arr.size() - 1] == n - 1) {
                    arr[arr.size() - 1]++;
                    break;
                }
                else
                    arr.pop_back();
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i < arr.size() - 1)
                cout << '.';
        }
        cout << '\n';
    }
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
