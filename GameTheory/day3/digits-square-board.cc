#include <iostream>
#include <vector>
#include <cassert>
#define MAXN 31

using namespace std;

bool is_prime[10] = {false, false, true, true, false, true, false, true, false, false};
int grid[MAXN][MAXN];
int cnt[MAXN][MAXN]; // cnt of non prime integers
int gnd[MAXN][MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN][MAXN];
int n;

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

inline int in_range(int r1, int c1, int r2, int c2) {
    return cnt[r2][c2] + cnt[r1-1][c1-1] - cnt[r1-1][c2] - cnt[r2][c1-1];
}

int go(int r1, int c1, int r2, int c2) {
    if(vis[r1][c1][r2][c2]) return gnd[r1][c1][r2][c2];
    if(in_range(r1, c1, r2, c2) == 0 || (r1 == r2 && c1 == c2)) {
        return gnd[r1][c1][r2][c2] = 0;
    }
    vis[r1][c1][r2][c2] = true;
    vector<int> temp;
    for(int c = c1; c < c2; c++) {
        temp.push_back(go(r1, c1, r2, c) ^ go(r1, c+1, r2, c2));
    }
    for(int r = r1; r < r2; r++) {
        temp.push_back(go(r1, c1, r, c2) ^ go(r+1, c1, r2, c2));
    }
    return gnd[r1][c1][r2][c2] = mex(temp);
}

void reset() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int a = 1; a <= n; a++) {
                for(int b = 1; b <= n; b++) {
                    vis[i][j][a][b] = false;
                    gnd[i][j][a][b] = 0;
                }
            }
        }
    }
}

void pre() {
    reset();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            cnt[i][j] += !is_prime[grid[i][j]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }
        pre();
        cout << (go(1, 1, n, n) == 0 ? "Second" : "First") << '\n';
    }
    return 0;
}
