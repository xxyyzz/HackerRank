#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#define MAXN 103
#define LIMIT 100001

using namespace std;
int gnd[LIMIT];

int mex(vector<int> &v) {
    vector<int> vis(v.size() + 2, false);
    for(auto &elem: v) {
        if(elem < vis.size())
            vis[elem] = true;
    }
    for(int i = 0; i < vis.size(); i++)
        if(!vis[i])
            return i;
    assert(false);
    return -1;
}

void go() {
    gnd[1] = 0;
    for(int i = 2; i < LIMIT; i++) {
        vector<int> temp = {0};
        for(int y = 2; y*y <= i; y++) {
            if(i % y == 0) {
                temp.push_back(y % 2 ? gnd[i/y] : 0);
                temp.push_back((i/y) % 2 ? gnd[y] : 0);
            }
        }
        gnd[i] = mex(temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n, temp;
    go();
    cin >> t;
    while(t--) {
        cin >> n;
        int res = 0;
        while(n--) {
            cin >> temp;
            res ^= gnd[temp];
        }
        cout << 2 - (res != 0) << '\n';
    }
    return 0;
}
