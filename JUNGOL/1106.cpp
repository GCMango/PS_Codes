#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
  
typedef long long ll;
typedef pair<int, int> p;
  
int N, M;
p start, fin;
vector<vector<int>> arr;

void solve(p cur, int cnt) {
    arr[cur.y][cur.x] = cnt;
    if (cur.x == fin.x && cur.y == fin.y) return;
    
    vector<p> option{{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};
    for (int i = 0; i < 8; ++i) {
        int yy = cur.y + option[i].y, xx = cur.x + option[i].x;
        if (yy >= 0 && yy < N && xx >= 0 && xx < M && arr[yy][xx] > cnt + 1)
            solve({xx, yy}, cnt + 1);
    }
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  
    cin >> N >> M;
    cin >> start.y >> start.x >> fin.y >> fin.x;
    start.y--; start.x--; fin.y--; fin.x--;
    N = max(start.y, fin.y) + 5, M = max(start.x, fin.x) + 5;
    arr.resize(N, vector<int>(M, 1e9));
    solve(start, 0);
    cout << arr[fin.y][fin.x] << "\n";
  
    return 0;
}
