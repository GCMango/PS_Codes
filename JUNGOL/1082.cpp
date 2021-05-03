#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, mn = 1e9;
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));
    queue<p> fire;
    p start, end;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') fire.push({j, i});
            else if (arr[i][j] == 'S') start = {j, i};
            else if (arr[i][j] == 'D') end = {j, i};
        }
    }

    return 0;
}
