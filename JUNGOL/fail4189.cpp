#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
   
typedef long long ll;
typedef pair<int, int> p;
   
struct Point {
    int x;
    int y;
    int cnt = 0;
};
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int N, M, x, y, xx, yy, result;
    cin >> N >> M >> y >> x >> yy >> xx;
    vector<vector<bool>> arr(N + 1, vector<bool>(M + 1, false));
    vector<p> option{{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};
    queue<Point> que;
    que.push({x, y, 0});
    while (!que.empty()) {
        Point cur = que.front();
        que.pop();
        if (cur.x == xx && cur.y == yy) { result = cur.cnt; break; }
        for (int i = 0; i < 8; ++i) {
            int yyy = cur.y + option[i].y, xxx = cur.x + option[i].x;
            if (yyy >= 1 && yyy <= N && xxx >= 1 && xxx <= M && arr[yyy][xxx] == false) {
                arr[yyy][xxx] = true;
                que.push({xxx, yyy, cur.cnt + 1});
            }
        }
    }
    cout << result << "\n";
   
    return 0;
}
