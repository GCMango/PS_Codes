#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, a = -1, b = -1;
    ll mn = 1e18;
    vector<vector<ll>> arr(3);
    cin >> N;
    for (int i = 0; i < N * 2; ++i) {
        ll n;
        char c;
        cin >> n >> c;
        switch (c) {
            case 'R':
                arr[0].push_back(n);
                break;
            case 'G':
                arr[1].push_back(n);
                break;
            case 'B':
                arr[2].push_back(n);
        }
    }
    if (arr[0].size() % 2)
        a = 0;
    if (arr[1].size() % 2) {
        if (a == -1)
            a = 1;
        else
            b = 1;
    }
    if (arr[2].size() % 2)
        b = 2;
    if (a == -1) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < arr[a].size(); ++i) {
        int pos = lower_bound(all(arr[b]), arr[a][i]) - arr[b].begin();
        mn = min(mn, abs(arr[a][i] - arr[b][pos]));
    }
    for (int i = 0; i < arr[b].size(); ++i) {
        int pos = lower_bound(all(arr[a]), arr[b][i]) - arr[a].begin();
        mn = min(mn, abs(arr[a][pos] - arr[b][i]));
    }
    cout << mn << '\n';

    return 0;
}
