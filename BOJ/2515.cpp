#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num, mh;
vector<int> idx;
vector<int> dp;
vector<int> mx;

struct Pic
{
    int hgt;
    int cst;
};

vector<Pic> pc;

bool compare(struct Pic &p, struct Pic &q)
{
    return p.hgt < q.hgt || p.hgt == q.hgt && p.cst > q.cst;
}

int main()
{
    cin >> num >> mh;
    pc.resize(num);
    idx.resize(num);
    dp.resize(num);
    mx.resize(num);
    for (int i = 0; i < num; i++)
        cin >> pc[i].hgt >> pc[i].cst;
    sort(pc.begin(), pc.end(), compare);
    idx[0] = 0;
    for (int i = 1; i < num; i++) {
        for (idx[i] = idx[i - 1] + 1; idx[i] < i + 1; idx[i]++) {
            if (pc[i].hgt - pc[idx[i] - 1].hgt < mh) break;
        }
        idx[i]--;
    }
    dp[0] = mx[0] = pc[0].cst;
    for (int i = 1; i < num; i++) {
        if (idx[i] == 0) {
            dp[i] = pc[i].cst;
        }
        else {
            dp[i] = mx[idx[i] - 1] + pc[i].cst;
        }
        mx[i] = max(mx[i - 1], dp[i]);
    }
    cout << mx[num - 1];

    return 0;
}
