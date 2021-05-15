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

int N;
string S;
vector<string> arr;

bool solve(int cur, int ii, int jj, int cnt) {
    if (cur == S.size() - 1) return true;
    bool result = false;
    for (int i = jj + 1; i < arr[ii].size(); ++i) {
        if (arr[ii][i] == S[cur + 1] && (cnt == -1 || i - jj == cnt)) {
            result = result || solve(cur + 1, ii, i, i - jj);
            if (result)
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (arr[i][j] != S[0]) continue;
            if (solve(0, i, j, -1)) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
