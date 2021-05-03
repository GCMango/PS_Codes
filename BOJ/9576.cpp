#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &p, pair<int, int> &q) { 
    return p.second < q.second;
}

void solve() {
    int n, m, result = 0;
    cin >> n >> m;
    vector<int> books(n, 1);
    vector<pair<int, int>> arr(m);

    for (int i = 0; i < m; ++i) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < m; ++i) {
        for (int j = arr[i].first - 1; j < arr[i].second; ++j) {
            if (books[j]) {
                books[j] = 0;
                result++;
                break;
            }
        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) solve();
    
    return 0;
}

