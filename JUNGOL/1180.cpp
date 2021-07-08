#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<string> res;

void dfs(int n, int sum, int x, string s) {
    if (n == N) {
        sum += x;
        if (sum == 0)
            res.push_back(s);
        return;
    }
    n++;
    dfs(n, sum + x, n, s + '+');
    dfs(n, sum + x, -n, s + '-');
    x *= n / 10 ? 100 : 10;
    dfs(n, sum, x + (x > 0 ? n : -n), s + '.');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    dfs(1, 0, 1, "");
    for (int i = 0; i < min(20, (int)res.size()); ++i) {
        cout << "1 ";
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << ' ' << j + 2 << ' ';
        cout << '\n';
    }
    cout << res.size() << '\n';

    return 0;
}
