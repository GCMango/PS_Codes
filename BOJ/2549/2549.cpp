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

struct Move {
    int n;
    int i;
    int k;
};

vector<Move> ans = {{}, {}, {}, {}, {}, {}, {}, {}};

void dfs(vector<vector<int>> arr, vector<Move> v, bool rowcol) {
    if (v.size() > 0)
        cout << v.back().n << ' ' << v.back().i << ' ' << v.back().k << '\n';
    int cnt = 1;
    bool same = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (arr[i][j] != cnt) same = 0;
            cnt++;
        }
    }
    if (same || v.size() >= ans.size()) {
        if (v.size() < ans.size()) ans = v;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (v.size() > 0 && !rowcol && v.back().i >= i) continue;
        for (int j = 1; j <= 3; ++j) {
            vector<vector<int>> comp = arr;
            for (int k = 0; k < j; ++k) {
                int tmp = comp[i][3];
                comp[i][3] = comp[i][2];
                comp[i][2] = comp[i][1];
                comp[i][1] = comp[i][0];
                comp[i][0] = tmp;
            }
            v.push_back({1, i, j});
            dfs(comp, v, 0);
            v.pop_back();
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (v.size() > 0 && rowcol && v.back().i >= i) continue;
        for (int j = 1; j <= 3; ++j) {
            vector<vector<int>> comp = arr;
            for (int k = 0; k < j; ++k) {
                int tmp = comp[3][i];
                comp[3][i] = comp[2][i];
                comp[2][i] = comp[1][i];
                comp[1][i] = comp[0][i];
                comp[0][i] = tmp;
            }
            v.push_back({2, i, j});
            dfs(comp, v, 1);
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> arr(4, vector<int>(4));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> arr[i][j];
    dfs(arr, {}, 0);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].n << ' ' << ans[i].i + 1 << ' ' << ans[i].k << '\n';

    return 0;
}
