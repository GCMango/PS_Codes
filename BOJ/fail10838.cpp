#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<p> par(N);
    for (int i = 1; i < N; ++i)
        par[i].x = 0;

    while (K--) {
        int n, a, b, c;
        cin >> n >> a >> b;
        if (n == 1) {
            cin >> c;
            int lca, aa = a;
            vector<bool> check(N, false);
            for (int i = 0; i < 1000; ++i) {
                check[a] = true;
                a = par[a].x;
            }
            for (int i = 0; i < 1000; ++i) {
                if (check[b]) {
                    lca = b;
                    break;
                }
                par[b].y = c;
                b = par[b].x;
            }
            while (aa != lca) {
                par[aa].y = c;
                aa = par[aa].x;
            }
        } 
        else if (n == 2)
            par[a].x = b;
        else {
            int cnt = 1;
            int lca, aa = a;
            vector<int> colors;
            vector<bool> check(N, false);
            for (int i = 0; i < 1000; ++i) {
                check[a] = true;
                a = par[a].x;
            }
            for (int i = 0; i < 1000; ++i) {
                if (check[b]) {
                    lca = b;
                    break;
                }
                colors.push_back(par[b].y);
                b = par[b].x;
            }
            while (aa != lca) {
                colors.push_back(par[aa].y);
                aa = par[aa].x;
            }

            sort(colors.begin(), colors.end());
            for (int i = 1; i < colors.size(); ++i)
                if (colors[i] != colors[i - 1])
                    cnt++;

            cout << (colors.size() == 0 ? 0 : cnt) << "\n";
        }
    }

    return 0;
}
