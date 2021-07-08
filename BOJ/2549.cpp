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

vector<vector<int>> res;

void dfs(vector<vector<int>> arr, vector<vector<int>> v) {
    bool chk = 0;
    for (int i = 0; i < 4; ++i) {
        int min_pos = min_element(all(arr[i])) - arr[i].begin();
        vector<int> tmp = arr[i]; sort(all(tmp));
        if (arr[i] != tmp) {
            chk = 1;
            int move = 4 - min_pos;
            v.push_back({1, i + 1, move});
            for (int j = 0; j < move; ++j) {
                int t = arr[i][3];
                arr[i][3] = arr[i][2], arr[i][2] = arr[i][1], arr[i][1] = arr[i][0], arr[i][0] = t;
            }
            dfs(arr, v);
        }
        vector<int> comp = {arr[0][i], arr[1][i], arr[2][i], arr[3][i]};
        min_pos = min_element(all(comp)) - comp.begin();
        tmp = comp; sort(all(tmp));
        if (comp != tmp) {
            chk = 1;
            int move = 4 - min_pos;
            v.push_back({2, i + 1, move});
            dfs(arr, v);
        }
    }
    if (!chk) {
        //for (int i = 0; i < v.size(); ++i)
            //cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << '\n';
        //cout << '\n';
        if (res.size() > v.size() || !res.size()) res = v;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> arr(4, vector<int>(4));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> arr[i][j];
    dfs(arr, {});
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}

/*
3
1 2 2
1 3 2
2 3 3
*/

/*
1 2 7 4
3 6 10 8
5 9 11 12
13 14 15 16
*/
