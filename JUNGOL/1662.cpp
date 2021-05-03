#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n;
vector<p> points;

int solve(vector<p> arr) {
    int mx = 0;
    for (int i = 0; i < points.size(); ++i) {
        int out = 0;
        for (int j = 0; j < arr.size(); ++j)
            if (abs(points[i].x - arr[j].x) == abs(points[i].y - arr[j].y)) { out = 1; break;}
        if (out) continue;
        arr.push_back(points[i]);
        mx = max(mx, solve(arr));
        arr.pop_back();
    }
    return mx == 0 ? arr.size() : mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            if (num) points.push_back({j, i});
        }
    }

    int mx = 0;
    p pp = {-1, -1};
    for (int i = 0; i < points.size(); ++i) {
        if (pp.x == -1 || abs(points[i].x - pp.x) == abs(points[i].y - pp.y)) {
            mx = max(mx, solve({points[i]}));
            pp.x = points[i].x; pp.y = points[i].y;
        }
    }

    cout << mx << "\n";

    return 0;
}
