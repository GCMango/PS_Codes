#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct Robot {
    int i;
    int j;
    int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; ++i) cin >> arr[i][j];

    Robot start, fin;
    cin >> start.i >> start.j >> start.n;
    cin >> fin.i >> fin.j >> fin.n;
    start.i--; start.j--; fin.i--; fin.j--;
    switch (start.n) {
        case 1:
            start.n = 2;
            break;
        case 2:
            start.n = 4;
            break;
        case 4:
            start.n = 1
    }
    switch (fin.n) {
        case 1:
            fin.n = 2;
            break;
        case 2:
            fin.n = 4;
            break;
        case 4:
            fin.n = 1
    }

    queue<Robot> que;
    que.push(start);

    return 0;
}
